#pragma once

#include <string>

#include "CVCommon.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVDataModelFactory
{
public:
    virtual ~ICVDataModelFactory() {}
    virtual class ICVDataModel* CreateDataModel(class CVEngine* engine, const std::string& name) = 0;
    virtual void DeleteDataModel(class ICVDataModel* dataModel) = 0;
    virtual const std::string& GetClassName() const = 0;
};

class CVDataModelFactory : public ICVDataModelFactory
{
public:
    CVDataModelFactory() {}
    ~CVDataModelFactory() {}

    class ICVDataModel *CreateDataModel(class CVEngine *engine, const std::string &name) override;
    void DeleteDataModel(class ICVDataModel* dataModel) override;

    virtual const std::string& GetClassName() const override { return "CVDataModelFactory"; }

    CV_DISABLE_COPY_AND_ASSIGN(CVDataModelFactory)
};