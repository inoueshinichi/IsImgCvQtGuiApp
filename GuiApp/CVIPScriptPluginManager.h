#pragma once

#include "CVPluginManager.h"

class CVIPScriptPluginManager : public CVPluginManager
{
public:
    ~CVIPScriptPluginManager();


protected:
    CVIPScriptPluginManager();

    CV_DISABLE_COPY_AND_ASSIGN(CVIPScriptPluginManager)
};