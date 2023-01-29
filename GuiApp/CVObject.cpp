#include "CVObject.h"
#include "CVEngine.h"
#include "CVComponent.h"
#include "CVDataModel.h"

#include <iostream>

CVObject::CVObject(ICVDataModel *dataModel)
    : mState(EActive)
    , mDataModel(dataModel)
{
    mDataModel->AddNode(this);
}

CVObject::~CVObject()
{
    mDataModel->RemoveNode(this);

    while(!mComponents.empty())
    {
        // リストの末尾を参照してdelete. 
        // リスト末尾の削除は, RemoveComponent関数で行う.
        delete mComponents.back();  
    }
}

void CVObject::AddComponent(CVComponent* comp)
{
    mComponents.push_back(comp);
}

void CVObject::RemoveComponent(CVComponent* comp)
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

void CVObject::Update(float deltaTime)
{
    if (mState == EActive)
    {
        ComputeWorldTransform();

        UpdateComponents(deltaTime);
        UpdateObject(deltaTime);

        ComputeWorldTransform();
    }

    

    // mTrialItemのResultデータをmDeployedItemのResultデータに付け替える
    std::cout << "Update CVObject with ID:" << " component!!" << std::endl;
}

void CVObject::UpdateObject(float deltaTime)
{
    // Object固有の処理
}

void CVObject::UpdateComponents(float deltaTime)
{
    for (auto comp : mComponents)
    {
        comp->Update(deltaTime);
    }
}

void CVObject::ComputeWorldTransform()
{

}