#include "CVEngine.h"
#include "CVObject.h"
#include "CVDataModel.h"

CVEngine::CVEngine()
    : mIsRunning(true)
    , mDataModelFactory(nullptr)
    , mDataModel(nullptr)
{
    // DataModelFactory
    mDataModel = mDataModelFactory->CreateDataModel(this, "List Model");
}

CVEngine::~CVEngine()
{
    mDataModelFactory->DeleteDataModel(mDataModel);
}

bool CVEngine::Initialize()
{
    LoadData();
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

void CVEngine::AddNode(CVObject* node)
{
    mDataModel->AddNode(node);
}

void CVEngine::RemoveNode(CVObject* node)
{
    mDataModel->RemoveNode(node);
}

void CVEngine::UpdateEngine()
{
    // ここで各ノードを更新
    // データモデル構造によって更新順序が変わる.
}

void CVEngine::ProcessInput()
{

}

void CVEngine::GenerateOutput()
{

}

bool CVEngine::LoadData()
{

}

void CVEngine::UnloadData()
{

}