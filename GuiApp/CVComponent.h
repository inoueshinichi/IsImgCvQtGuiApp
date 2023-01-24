#pragma once

#include <string>

class ICVComponent
{
public:
    virtual ~ICVComponent() {}

    virtual void Run() = 0;
    virtual void SetName(const std::string& name) = 0;
    virtual const std::string& GetName() const = 0;
    virtual int GetId() const = 0;
};

#include <vector>

class CVComponent : public ICVComponent
{
public:
    CVComponent(class CVObject* owner);
    virtual ~CVComponent();

    virtual void Run() override;

    int GetId() const override { return mId; }
    void SetName(const std::string& name) override { mName = name; }
    const std::string& GetName() const override { return mName; }

private:
    class CVObject* mOwner;
    int mId;
    std::string mName;
    std::vector<class CVItem*> mTrialSrcItems;
    std::vector<class CVItem*> mTrialDstItems;
    
};