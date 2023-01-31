#include "CVIPScriptTask.h"
#include "CVIPScriptPluginManager.h"
#include "CVSingletonManager-Internal.h"

CVIPScriptTask::CVIPScriptTask(CVIPTaskController* owner)
    : CVIPTask(owner)
{

}

CVIPScriptTask::~CVIPScriptTask()
{

}

bool CVIPScriptTask::LoadScript(const std::string &scriptPluginPath) const
{
    bool bRet = CVSingletonManager::Get<CVIPScriptPluginManager>()->LoadPlugin(this, scriptPluginPath);
    return bRet;
}

void CVIPScriptTask::UnloadScript() const
{
    CVSingletonManager::Get<CVIPScriptPluginManager>()->UnloadPlugin(this);
}

const std::string &CVIPScriptTask::GetScriptPluginPath() const
{
    return CVSingletonManager::Get<CVIPScriptPluginManager>()->GetPluginPath(this);
}

void CVIPScriptTask::ExecuteImpl()
{
    // Invoke dll program
    CV_DEBUG_CHECKER(this)
}