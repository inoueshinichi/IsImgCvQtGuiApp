#pragma once

#include "CVCommon.h"

#include <vector>
#include <memory>

class ICVItem;
using ICVItemPtr = std::shared_ptr<ICVItem>;

class CVIPTask
{
public:
    CVIPTask(class CVIPTaskController* owner);
    virtual ~CVIPTask();

    unsigned int GetID() const { return mID; }
    void Execute();
    
    const class CVIPTaskController* GetTaskController() const { return mOwner; }

    void Setup();
    void Attatch();

    virtual std::string GetClassName() const { return "CVIPTask"; }

protected:
    virtual void ExecuteImpl();

private:
    class CVIPTaskController *mOwner;
    unsigned int mID;
    std::vector<ICVItemPtr> mSrcItems;
    std::vector<ICVItemPtr> mDstItems;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPTask)
};