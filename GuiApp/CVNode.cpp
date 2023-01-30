#include "CVNode.h"
#include "CVEngine.h"
#include "CVComponent.h"
#include "CVDataModel.h"

#include <iostream>

CVNode::CVNode(ICVDataModel *dataModel)
    : mState(EActive), mDataModel(dataModel)
{
    mDataModel->AddNode(this);
}

CVNode::~CVNode()
{
    mDataModel->RemoveNode(this);

    while(!mComponents.empty())
    {
        // リストの末尾を参照してdelete. 
        // リスト末尾の削除は, RemoveComponent関数で行う.
        delete mComponents.back();  
    }
}

void CVNode::AddComponent(CVComponent *comp)
{
    mComponents.push_back(comp);
}

void CVNode::RemoveComponent(CVComponent *comp)
{
    auto iter = mComponents.begin();
    for (; iter != mComponents.end(); ++iter)
    {
        if (comp == (*iter))
        {
            break;
        }
    }

    mComponents.erase(iter);
}

void CVNode::Update(float deltaTime)
{
    CV_DEBUG_CHECKER(this);

    if (mState == EActive)
    {
        ComputeWorldTransform();

        UpdateComponents(deltaTime);
        UpdateNode(deltaTime);

        ComputeWorldTransform();
    }
}

void CVNode::UpdateNode(float deltaTime)
{
    // Node固有の処理
}

void CVNode::UpdateComponents(float deltaTime)
{
    for (auto comp : mComponents)
    {
        comp->Update(deltaTime);
    }
}

void CVNode::ComputeWorldTransform()
{

}