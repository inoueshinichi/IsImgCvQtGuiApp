#pragma once

#include "CVDataModelFactory.h"

#include <vector>
#include <chrono>

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

    bool GetUpdatingNodes() const { return mIsUpdatingNodes; }
    void SetUpdatingNodes(bool updatingNodes) { mIsUpdatingNodes = updatingNodes; }

private:
    void UpdateEngine();
    void ProcessInput();
    void GenerateOutput();
    bool LoadData();
    void UnloadData();

    bool mIsRunning;
    bool mIsUpdatingNodes;

    // CVDataModel用ファクトリ
    ICVDataModelFactory* mDataModelFactory;

    // CVObjectのためのデータ構造
    class ICVDataModel *mDataModel;

    // Ticks
    std::chrono::high_resolution_clock::time_point mTimePoint;

    CV_DISABLE_COPY_AND_ASSIGN(CVEngine)
};