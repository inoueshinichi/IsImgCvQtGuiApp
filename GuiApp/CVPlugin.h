#pragma once

#include <string>

#include "CVCommon.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVPlugin
{
public:
    enum PluginType
    {
        EBase = 0,
        EIPScript = 1,
    };

    virtual ~ICVPlugin() {}
    virtual const std::string& GetFilePath() const = 0;
    virtual std::string GetClassName() const = 0;
    virtual bool Initialize() = 0;
    virtual bool Shutdown() = 0;
    virtual void About() const = 0;
};

class CVPluginManager;

class CVPlugin : public ICVPlugin
{
public:
    CVPlugin(CVPluginManager& manager);
    virtual ~CVPlugin();
    const std::string& GetFilePath() const override;
    virtual std::string GetClassName() const override { return "CVPlugin"; }
    virtual bool Initialize() override;
    virtual bool Shutdown() override;
    virtual void About() const override;

private:
    CVPluginManager& mManager;
    std::string mFilePath;
};

typedef CVPlugin *(*CV_CREATE_PLUGIN)(CVPluginManager &mgr);

extern "C" CV_DLL_API CVPlugin *CreatePlugin(CVPluginManager &mgr);
