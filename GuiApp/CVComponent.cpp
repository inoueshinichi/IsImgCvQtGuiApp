
#include "CVComponent.h"
#include "CVObject.h"

CVComponent::CVComponent(CVObject *owner)
    : mOwner(owner)
    , mName("")
{
    mOwner->AddComponent(this);
}

CVComponent::~CVComponent()
{
    mOwner->RemoveComponent(this);
}


