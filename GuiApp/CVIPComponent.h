#pragma once

#include "CVComponent.h"

#include <vector>
#include <memory>

#include "CVCommon.h"

class ICVItem;

using ICVItemPtr = std::shared_ptr<ICVItem>;

class CVIPComponent : public CVComponent
{
public:
    CVIPComponent(class CVNode* owner);
    virtual ~CVIPComponent();

    void Update(float deltaTime) override;
    void OnUpdateTransform() override {};

    virtual std::string GetClassName() const override { return "CVIPComponent"; }

    class CVIPTaskController* GetTaskController() const { return mTaskController; }

    // 外部CVObjectと通信
    void ImportSrcItems(const std::vector<ICVItemPtr>& srcItems) 
    {
        CV_DEBUG_CHECKER(this)
        mSrcItems = srcItems;
    }
    const std::vector<ICVItemPtr>& ExportDstItems() const 
    {
        CV_DEBUG_CHECKER(this)
        return mDstItems;
    }

    // IPTaskと通信
    const std::vector<ICVItemPtr>& GiveSrcItems() 
    {
        CV_DEBUG_CHECKER(this)
        return mSrcItems;
    }
    void TakeDstItems(const std::vector<ICVItemPtr>& dstItems) 
    {
        CV_DEBUG_CHECKER(this)
        mDstItems = dstItems;
    }

private:
    
    class CVIPTaskController* mTaskController;
    std::vector<ICVItemPtr> mSrcItems;                // 参照
    std::vector<ICVItemPtr> mDstItems;                // 値

    CV_DISABLE_COPY_AND_ASSIGN(CVIPComponent)
};