
#include "CVComponent.h"
#include "CVNode.h"

CVComponent::CVComponent(CVNode *owner)
    : mOwner(owner), mName("")
{
    assert(owner != nullptr);
    mOwner->AddComponent(this);
}

CVComponent::~CVComponent()
{
    mOwner->RemoveComponent(this);
}


