#include "CVEngine.h"
#include "CVNode.h"
#include "CVDataModel.h"
#include "CVDataModelFactory.h"

#include <iostream>
#include <thread>

#define CV_TARGET_FPS (int)(1000000.0f / 30)

CVEngine::CVEngine()
    : mIsRunning(true)
    , mIsUpdatingNodes(false)
    , mDataModelFactory(nullptr)
    , mDataModel(nullptr)
{
    // DataModelFactory
    mDataModelFactory = new CVDataModelFactory();
    mDataModel = mDataModelFactory->CreateDataModel(this, "List Model");
}

CVEngine::~CVEngine()
{
    mDataModelFactory->DeleteDataModel(mDataModel);
    delete mDataModelFactory;
}

bool CVEngine::Initialize()
{
    LoadData();

    using std::chrono::high_resolution_clock;
    mTimePoint = high_resolution_clock::now();

    return true;
}

void CVEngine::Shutdown()
{
    UnloadData();
}


void CVEngine::Run()
{
    ProcessInput();
    UpdateEngine();
    GenerateOutput();
}

void CVEngine::RunLoop()
{
    while (mIsRunning)
    {
        Run();
    }
}

void CVEngine::AddNode(CVNode *node)
{
    mDataModel->AddNode(node);
}

void CVEngine::RemoveNode(CVNode *node)
{
    mDataModel->RemoveNode(node);
}

void CVEngine::UpdateEngine()
{
    // ここで各ノードを更新
    // データモデル構造によって更新順序が変わる.
    using namespace std::chrono;
    using std::chrono::high_resolution_clock;


    // デルタタイム(単位[s])
    while (high_resolution_clock::now() < (mTimePoint + microseconds(CV_TARGET_FPS)))
    {
        // busy loop
    }
    
    auto duration = high_resolution_clock::now() - mTimePoint;
    float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    deltaTime /= 1000000.0f; // [s]

    CV_DEBUG_LOG("DeltaTime: %f[s]\n", deltaTime);
    

    // 時刻を更新(次のフレームのため)
    mTimePoint = high_resolution_clock::now();

    // デルタタイムが大きい=1フレーム内の時間に関する物理量変化が大きくなる
    if (deltaTime > 0.05f) // 20FPS
    {
        deltaTime = 0.05f; // 20FPS以上の変化量に制限
    }

   
    

    // Nodeの更新
    mDataModel->UpdateNodes(deltaTime);
}

void CVEngine::ProcessInput()
{

}

void CVEngine::GenerateOutput()
{

}

bool CVEngine::LoadData()
{
    return true;
}

void CVEngine::UnloadData()
{

}