#pragma once

#include "CVDefs.h"

#include <string>
#include <vector>

class CVDatetime
{

};

typedef struct 
{
    class CVPlugin* mPluginPtr;
    void* mHandle; // 32bit:4byte, 64bit:8byte
    std::string mDirName;
    std::string mFileName;
    std::string mExeName;
    size_t mFileSize;
    CVDatetime mDateTime;
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
    virtual const std::string& GetPluginRelPath(unsigned int) = 0;
    virtual const std::string& GetPluginAbsPath(unsigned int) = 0;
    virtual int GetNumPlugins() const = 0;
};

class CVPluginManager
{
public:
    virtual ~CVPluginManager() {}
    bool LoadPlugin(const std::string &fileName);
    void UnloadPlugin(const std::string &fileName);
    void UnloadAll();
    const std::string &GetPluginRelPath(class CVPlugin* plugin);
    const std::string &GetPluginAbsPath(class CVPlugin *plugin);
    size_t GetNumPlugins() const;
    class CVPlugin * GetPlugin(unsigned int index);
protected:
    // 管轄下にあるDLLの全情報
    std::vector<CVPluginInfo> mPlugins;

protected:
    // friend SingletonManager class
    CVPluginManager();

    CV_DISABLE_COPY_AND_ASSIGN(CVPluginManager)
};
