#pragma once

#include <string>
#include <vector>
#include <list>

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

    void Update(int compId);

    void AddComponent(class CVComponent* comp);
    void RemoveComponent(class CVComponent* comp);
    class CVComponent* GetComponent(int compId);
    class CVComponent* GetComponent(const std::string& name);

    class ICVDataModel* GetDataModel() { return mDataModel; }

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    int GetCompCounter();

private:
    State mState;
    class ICVDataModel* mDataModel;
    std::vector<class CVItem*> mSrcItems;
    std::vector<class CVItem*> mDstItems;

    std::list<class CVComponent*> mComponents;
    int mCompCounter;
};