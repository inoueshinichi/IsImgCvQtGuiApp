#include "CVIPComponent.h"
#include "CVNode.h"
#include "CVIPTaskController.h"
#include "CVItem.h"


CVIPComponent::CVIPComponent(CVNode *owner)
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
    CV_DEBUG_CHECKER(this) 
    // 現在のタスク番号に該当するタスクを実行
    // mTaskController->DoRepresentativeTask();
    mTaskController->DoAllTask();
}