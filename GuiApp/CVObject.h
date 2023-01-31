#pragma once

#include <string>
#include <vector>
#include <list>

#include "CVCommon.h"

class CVObject
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead,
    };

    CVObject();
    virtual ~CVObject();

    virtual std::string GetClassName() const { return "CVObject"; }

    void AddComponent(class CVComponent* comp);
    void RemoveComponent(class CVComponent* comp);

    void Update(float deltaTime);
    virtual void UpdateSelf(float deltaTime);
    void UpdateComponents(float deltaTime);

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    void ComputeWorldTransform();

private:
    State mState;
    std::string mName;
    std::vector<class CVComponent*> mComponents;

    CV_DISABLE_COPY_AND_ASSIGN(CVObject)
};