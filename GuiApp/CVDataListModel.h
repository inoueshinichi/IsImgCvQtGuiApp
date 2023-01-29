#pragma once

#include "CVDataModel.h"

#include <vector>
#include <list>

#include "CVDefs.h"

/////////////////////////////////////////////////
// 抽象インターフェースクラスCVDataListModelの詳細実装
/////////////////////////////////////////////////
class CVDataListModel : public ICVDataListModel
{
public:
    CVDataListModel(class CVEngine* engine);
    virtual ~CVDataListModel();

    virtual void AddNode(class CVObject* node) override;
    virtual void RemoveNode(class CVObject* node) override;

    virtual void UpdateNodes(float deltaTime) override;

    StructureType GetModelType() const override { return EListModel; }

private:
    class CVEngine* mEngine;
    std::list<class CVObject*> mNodes;
    std::vector<class CVObject *> mPendingNodes;
    

    CV_DISABLE_COPY_AND_ASSIGN(CVDataListModel)
};