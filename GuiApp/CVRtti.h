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




/////////////////////////////
// C++クラス名のデマングル
/////////////////////////////
#include <typeinfo>
#include <iostream>

#if defined(_MSC_VER)
    #if !defined(_DEBUG) || defined(NDEBUG)
        #define CV_SINGLETON_LOG(message, singleton)
    #else
        #define CV_SINGLETON_LOG(message singleton)               \
            std::cout << "[" << #message << "]: a singleton `" << \
            typeid(singleton).name() << "`" << std::endl;
    #endif
#else
    #if defined(NDEBUG)
        #define CV_SINGLETON_LOG(message, singleton)
    #else
        // UNIX系だとlibstdc++に含まれる.
        // Windowsはvcruntime14X.dllかな...
        #if __has_include(<cxxabi.h>)
            #include <cxxabi.h>
            #define CV_SINGLETON_LOG(message, singleton)                                                     \
            std::string singleton_name;                                                                      \
            const std::type_info &type_id = typeid(singleton); /* RTTI */                                    \
            int stat{-1};                                                                                    \
            char *name = abi::__cxa_demangle(type_id.name(), 0, 0, &stat);                                   \
            if (name != nullptr)                                                                             \
            {                                                                                                \
                if (stat == 0) /* success: stat == 0 */                                                      \
                {                                                                                            \
                    singleton_name = name;                                                                   \
                    std::cout << "[" << #message << "] a singleton `" << singleton_name << "`" << std::endl; \
                    ::free(name);                                                                            \
                }                                                                                            \
            }                                                                                                \
            if (stat != 0)                                                                                   \
            {                                                                                                \
                std::cout << "[" << #message << "] a singleton `" <<                                         \
                    typeid(SINGLETON).name() << "`" << std::endl;                                            \
            }
        #else
            #define CV_SINGLETON_LOG(message, singleton)               \
                std::cout << "[" << #message << "]: a singleton `" << \
                typeid(singleton).name() << "`" << std::endl;
        #endif
    #endif
#endif

