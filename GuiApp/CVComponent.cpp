
#include "CVComponent.h"
#include "CVObject.h"

CVComponent::CVComponent(CVObject *owner)
    : mOwner(owner)
    , mId(0)
    , mName("")
{
    mOwner->AddComponent(this);
    mId = mOwner->GetCompCounter();
}

CVComponent::~CVComponent()
{
    mOwner->RemoveComponent(this);
}

void CVComponent::Run()
{
    std::printf("[RUN] %s component \n", mName.c_str());
}

