#pragma once

#include "CVPlugin.h"

class CVIPScriptManager;

// IPスクリプト用プラグインクラス
class CVIPScriptPlugin : public CVPlugin
{
public:
    CVIPScriptPlugin(CVIPScriptManager& manager);
    ~CVIPScriptPlugin();
    bool Initialize() override;
    bool Shutdown() override;
    void About() const override;
    std::string GetClassName() const override { return "CVIPScriptPugin"; }
};