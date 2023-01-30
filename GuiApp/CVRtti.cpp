#include "CVRtti.h"

CVMonoRtti::CVMonoRtti(const std::string &className)
    : mClassName(className), mMonoBaseRtti(nullptr)
{}

CVMonoRtti::CVMonoRtti(const std::string &className, const CVMonoRtti &baseRtti)
    : mClassName(className), mMonoBaseRtti(&baseRtti)
{}

const std::string &CVMonoRtti::GetClassName() const
{
    return mClassName;
}

bool CVMonoRtti::DerivedFrom(const CVMonoRtti &rtti) const
{
    const CVMonoRtti* compare = this;
    while (compare != nullptr)
    {
        if (compare == &rtti)
        {
            return true;
        }
        compare = compare->mMonoBaseRtti;
    }
    return false;
}