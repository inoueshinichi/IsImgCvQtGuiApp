#include "CVEngine.h"
#include "CVObject.h"
#include "CVDataModel.h"

CVEngine::CVEngine()
    : mDataModelFactory(nullptr)
    , mDataModel(nullptr)
    , mIsRunning(true)
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