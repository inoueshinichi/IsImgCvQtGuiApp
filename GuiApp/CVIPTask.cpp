#include "CVIPTask.h"
#include "CVIPTaskController.h"
#include "CVItem.h"
#include "CVIPComponent.h"


CVIPTask::CVIPTask(CVIPTaskController *owner)
    : mOwner(owner)
    , mID(0)
{
    assert(owner != nullptr);
    mID = mOwner->mNextTaskID++;
    mOwner->AddTask(this);
}

CVIPTask::~CVIPTask()
{
    mOwner->RemoveTask(this);
}

void CVIPTask::Execute()
{
    if (mSrcItems.size() > 0)
    {
        this->ExecuteImpl();
    }
}

void CVIPTask::Setup()
{
    CV_DEBUG_LOG("[Setup] task's SrcItems in IPTask : %p\n", (void*)this);
    mSrcItems = mOwner->GetIPCompoennt()->GiveSrcItems();
}

void CVIPTask::Attatch()
{
    CV_DEBUG_LOG("[Attach] task's DstItems in IPTask : %p\n", (void*)this);
    mOwner->GetIPCompoennt()->TakeDstItems(mDstItems);
}

void CVIPTask::ExecuteImpl()
{
    // nothing
}