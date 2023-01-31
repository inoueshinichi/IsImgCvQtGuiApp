#pragma once

#include "CVCommon.h"
#include "CVSingletonManager.h"
#include "CVPlugin.h"

#include <string>
#include <vector>


typedef struct 
{
    void *mHandle; // 32bit:4byte, 64bit:8byte
    class ICVPlugin* mPlugin;
    std::string mFilePath;
    size_t mFileSize;
} CVPluginInfo;

//////////////////////////
// 抽象インターフェースクラス
//////////////////////////
class ICVPluginManager
{
public:
    virtual ~ICVPluginManager() {}
    virtual bool LoadPlugin(const std::string& fileName) = 0;
    virtual void UnloadPlugin(const std::string& fileName) = 0;
    virtual void UnloadAll() = 0;
    virtual const std::string& GetPluginRelPath(class ICVPlugin* plugin, const std::string& path) = 0;
    virtual const std::string& GetPluginAbsPath(class ICVPlugin* plugin) = 0;
    virtual unsigned int GetNumPlugins() const = 0;
    virtual std::string GetClassName() const = 0;
    virtual ICVPlugin::PluginType GetPluginType() const = 0;
};


// シングルトン
class CVPluginManager : public ICVPluginManager
{
public:
    virtual ~CVPluginManager() {}
    bool LoadPlugin(const std::string &fileName);
    void UnloadPlugin(const std::string &fileName);
    void UnloadAll();
    const std::string &GetPluginRelPath(class ICVPlugin* plugin, const std::string& path);
    const std::string &GetPluginAbsPath(class ICVPlugin *plugin);
    class ICVPlugin * GetPlugin(unsigned int index);

    virtual ICVPlugin::PluginType GetPluginType() const { return ICVPlugin::EBase; }
    virtual std::string GetClassName() const override { "CVPluginManager"; }
    unsigned int GetNumPlugins() const { return mPlugins.size(); }
    

protected:
    // 管轄下にあるDLLの全情報
    std::vector<CVPluginInfo> mPlugins;

    friend class CVSingletonManager;
    CVPluginManager();

    CV_DISABLE_COPY_AND_ASSIGN(CVPluginManager)
};
