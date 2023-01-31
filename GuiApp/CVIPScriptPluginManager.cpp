#include "CVIPScriptPluginManager.h"
#include "CVIPScriptTask.h"
#include "CVIPScriptPlugin.h"

CVIPScriptPluginManager::CVIPScriptPluginManager()
{

}

const std::string &CVIPScriptPluginManager::GetPluginPath(const CVIPScriptTask *scriptTask) const
{
    return std::string("Testing...");
}

bool CVIPScriptPluginManager::LoadPlugin(const CVIPScriptTask *scriptTask, const std::string &pluginFilePath)
{
    bool bRet = CVPluginManager::LoadPlugin(pluginFilePath);
    if (bRet)
    {

    }
}

void CVIPScriptPluginManager::UnloadPlugin(const CVIPScriptTask *scriptTask)
{

}

const std::vector<ICVItemPtr> &CVIPScriptPluginManager::GetIPTaskSrcItems(CVIPScriptPlugin *scriptPlugin)
{

}

void CVIPScriptPluginManager::SetIPTaskDstItems(class CVIPScriptPlugin *scriptPlugin, 
                                                const std::vector<ICVItemPtr> &pluginItems)
{

}