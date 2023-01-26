#include "CVIPTask.h"
#include "CVIPComponent.h"

CVIPTask::CVIPTask(CVIPComponent* owner)
    : mOwner(owner)
    , mID(0)
{
    mOwner->AddTask(this);
}

CVIPTask::~CVIPTask()
{
    mOwner->RemoveTask(this);
}

void CVIPTask::Execute()
{
    this->ExecuteImpl();
}

void CVIPTask::ExecuteImpl()
{
    // nothing
}