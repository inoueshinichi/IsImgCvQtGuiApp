#pragma once

#include "CVDataModelFactory.h"

#include <vector>

#include "CVDefs.h"

class CVEngine
{
public:
    CVEngine();
    ~CVEngine();

    bool Initialize();
    void Shutdown();
    
    
    void Run();
    void RunLoop();

    void AddNode(class CVObject *node);
    void RemoveNode(class CVObject *node);

private:
    void UpdateEngine() {}
    void ProcessInput() {}
    void GenerateOutput() {}
    bool LoadData() {}
    void UnloadData() {}

    // CVObjectのためのデータ構造
    class ICVDataModel* mDataModel;

    // CVDataModel用ファクトリ
    ICVDataModelFactory* mDataModelFactory;

    std::vector<class CVObject*> mNodes;
    std::vector<class CVObject*> mPendingNodes;

    bool mIsRunning;

    CV_DISABLE_COPY_AND_ASSIGN(CVEngine)
};