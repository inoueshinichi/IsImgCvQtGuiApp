#pragma once

#include "CVCommon.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVItem
{
public:
    virtual ~ICVItem() {}
    virtual const std::string& GetClassName() const = 0;
};

class CVItem : public ICVItem
{
public:
    virtual ~CVItem() {} 
    virtual const std::string& GetClassName() const override { return "CVItem"; }

    CV_DISABLE_COPY_AND_ASSIGN(CVItem)
};