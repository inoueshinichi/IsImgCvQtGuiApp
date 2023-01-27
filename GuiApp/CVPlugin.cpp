#include "CVPlugin.h"
#include "CVPluginManager.h"

CVPlugin::CVPlugin(CVPluginManager& manager)
    : mManager(manager)
{

}

CVPlugin::~CVPlugin()
{

}

const std::string &CVPlugin::GetName() const
{
    return mName;
}

bool CVPlugin::Initialize()
{
    return false;
}

bool CVPlugin::Shutdown()
{
    return false;
}

void CVPlugin::About() const
{
    
}
