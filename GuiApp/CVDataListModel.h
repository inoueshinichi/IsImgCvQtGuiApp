#pragma once

#include "CVDataModel.h"

#include <vector>
#include <list>

#include "CVCommon.h"


/////////////////////////////////////////////////
// 抽象インターフェースクラスCVDataListModelの詳細実装
/////////////////////////////////////////////////
class CVDataListModel : public ICVDataListModel
{
public:
    CVDataListModel(class CVEngine* engine);
    virtual ~CVDataListModel();

    virtual void AddNode(class CVNode *node) override;
    virtual void RemoveNode(class CVNode *node) override;

    virtual void UpdateNodes(float deltaTime) override;

    std::string GetClassName() const override { return "CVDataListModel"; }

    StructureType GetModelType() const override { return EListModel; }

private:
    class CVEngine* mEngine;
    std::list<class CVNode*> mNodes;
    std::vector<class CVNode *> mPendingNodes;

    CV_DISABLE_COPY_AND_ASSIGN(CVDataListModel)
};