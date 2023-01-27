#include "CVIPScriptTask.h"


CVIPScriptTask::CVIPScriptTask(CVIPTaskController* owner)
    : CVIPTask(owner)
{

}

CVIPScriptTask::~CVIPScriptTask()
{

}

bool CVIPScriptTask::LoadScript(const std::string& fileName)
{
    return false;
}

bool CVIPScriptTask::ReloadScript()
{
    UnloadScript();
    return LoadScript("TEST");
}

void CVIPScriptTask::UnloadScript()
{

}

void CVIPScriptTask::ExecuteImpl()
{
    // Invoke dll program
}