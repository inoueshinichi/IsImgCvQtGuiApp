#pragma once

#include "CVCommon.h"


class ICVComponent
{
public:
    virtual ~ICVComponent() {}
    virtual void Update(float deltaTime) = 0;
    virtual class CVNode* GetNode() = 0;
    virtual void SetName(const std::string& name) = 0;
    virtual const std::string& GetName() = 0;
    virtual void OnUpdateTransform() = 0;
    virtual const std::string& GetClassName() const = 0;
};


class CVComponent : public ICVComponent
{
public:
    CVComponent(class CVNode *owner);
    virtual ~CVComponent();

    virtual void Update(float deltaTime) override {}
    virtual void OnUpdateTransform() override {}
    class CVNode *GetNode() override { return mOwner; }
    void SetName(const std::string& name) override { mName = name; }
    const std::string& GetName() override { return mName; }
    virtual const std::string& GetClassName() const override { return "CVComponent"; }

private:
    class CVNode* mOwner;
    std::string mName;

    CV_DISABLE_COPY_AND_ASSIGN(CVComponent)
};