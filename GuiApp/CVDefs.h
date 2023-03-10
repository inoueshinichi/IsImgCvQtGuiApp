#pragma once

// Windows supports
#if defined(_MSC_VER)
// __func__の定義
#define __func__ __FUNCTION__
#endif

// dll/lib
#if defined(_MSC_VER) && !defined(__CUDACC__)
    #if defined(CV_PLUGIN_EXPORTS) || defined(CV_PLUGIN_dbg_EXPORTS)
    #define CV_DLL_API __declspec(dllexport)
#else
    #define CV_DLL_API __declspec(dllimport)
#endif
#else
    #define CV_DLL_API
#endif

// debug log
#if 1
    #include <cstdio>
    #if __cplusplus <= 201703L // <= C++17
        #define CV_DEBUG_LOG(format, ...) std::printf(format, ##__VA_ARGS__)
    #else // >= C++20
        #ifdef _MSC_VER
            #if _MSC_VER >= 1925 // >= Visual Studio 2019 16.5.1
                #define CV_DEBUG_LOG(format, ...) std::printf(format __VA_OPT__(, ) __VA_ARGS__)
            #else // < Visual Studio 2019 16.5.1
                // _MSVC_TRADITIONAL 従来:1, 準拠:0
                #if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL // 従来型プリプロセッサ
                    #define CV_EXPAND(...) __VA_ARGS__
                    #define CV_DEBUG_LOG(format, ...) std::printf(format CV_EXPAND(__VA_ARGS__))
                    #undef CV_EXPAND
                #else // 新型プリプロセッサ
                    #define CV_DEBUG_LOG(format, ...) std::printf(format, ##__VA_ARGS__)
                #endif
            #endif
        #else // GCC or Clang (>= C++20)
            #define IS_DEBUG_LOG(format, ...) std::printf(format __VA_OPT__(, ) __VA_ARGS__)
        #endif
    #endif
#else
    #define IS_DEBUG_LOG(format, ...)
#endif

#define CV_DEBUG_CHECKER(class_this_ptr) \
    CV_DEBUG_LOG("[%p] %s in %s, %d at %s\n", (void *)class_this_ptr, __FUNCTION__, class_this_ptr->GetClassName().c_str(), __LINE__, __FILE__);

// コピーコンストラクタとコピー代入演算子の外部公開を禁止する
#define CV_DISABLE_COPY_AND_ASSIGN(class_name)           \
    class_name(const class_name &) = delete;             \
    class_name &operator=(const class_name &) = delete;


#if (__cplusplus < 201704L)
    #define CV_INVOKE_RESULT_TYPE(Func, Args) typename std::result_of<Func(Args...)>::type
#else
    #define CV_INVOKE_RESULT_TYPE(Func, Args) typename std::invoke_result<Func, Args...>::type
#endif