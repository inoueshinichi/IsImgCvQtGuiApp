#pragma once

#include <string>

#include "CVDefs.h"

////////////////////////////
// 単一継承のみ対応のRTTIクラス
////////////////////////////
class CVMonoRtti
{
public:
    CVMonoRtti(const std::string &className);
    CVMonoRtti(const std::string &className, const CVMonoRtti &baseRtti);

    const std::string& GetClassName() const;
    bool operator==(const CVMonoRtti &rtti) { return (this == &rtti); } // アドレス比較
    bool DerivedFrom(const CVMonoRtti &rtti) const;

private:
    std::string mClassName;
    const CVMonoRtti *mMonoBaseRtti;

    CV_DISABLE_COPY_AND_ASSIGN(CVMonoRtti)
};

////////////////
// Headerに定義
////////////////
#define CV_MONO_RTTI_DECL                   \
    public:                                 \
        static const CVMonoRtti sMonoRtti;  \
        const CVMonoRtti& GetRtti()         \
        {                                   \
            return sMonoRtti;               \
        }

////////////////
// Sourceに定義
////////////////
// Root用
#define CV_MONO_RTTI_IMPL_NOPARENT(class_name)           \
    const CVMonoRtti class_name::sMonoRtti(#class_name);

// Rootの子孫用
#define CV_MONO_RTTI_IMPL(class_name, base_name)                                \
    const CVMonoRtti class_name::sMonoRtti(#class_name, base_name::sMonoRtti);