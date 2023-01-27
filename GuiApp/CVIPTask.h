#pragma once

#include "CVDefs.h"

#include <vector>
#include <memory>

class ICVItem;

class CVIPTask
{
public:
    CVIPTask(class CVIPTaskController* owner);
    virtual ~CVIPTask();

    unsigned int GetID() const { return mID; }
    void Execute();
    const class CVIPTaskController* GetTaskController() const { return mOwner; }

    void Setup(class CVIPComponent* comp);
    void Attatch(class CVIPComponent* comp);
    
protected:
    virtual void ExecuteImpl();

private:
    class CVIPTaskController *mOwner;
    unsigned int mID;
    std::vector<std::shared_ptr<ICVItem> > mSrcItems;
    std::vector<std::shared_ptr<ICVItem> > mDstItems;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPTask)
};