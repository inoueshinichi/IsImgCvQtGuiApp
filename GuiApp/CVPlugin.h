#pragma once

#include <string>

#include "CVDefs.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVPlugin
{
public:
    virtual ~ICVPlugin() {}
    virtual const std::string& GetName() const = 0;
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
    const std::string& GetName() const override;
    virtual bool Initialize() override;
    virtual bool Shutdown() override;
    virtual void About() const override;

private:
    CVPluginManager& mManager;
    std::string mName;
};

typedef CVPlugin *(*CV_CREATEPLUGIN)(CVPluginManager &mgr);

extern "C" CV_DLL_API CVPlugin *CreatePlugin(CVPluginManager &mgr);
