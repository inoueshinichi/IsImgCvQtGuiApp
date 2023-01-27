#pragma once

#include "CVDataModel.h"

#include <vector>

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

private:
    class CVEngine* mEngine;
    std::vector<class CVObject *> mNodes;
    std::vector<class CVObject *> mPendingNodes;
    bool mUpdatingNodes;

    CV_DISABLE_COPY_AND_ASSIGN(CVDataListModel)
};