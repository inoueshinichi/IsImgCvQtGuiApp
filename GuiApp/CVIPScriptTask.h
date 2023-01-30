#pragma once

#include "CVIPTask.h"

#include "CVCommon.h"

class CVIPScriptTask : public CVIPTask
{
public:
    CVIPScriptTask(class CVIPTaskController* owner);
    virtual ~CVIPScriptTask();

    virtual std::string GetClassName() const override { return "CVIPScriptTask"; }

    bool LoadScript(const std::string& fileName);
    bool ReloadScript();
    void UnloadScript();


protected:
    virtual void ExecuteImpl() override;
private:
    class CVIPScriptPlugin* mScriptPlugin;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPScriptTask)
};