#include "CVPluginManager.h"
#include "CVPlugin.h"

CVPluginManager::CVPluginManager()
{

}

bool CVPluginManager::LoadPlugin(const std::string &fileName)
{

}

void CVPluginManager::UnloadPlugin(const std::string &fileName)
{

}

void CVPluginManager::UnloadAll()
{

}

const std::string &CVPluginManager::GetPluginRelPath(ICVPlugin *plugin, const std::string& path)
{

}

const std::string &CVPluginManager::GetPluginAbsPath(ICVPlugin *plugin)
{

}

ICVPlugin *CVPluginManager::GetPlugin(unsigned int index)
{
    if (index < 0 || index >= mPlugins.size())
        return nullptr;
    return mPlugins[index].mPlugin;
}
