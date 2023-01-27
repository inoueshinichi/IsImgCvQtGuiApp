#pragma once

#include "CVComponent.h"

#include <vector>
#include <memory>

#include "CVDefs.h"

class ICVItem;

class CVIPComponent : public CVComponent
{
public:
    CVIPComponent(class CVObject* owner);
    virtual ~CVIPComponent();

    void Update(float deltaTime) override;
    void OnUpdateTransform() override {};

    const std::vector<std::shared_ptr<ICVItem> > &GetSrcItems() const { return mSrcItems; }
    void SetSrcItems(const std::vector<std::shared_ptr<ICVItem> > &srcItem) { mSrcItems = srcItem; }

    const std::vector<std::shared_ptr<ICVItem>> &GetDstItems() const { return mDstItems; }
    void SetDstItems(const std::vector<std::shared_ptr<ICVItem> > &dstItem) { mDstItems = dstItem; }

private:
    
    


    class CVIPTaskController* mTaskController;
    std::vector<std::shared_ptr<ICVItem> > mSrcItems; // 参照
    std::vector<std::shared_ptr<ICVItem> > mDstItems; // 値

    CV_DISABLE_COPY_AND_ASSIGN(CVIPComponent)
};