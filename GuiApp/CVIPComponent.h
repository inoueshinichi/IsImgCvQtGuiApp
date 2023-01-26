#pragma once

#include "CVComponent.h"

#include <vector>
#include <list>

#include "CVDefs.h"

class CVIPComponent : public CVComponent
{
public:
    CVIPComponent(class CVObject* owner);
    virtual ~CVIPComponent();

    void Update(float deltaTime) override;
    void OnUpdateTransform() override {};

    void SetSrcItems(const std::vector<class ICVItem*>& srcItems);
    const std::vector<class ICVItem*>& GetDstItems() const;

    void AddTask(class CVIPTask* task);
    void RemoveTask(class CVIPTask* task);

private:
    unsigned int mCurrentTaskIndex;
    std::vector<class CVIPTask*> mIPTasks; // 画像処理
    std::vector<class ICVItem*> mSrcItems; // 参照
    std::vector<class ICVItem*> mDstItems; // 値

    CV_DISABLE_COPY_AND_ASSIGN(CVIPComponent)
};