#pragma once

#include <string>
#include <vector>
#include <list>

#include "CVCommon.h"

class CVNode
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead,
    };

    CVNode(class ICVDataModel *dataModel);
    virtual ~CVNode();

    virtual const std::string& GetClassName() const { return "CVNode"; }

    void AddComponent(class CVComponent* comp);
    void RemoveComponent(class CVComponent* comp);

    void Update(float deltaTime);
    virtual void UpdateNode(float deltaTime);
    void UpdateComponents(float deltaTime);

    class ICVDataModel* GetDataModel() { return mDataModel; }

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    void ComputeWorldTransform();

private:
    State mState;
    std::string mName;
    class ICVDataModel* mDataModel;
    std::vector<class CVComponent*> mComponents;

    CV_DISABLE_COPY_AND_ASSIGN(CVNode)
};