#pragma once

#include <string>
#include <vector>
#include <list>

#include "CVCommon.h"

#include "CVObject.h"

class CVNode : public CVObject
{
public:

    CVNode(class ICVDataModel *dataModel);
    virtual ~CVNode();

    virtual std::string GetClassName() const { return "CVNode"; }
    class ICVDataModel* GetDataModel() { return mDataModel; }

private:
    std::string mName;
    class ICVDataModel* mDataModel;

    CV_DISABLE_COPY_AND_ASSIGN(CVNode)
};