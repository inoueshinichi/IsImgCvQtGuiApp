
#include "CVComponent.h"
#include "CVObject.h"

CVComponent::CVComponent(CVObject *owner)
    : mOwner(owner)
    , mName("")
{
    assert(owner != nullptr);
    mOwner->AddComponent(this);
}

CVComponent::~CVComponent()
{
    mOwner->RemoveComponent(this);
}


