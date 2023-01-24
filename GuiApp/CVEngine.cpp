#include "CVEngine.h"
#include "CVObject.h"
#include "CVDataModel.h"

CVEngine::CVEngine()
    : mDataModelFactory(nullptr)
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
    return true;
}

void CVEngine::Shutdown()
{
}

void CVEngine::UpdateNode(int nodeId, int compId)
{
    mDataModel->UpdateNode(nodeId, compId);
}

void CVEngine::Run()
{
    mDataModel->Run();
}

void CVEngine::AddNode(CVObject* node)
{
    mDataModel->AddNode(node);
}

void CVEngine::RemoveNode(CVObject* node)
{
    mDataModel->RemoveNode(node);
}