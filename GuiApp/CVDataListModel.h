#pragma once

#include "CVDataModel.h"

#include <vector>

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
    virtual void UpdateNode(int nodeId, int compId) override;
    virtual void Run() override;

private:
    class CVEngine* mEngine;
    std::vector<class CVObject *> mNodes;
    std::vector<class CVObject *> mPendingNodes;
    bool mUpdatingNodes;
};