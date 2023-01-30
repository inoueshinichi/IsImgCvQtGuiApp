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

    virtual const std::string& GetClassName() const override { return "CVIPComponent"; }

    // 外部CVObjectと通信
    void ImportSrcItems(const std::vector<ICVItemPtr>& srcItems) { mSrcItems = srcItems; }
    const std::vector<ICVItemPtr>& ExportDstItems() const { return mDstItems; }

    // IPTaskと通信
    const std::vector<ICVItemPtr>& GiveSrcItems() { return mSrcItems; }
    void TakeDstItems(const std::vector<ICVItemPtr>& dstItems) { mDstItems = dstItems; }

private:
    
    class CVIPTaskController* mTaskController;
    std::vector<std::shared_ptr<ICVItem> > mSrcItems; // 参照
    std::vector<std::shared_ptr<ICVItem> > mDstItems; // 値

    CV_DISABLE_COPY_AND_ASSIGN(CVIPComponent)
};