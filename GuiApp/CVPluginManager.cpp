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

const std::string &CVPluginManager::GetPluginRelPath(CVPlugin *plugin)
{

}

const std::string &CVPluginManager::GetPluginAbsPath(CVPlugin *plugin)
{

}

int CVPluginManager::GetNumPlugins() const
{
    return mPlugins.size();
}

CVPlugin *CVPluginManager::GetPlugin(unsigned int index)
{
    if (index < 0 || index >= mPlugins.size())
        return nullptr;
    return mPlugins[index].mPluginPtr;
}
