#pragma once

#include "CVPluginManager.h"

class CVIPScriptPluginManager : public CVPluginManager
{
public:
    ~CVIPScriptPluginManager();
    std::string GetClassName() const override { return "CVIPScriptPluginManager"; }


protected:
    CVIPScriptPluginManager();

    CV_DISABLE_COPY_AND_ASSIGN(CVIPScriptPluginManager)
};