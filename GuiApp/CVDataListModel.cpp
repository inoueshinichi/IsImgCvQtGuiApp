#include "CVDataListModel.h"
#include "CVEngine.h"
#include "CVNode.h"

CVDataListModel::CVDataListModel(CVEngine* engine)
    : mEngine(engine)
{

}

CVDataListModel::~CVDataListModel()
{

}

void CVDataListModel::AddNode(CVNode *node)
{
    if (mEngine->GetUpdatingNodes())
    {
        mPendingNodes.push_back(node); // vector
    }
    else
    {
        mNodes.push_back(node); // list
    }
}

void CVDataListModel::RemoveNode(CVNode *node)
{
    // pending nodes (vector)
    auto iter1 = std::find(mPendingNodes.begin(), mPendingNodes.end(), node);
    if (iter1 != mPendingNodes.end())
    {
        std::iter_swap(iter1, mPendingNodes.end() - 1);
        mPendingNodes.pop_back();
    }

    // nodes (list)
    auto iter2 = std::find(mNodes.begin(), mNodes.end(), node);
    if (iter2 != mNodes.end())
    {
        mNodes.erase(iter2); // list
    }
}

void CVDataListModel::UpdateNodes(float deltaTime)
{
    // Nodesの更新
    mEngine->SetUpdatingNodes(true);
    for (auto& node : mNodes)
    {
        node->Update(deltaTime);
    }
    mEngine->SetUpdatingNodes(false);

    // 待機状態にあったNodeを追加
    for (auto& node : mPendingNodes)
    {
        mNodes.emplace_back(node);
    }
    mPendingNodes.clear();

    // 死んだNodeを回収
    std::vector<CVNode *> deadNodes;
    for (auto& node : mNodes)
    {
        if (node->GetState() == CVNode::EDead)
        {
            deadNodes.emplace_back(node);
        }
    }

    // 削除
    for (auto& node : deadNodes)
    {
        delete node;
    }

}
