#pragma once

#include "CVDataModelFactory.h"

#include <vector>
#include <chrono>

#include "CVCommon.h"

class CVEngine
{
public:
    CVEngine();
    ~CVEngine();

    bool Initialize();
    void Shutdown();

    std::string GetClassName() const { return "CVEngine"; }
    
    void Run();
    void RunLoop();

    void AddNode(class CVNode *node);
    void RemoveNode(class CVNode *node);

    bool GetUpdatingNodes() const { return mIsUpdatingNodes; }
    void SetUpdatingNodes(bool updatingNodes) { mIsUpdatingNodes = updatingNodes; }

    class ICVDataModel* GetDataModel() const { return mDataModel; }


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