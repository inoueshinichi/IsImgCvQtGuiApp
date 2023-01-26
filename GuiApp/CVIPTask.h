#pragma once

#include "CVDefs.h"

class CVIPTask
{
public:
    CVIPTask(class CVIPComponent* owner);
    virtual ~CVIPTask();

    unsigned int GetID() const { return mID; }
    void Execute();
    
protected:
    virtual void ExecuteImpl();

private:
    class CVIPComponent *mOwner;
    unsigned int mID;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPTask)
};