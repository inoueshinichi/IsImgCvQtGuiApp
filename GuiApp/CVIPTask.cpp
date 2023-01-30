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
    CV_DEBUG_CHECKER(this)
    if (mSrcItems.size() > 0)
    {
        this->ExecuteImpl();
    }
}

void CVIPTask::Setup()
{
    CV_DEBUG_CHECKER(this)
    mSrcItems = mOwner->GetIPCompoennt()->GiveSrcItems();
}

void CVIPTask::Attatch()
{
    CV_DEBUG_CHECKER(this)
    mOwner->GetIPCompoennt()->TakeDstItems(mDstItems);
}

void CVIPTask::ExecuteImpl()
{
    // nothing
    CV_DEBUG_CHECKER(this)
}