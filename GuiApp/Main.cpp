#include <iostream>
#include <memory>

#include <QApplication>

#include "StartUpWindow.h"

#include "CVEngine.h"
#include "CVNode.h"
#include "CVIPComponent.h"
#include "CVIPTask.h"
#include "CVItem.h"

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
        CVIPTask *testIPTask_2 = new CVIPTask(testIPComp->GetTaskController());
        CVIPTask *testIPTask_3 = new CVIPTask(testIPComp->GetTaskController());
        CVIPTask *testIPTask_4 = new CVIPTask(testIPComp->GetTaskController());
        CVIPTask *testIPTask_5 = new CVIPTask(testIPComp->GetTaskController());


        engine.Run();

        testIPComp->ExportDstItems();
    }


    return app.exec();
}