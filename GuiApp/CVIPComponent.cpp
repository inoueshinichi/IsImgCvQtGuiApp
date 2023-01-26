#include "CVIPComponent.h"
#include "CVObject.h"
#include "CVIPTask.h"
#include "CVItem.h"


CVIPComponent::CVIPComponent(CVObject* owner)
    : CVComponent(owner)
{

}

CVIPComponent::~CVIPComponent()
{

}

void CVIPComponent::Update(float deltaTime)
{
    // 現在のタスク番号に該当するタスクを実行
    mIPTasks.at(mCurrentTaskIndex)->Execute();
}

void CVIPComponent::SetSrcItems(const std::vector<ICVItem*>& srcItems)
{
    mSrcItems = srcItems; // copy
}

const std::vector<ICVItem *> &CVIPComponent::GetDstItems() const
{
    return mDstItems;
}

void CVIPComponent::AddTask(CVIPTask* task)
{
    mIPTasks.push_back(task);
}

void CVIPComponent::RemoveTask(CVIPTask* task)
{
    auto iter = std::find(mIPTasks.begin(), mIPTasks.end(), task);
    if (iter != std::end(mIPTasks))
    {
        // mIPTasks.erase(iter);
        // Avoid copy with erase()
        std::iter_swap(mIPTasks.begin(), mIPTasks.end() - 1);
        mIPTasks.pop_back();
    }
}