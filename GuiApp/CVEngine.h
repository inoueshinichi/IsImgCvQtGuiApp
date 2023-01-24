#pragma once

#include "CVDataModelFactory.h"

class CVEngine
{
public:
    CVEngine();
    ~CVEngine();

    bool Initialize();
    void Shutdown();
    
    void UpdateNode(int nodeId, int compId);
    void Run();

    void AddNode(class CVObject *node);
    void RemoveNode(class CVObject *node);

private:
    // コピー禁止
    CVEngine(const CVEngine& engine);
    CVEngine& operator=(const CVEngine& engine);

    // CVObjectのためのデータ構造
    class ICVDataModel* mDataModel;

    // CVDataModel用ファクトリ
    ICVDataModelFactory* mDataModelFactory;
};