#pragma once

#include "CVDefs.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVItem
{
public:
    virtual ~ICVItem() {}
};

class CVItem : public ICVItem
{
public:
    virtual ~CVItem() {} 

    CV_DISABLE_COPY_AND_ASSIGN(CVItem)
};