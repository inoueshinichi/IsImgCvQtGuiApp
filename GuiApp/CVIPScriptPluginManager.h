#pragma once

#include "CVPluginManager.h"

#include <memory>
#include <unordered_map>

class ICVItem;
using ICVItemPtr = std::shared_ptr<ICVItem>;

class CVIPScriptPluginManager : public CVPluginManager
{
public:
    ~CVIPScriptPluginManager() {}
    virtual ICVPlugin::PluginType GetPluginType() const { return ICVPlugin::EIPScript; }
    std::string GetClassName() const override { return "CVIPScriptPluginManager"; }

    const std::string &GetPluginPath(const class CVIPScriptTask *scriptTask) const;

    bool LoadPlugin(const class CVIPScriptTask* scriptTask, const std::string& pluginFilePath);
    void UnloadPlugin(const class CVIPScriptTask* scriptTask);

    const std::vector<ICVItemPtr>& GetIPTaskSrcItems(class CVIPScriptPlugin* scriptPlugin);
    void SetIPTaskDstItems(class CVIPScriptPlugin* scriptPlugin, const std::vector<ICVItemPtr>& pluginItems);

private: 
    friend class CVSingletonManager;
    CVIPScriptPluginManager();

    std::unordered_map<const class CVIPScriptTask*, class CVIPScriptPlugin*> mCouples;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPScriptPluginManager)
};