#include "CVNode.h"
#include "CVEngine.h"
#include "CVComponent.h"
#include "CVDataModel.h"

#include <iostream>

CVNode::CVNode(ICVDataModel *dataModel)
    : mDataModel(dataModel)
{
    mDataModel->AddNode(this);
}

CVNode::~CVNode()
{
    mDataModel->RemoveNode(this);
}