#include <iostream>
#include <memory>
// #include <thread>
#include <future>

#include <QApplication>

#include "StartUpWindow.h"

#include "CVEngine.h"
#include "CVNode.h"
#include "CVIPComponent.h"
#include "CVIPTask.h"
#include "CVIPScriptTask.h"
#include "CVItem.h"
#include "CVPlugin.h"
#include "CVSingletonManager-Internal.h"
#include "CVPluginManager.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;

    QApplication app(argc, argv);

    StartUpWindow startUpWindow;
    startUpWindow.show();

    CV_DEBUG_LOG("%s in %s, %d at %s\n", __FUNCTION__, "EntryPoint", __LINE__, __FILE__);

    CVEngine engine;
    if (engine.Initialize())
    {
        CVNode* testNode = new CVNode(engine.GetDataModel());
        CVIPComponent* testIPComp = new CVIPComponent(testNode);
        auto testCVItem = std::make_shared<CVItem>();
        std::vector<std::shared_ptr<ICVItem> > srcVec;
        srcVec.emplace_back(testCVItem);
        testIPComp->ImportSrcItems(srcVec);
        CVIPTask* testIPTask_1 = new CVIPTask(testIPComp->GetTaskController());
        CVIPTask *testIPTask_2 = new CVIPScriptTask(testIPComp->GetTaskController());

        // 非同期なスレッドを1つ作成し，適当な計算を担当してもらう
        auto result_async = std::async(std::launch::async, []()
                                       {
            CVPluginManager& pluginManager = *CVSingletonManager::Get<CVPluginManager>();
            CV_DEBUG_LOG("Async Singleton\n"); });

        CVPluginManager &pluginManager = *CVSingletonManager::Get<CVPluginManager>();

        engine.Run();

        testIPComp->ExportDstItems();

        CVSingletonManager::Erase<CVPluginManager>();
    }


    return app.exec();
}