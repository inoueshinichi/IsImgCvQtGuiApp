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
    void UpdateEngine();
    void ProcessInput();
    void GenerateOutput();
    bool LoadData();
    void UnloadData();

    bool mIsRunning;

    // CVDataModel用ファクトリ
    ICVDataModelFactory* mDataModelFactory;

    // CVObjectのためのデータ構造
    class ICVDataModel *mDataModel;

    CV_DISABLE_COPY_AND_ASSIGN(CVEngine)
};