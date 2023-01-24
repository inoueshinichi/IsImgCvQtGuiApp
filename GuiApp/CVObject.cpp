#include "CVObject.h"
#include "CVEngine.h"
#include "CVComponent.h"
#include "CVDataModel.h"

#include <iostream>

CVObject::CVObject(ICVDataModel *dataModel)
    : mState(EActive)
    , mDataModel(dataModel)
    , mCompCounter(0)
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

int CVObject::GetCompCounter()
{
    int ret = mCompCounter;
    mCompCounter++;
    return ret;
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

void CVObject::Update(int compId)
{
    auto iter = mComponents.begin();
    for (; iter != mComponents.end(); ++iter)
    {
        if (compId == (*iter)->GetId())
        {
            break;
        }
    }

    // mTrialItemのResultデータをmDeployedItemのResultデータに付け替える
    std::cout << "Update CVObject with ID:" << " component!!" << std::endl;
}

CVComponent* CVObject::GetComponent(int compId)
{
    CVComponent* ptr = nullptr;
    for (auto& p : mComponents)
    {
        if (compId == p->GetId())
        {
            ptr = p;
            break;
        }
    }
    
    return ptr;
}


CVComponent* CVObject::GetComponent(const std::string& name)
{
    CVComponent* ptr = nullptr;
    for (auto& p : mComponents)
    {
        if (name == p->GetName())
        {
            ptr = p;
            break;
        }
    }

    return ptr;
}