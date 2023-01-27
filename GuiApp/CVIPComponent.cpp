#include "CVIPComponent.h"
#include "CVObject.h"
#include "CVIPTaskController.h"
#include "CVItem.h"


CVIPComponent::CVIPComponent(CVObject* owner)
    : CVComponent(owner)
{
    mTaskController = new CVIPTaskController(this);
}

CVIPComponent::~CVIPComponent()
{
    delete mTaskController;
    mTaskController = nullptr;
}

void CVIPComponent::Update(float deltaTime)
{
    // 現在のタスク番号に該当するタスクを実行
    mTaskController->DoRepresentativeTask();
}