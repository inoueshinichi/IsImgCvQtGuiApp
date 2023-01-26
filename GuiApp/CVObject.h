#pragma once

#include <string>
#include <vector>
#include <list>

#include "CVDefs.h"

class CVObject
{
    enum State
    {
        EActive,
        EPaused,
        EDead,
    };

public:
    CVObject(class ICVDataModel* dataModel);
    virtual ~CVObject();

    void AddComponent(class CVComponent* comp);
    void RemoveComponent(class CVComponent* comp);

    void Update(float deltaTime);
    virtual void UpdateObject(float deltaTime);
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

    CV_DISABLE_COPY_AND_ASSIGN(CVObject)
};