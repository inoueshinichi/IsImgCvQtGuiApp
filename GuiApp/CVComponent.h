#pragma once

#include <string>

#include "CVDefs.h"

class ICVComponent
{
public:
    virtual ~ICVComponent() {}
    virtual void Update(float deltaTime) = 0;
    virtual class CVObject* GetObject() = 0;
    virtual void SetName(const std::string& name) = 0;
    virtual const std::string& GetName() = 0;
    virtual void OnUpdateTransform() = 0;
};

class CVComponent : public ICVComponent
{
public:
    CVComponent(class CVObject* owner);
    virtual ~CVComponent();

    virtual void Update(float deltaTime) override {}
    virtual void OnUpdateTransform() override {}
    class CVObject* GetObject() override { return mOwner; }
    void SetName(const std::string& name) override { mName = name; }
    const std::string& GetName() override { return mName; }

private:
    class CVObject* mOwner;
    std::string mName;

    CV_DISABLE_COPY_AND_ASSIGN(CVComponent)
};