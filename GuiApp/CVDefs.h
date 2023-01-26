#pragma once

#if defined(_MSC_VER)
// __func__の定義
#define __func__ __FUNCTION__
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


// コピーコンストラクタとコピー代入演算子の外部公開を禁止する
#define CV_DISABLE_COPY_AND_ASSIGN(class_name) \
private:                                       \
    class_name(const class_name &);            \
    class_name &operator=(const class_name &);


#if (__cplusplus < 201704L)
    #define CV_INVOKE_RESULT_TYPE(Func, Args) typename std::result_of<Func(Args...)>::type
#else
    #define CV_INVOKE_RESULT_TYPE(Func, Args) typename std::invoke_result<Func, Args...>::type
#endif