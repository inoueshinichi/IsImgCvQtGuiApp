#pragma once

#include "CVIPTask.h"

#include "CVCommon.h"

class CVIPScriptTask : public CVIPTask
{
public:
    CVIPScriptTask(class CVIPTaskController* owner);
    ~CVIPScriptTask();

    virtual std::string GetClassName() const override { return "CVIPScriptTask"; }

    bool LoadScript(const std::string& pluginFilePath) const;
    void UnloadScript() const;

    const std::string &GetScriptPluginPath() const;

protected:
    virtual void ExecuteImpl() override;
private:

    CV_DISABLE_COPY_AND_ASSIGN(CVIPScriptTask)
};