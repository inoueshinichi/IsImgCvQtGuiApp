cmake_minimum_required(VERSION 3.14.6)

###############################################################################
# Workaround
###############################################################################
# <= CMake3.*.*でAppleClangをコンパイラIDとして認識させる
# Report AppleClang separately from Clang. Their version numbers are different.
# https://cmake.org/cmake/help/v3.0/policy/CMP0025.html
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()

###############################################################################
# Top-level Project Name
###############################################################################
project(IsImgCvQtGuiApp LANGUAGES CXX VERSION 0.1.0)

###############################################################################
# CMake Version
###############################################################################
message(STATUS "========== [START] Version Management ==========")
message(STATUS "CMake Ver: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}.${CMAKE_TWEAK_VERSION}")
message(STATUS "========== [END] Version Management ==========")

###############################################################################
# 全ターゲットに影響を与えるオプション
###############################################################################
message(STATUS "========== [START] C++ All Target Options ==========")

# 独自キャッシュ変数の定義(ON/OFF)
option(BUILD_CPP_PEDANTIC_ERROR "Enable/Disable: --pedantic-errors" OFF)
option(BUILD_CPP_OPENMP "Enable/Disable: OpenMP" ON)
option(BUILD_CPP_TEST "Enable/Disable: Building Test" ON)
option(BUILD_CPP_SHARED_LIBS "Enable/Disable: Shared Libraries" ON)
option(BUILD_CPP_ZERO_CHECK "Enable/Disable: ZERO_CHECK" OFF)
option(BUILD_CPP_MSVC_DEFAULT_LOCALE_UTF8 "Enable/Disable utf-8 default locale" OFF) # ANSI: ShiftJIS -> UTF8 @ Windows OS
option(BUILD_CPP_MSVC_STATIC_VCRUNTIME "Enable/Disable Static MSVC Runtime" OFF) # MD, MDd -> MT, MTd

# 独自キャッシュ変数の定義 (その他)
set(BUILD_CPP_RELEASE_POSTFIX "" CACHE STRING "Release mode library file postfix")
set(BUILD_CPP_DEBUG_POSTFIX "d" CACHE STRING "Debug mode library file postfix")
set(BUILD_CPP_MINSIZEREL_POSTFIX "s" CACHE STRING "MinSizRel mode library file postfix")
set(BUILD_CPP_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "RelWithDebInfo mode library file postfix")

# プラットフォーム
if(WIN32)
    message(STATUS "Platform: Windows ${CMAKE_SYSTEM_VERSION}")
elseif(APPLE)
    message(STATUS "Platform: macOS ${CMAKE_SYSTEM_VERSION}")
elseif(UNIX AND NOT APPLE) # Linux
    message(STATUS "Platform: Linux ${CMAKE_SYSTEM_VERSION}")
else()
    message(FATAL_ERROR "Platform: Not match platforms [Windows, macOS, Linux]. Given platform is ${CMAKE_SYSTEM_NAME}")
endif()

# プロセッサ
message(STATUS "Processor: ${CMAKE_SYSTEM_PROCESSOR}")

# ジェネレータの指定
# https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html
message(STATUS "Generator: $CACHE{CMAKE_GENERATOR}")

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ZERO_CHECKプロジェクトの有無
if(NOT BUILD_CPP_ZERO_CHECK)
    set(CMAKE_SUPPRESS_REGENERATION ON) # CMAKEが管理する全プロジェクトを統括する特殊プロジェクトを生成しない設定
endif()

# コンパイラオプションの初期値
set(MY_CMAKE_CXX_FLAGS "$CACHE{CMAKE_CXX_FLAGS}")
set(MY_CMAKE_CXX_FLAGS_DEBUG "$CACHE{CMAKE_CXX_FLAGS_DEBUG}")
set(MY_CMAKE_CXX_FLAGS_RELEASE "$CACHE{CMAKE_CXX_FLAGS_RELEASE}")
set(MY_CMAKE_CXX_FLAGS_MINSIZEREL "$CACHE{CMAKE_CXX_FLAGS_MINSIZEREL}")
set(MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "$CACHE{CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

# プラットフォーム毎のコンパイラオプション(マルチ・コンフィギュレーションに対応)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    # MSVCバージョン対応表
    # https://qiita.com/yumetodo/items/8c112fca0a8e6b47072d

    ##################################################
    # MSVCのバージョン指定(_MSVC_VERマクロと同じ)
    # https://cmake.org/cmake/help/latest/variable/MSVC_VERSION.html
    ##################################################
    # 1200      = VS  6.0
    # 1300      = VS  7.0
    # 1310      = VS  7.1
    # 1400      = VS  8.0 (v80 toolset)
    # 1500      = VS  9.0 (v90 toolset)
    # 1600      = VS 10.0 (v100 toolset)
    # 1700      = VS 11.0 (v110 toolset)
    # 1800      = VS 12.0 (v120 toolset)
    # 1900      = VS 14.0 (v140 toolset)
    # 1910-1919 = VS 15.0 (v141 toolset) [Warning] C++17に完全対応したのが 1914
    # 1920-1929 = VS 16.0 (v142 toolset)
    # 1930-1939 = VS 17.0 (v143 toolset)
    set(MSVC_CXX_17_FULL_SUPPORT_VERSION 1914)
    if(${MSVC_VERSION} LESS ${MSVC_CXX_17_FULL_SUPPORT_VERSION})
        message(FATAL_ERROR "Not match C++17 full-support MSVC version (>= ${MSVC_CXX_17_FULL_SUPPORT_VERSION}). Given is ${MSVC_VERSION}")
    endif()

    ##################################################
    # MSVC-toolsetのバージョン指定
    # https://cmake.org/cmake/help/latest/variable/MSVC_TOOLSET_VERSION.html#variable:MSVC_TOOLSET_VERSION
    ##################################################
    # 80        = VS 2005 (8.0)
    # 90        = VS 2008 (9.0)
    # 100       = VS 2010 (10.0)
    # 110       = VS 2012 (11.0)
    # 120       = VS 2013 (12.0)
    # 140       = VS 2015 (14.0)
    # 141       = VS 2017 (15.0)
    # 142       = VS 2019 (16.0)
    # 143       = VS 2022 (17.0)
    set(MSVC_TOOLSET_VS2017_15_VERSION 141)
    if(${MSVC_TOOLSET_VERSION} EQUAL ${MSVC_TOOLSET_VS2017_15_VERSION} OR 
       ${MSVC_TOOLSET_VERSION} GREATER ${MSVC_TOOLSET_VS2017_15_VERSION})
        message(FATAL_ERROR "Not match C++17 support MSVC-toolset version (>= ${MSVC_TOOLSET_VS2017_15_VERSION}). Given is ${MSVC_TOOLSET_VERSION}")
    endif()

    ##################################################
    # ビルドオプション
    ##################################################
    string(REGEX REPLACE "/W[0-4]" "" MY_CMAKE_CXX_FLAGS "${MY_CMAKE_CXX_FLAGS}") # デフォルトの`/W[0-4]`を削除
    set(MY_CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /GR /EHsc /W4")
    set(MY_CMAKE_CXX_FLAGS_DEBUG "/Ob0 /Od /MDd /Zi /RTC1") # /MDd or /Od が指定されている場合、#include <windows>内部で_DEBUGマクロが定義される
    set(MY_CMAKE_CXX_FLAGS_RELEASE "/Ob2 /O2 /MD /DNDEBUG") # /DNDEBUGマクロはstatic_assert()で利用する
    set(MY_CMAKE_CXX_FLAGS_MINSIZEREL "/O1 /MD /DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Od /MDd /Zi /RTC1")
    

    ##################################################
    # VC Runtimeの選択 (Static or Shared)
    ##################################################
    if(BUILD_CPP_MSVC_STATIC_VCRUNTIME) 
        string(REPLACE "/MDd" "/MTd" MY_CMAKE_CXX_FLAGS_DEBUG "${MY_CMAKE_CXX_FLAGS_DEBUG}")
        string(REPLACE "/MD" "/MT" MY_CMAKE_CXX_FLAGS_RELEASE "${MY_CMAKE_CXX_FLAGS_RELEASE}")
        string(REPLACE "/MD" "/MT" MY_CMAKE_CXX_FLAGS_MINSIZEREL "${MY_CMAKE_CXX_FLAGS_MINSIZEREL}")
        string(REPLACE "/MDd" "/MTd" MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "${MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
    endif()

    ##################################################
    # OpenMPの有効化/無効化
    ##################################################
    if(BUILD_CPP_OPENMP)
        message(STATUS "Enable OpenMP")
        find_package(OpenMP REQUIRED)
        include_directories(${OpenMP_INCLUDE_DIRS})
        link_directories(${OpenMP_LIBRARY})
        link_libraries(${OpenMP_LIBRARIES})
        string(APPEND MY_CMAKE_CXX_FLAGS " /openmp")
    endif()

    ##################################################
    # ソースコードでUTF-8を使う(MSVC)
    ##################################################
    # add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/utf-8>)
    # set(MY_CMAKE_CXX_FLAGS "${MY_CMAKE_CXX_FLAGS} /utf-8")
    string(APPEND MY_CMAKE_CXX_FLAGS " /utf-8")

    ##################################################
    # C++11以降を利用した場合にマクロ変数__cplusplusの値を利用中のC++バージョンに合わせる(つけないとC++98相当の値になる)
    ##################################################
    # add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>)
    # set(MY_CMAKE_CXX_FLAGS "${MY_CMAKE_CXX_FLAGS}")
    string(APPEND MY_CMAKE_CXX_FLAGS " /Zc:__cplusplus")

    ##################################################
    # オブジェクトファイル(*.obj)のサイズ制限を解放
    ##################################################
    # add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/bigobj>)
    string(APPEND MY_CMAKE_CXX_FLAGS " /bigobj")

    ##################################################
    # プリプロセッサ準拠モードを有効にする
    # https://docs.microsoft.com/ja-jp/cpp/preprocessor/preprocessor-experimental-overview?view=msvc-160
    # https://docs.microsoft.com/ja-jp/cpp/build/reference/zc-preprocessor?view=msvc-160
    ##################################################
    # add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/Zc:preprocessor>)
    string(APPEND MY_CMAKE_CXX_FLAGS " /Zc:preprocessor")

    ##################################################
    # MSVCのC++(ANSI C/ISO C++)標準逸脱のコンパイラ仕様を回避する
    ##################################################
    add_compile_definitions(_CRT_NONSTDC_NO_DEPRECATE) # mkdir, closeなどPOSIX関数でコンパイル時に警告発生（unsafe）を抑制.
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS) # strcpy、sprinitfなどでコンパイル時に警告発生（unsafe）を抑制.
    add_compile_definitions(_USE_MATH_DEFINES) # math.hに定義されている円周率等の物理定数を有効化する.
    

elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    ##################################################
    # ビルドオプション (マルチコンフィギュレーション対応)
    ##################################################
    set(MY_CMAKE_CXX_FLAGS "-O1")
    set(MY_CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(MY_CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

    ##################################################
    # OpenMPの有効化/無効化
    ##################################################
     if(BUILD_CPP_OPENMP)
        message(STATUS "Enable OpenMP")
        find_package(OpenMP REQUIRED)
        include_directories(${OpenMP_INCLUDE_DIRS})
        link_directories(${OpenMP_LIBRARY})
        link_libraries(${OpenMP_LIBRARIES})
        string(APPEND MY_CMAKE_CXX_FLAGS " -fopenmp")
    endif()


elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")

    ##################################################
    # ビルドオプション (マルチコンフィギュレーション対応)
    ##################################################
    set(MY_CMAKE_CXX_FLAGS "-O1")
    set(MY_CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(MY_CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

    # add_compile_options($<$<CXX_COMPILER_ID:AppleClang>:-O1>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:Debug>>:-O0 -g>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:Release>>:-O3 -DNDEBUG>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:MinSizeRel>>:-Os -DNDEBUG>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RelWithDebgInfo>>:-O2 -g>)

    ##################################################
    # OpenMPの有効化/無効化
    ##################################################
     if(BUILD_CPP_OPENMP)
        message(STATUS "Enable OpenMP")
        find_package(OpenMP REQUIRED)
        include_directories(${OpenMP_INCLUDE_DIRS})
        link_directories(${OpenMP_LIBRARY})
        link_libraries(${OpenMP_LIBRARIES})
        # add_compile_options($<$<CXX_COMPILER_ID:AppleClang>:-fopenmp>)
        string(APPEND MY_CMAKE_CXX_FLAGS " -Xpreprocessor -fopenmp")
    endif()

elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    ##################################################
    # ビルドオプション (マルチコンフィギュレーション対応)
    ##################################################
    set(MY_CMAKE_CXX_FLAGS "-O1")
    set(MY_CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(MY_CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
    set(MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

    # add_compile_options($<$<CXX_COMPILER_ID:GNU>:-O1>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Debug>>:-O0 -g>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Release>>:-O3 -DNDEBUG>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:MinSizeRel>>:-Os -DNDEBUG>)
    # add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:RelWithDebgInfo>>:-O2 -g>)

    ##################################################
    # OpenMPの有効化/無効化
    ##################################################
     if(BUILD_CPP_OPENMP)
        message(STATUS "Enable OpenMP")
        find_package(OpenMP REQUIRED)
        include_directories(${OpenMP_INCLUDE_DIRS})
        link_directories(${OpenMP_LIBRARY})
        link_libraries(${OpenMP_LIBRARIES})
        # add_compile_options($<$<CXX_COMPILER_ID:GNU>:-fopenmp>)
        string(APPEND MY_CMAKE_CXX_FLAGS " -fopenmp")
    endif()

else()
    message(FATAL_ERROR "Not match compilers [MSVC, GNU, Clang, AppleClang]. Given is C: ${CMAKE_C_COMPILER_ID}, CXX: ${CMAKE_CXX_COMPILER_ID}")
endif()

if(UNIX OR APPLE)

    # Makefileの詳細情報を出力
    set(CMAKE_VERBOSE_MAKEFILE ON)

    ##################################################
    # 警告の要求/抑制オプション
    ##################################################
    # 警告レベル
    string(APPEND MY_CMAKE_CXX_FLAGS " -Wall")
    # add_compile_options(-Wall)

    # C++標準の準拠に関する可否
    if(BUILD_CPP_PEDANTIC_ERROR)
        # C++標準(厳密なANSI CおよびISO C++)に準拠しない拡張機能を無効化.
        # 禁止されている拡張機能を使うプログラムをはすべて拒絶となる.
        string(APPEND MY_CMAKE_CXX_FLAGS " -pedantic-errors")
        # add_compile_options(-pedantic-errors)
    else()
         # C++標準(厳密なANSI CおよびISO C++)により要求される警告をすべて出力する.
        string(APPEND MY_CMAKE_CXX_FLAGS " -pedantic")
        # add_compile_options(-pedantic)
    endif()
    

    # C++標準の準拠に関する詳細な警告レベルの設定
    # https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings/9862800#9862800
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wextra")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wcast-align")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wcast-qual")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wctor-dtor-privacy")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wdisabled-optimization")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wformat=2 ")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Winit-self")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wlogical-op")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wmissing-declarations")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wmissing-include-dirs")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wnoexcept")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wold-style-cast")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Woverloaded-virtual")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wredundant-decls")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wshadow")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wsign-conversion")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wsign-promo")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wstrict-null-sentinel")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wstrict-overflow=5")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wswitch-default")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wundef")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Werror")
    # string(APPEND MY_CMAKE_CXX_FLAGS " -Wno-unused")

    # add_compile_options(-Wextra)
    # add_compile_options(-Wcast-align)
    # add_compile_options(-Wcast-qual)
    # add_compile_options(-Wctor-dtor-privacy)
    # add_compile_options(-Wdisabled-optimization)
    # add_compile_options(-Wformat=2 )
    # add_compile_options(-Winit-self)
    # add_compile_options(-Wlogical-op)
    # add_compile_options(-Wmissing-declarations)
    # add_compile_options(-Wmissing-include-dirs)
    # add_compile_options(-Wnoexcept)
    # add_compile_options(-Wold-style-cast)
    # add_compile_options(-Woverloaded-virtual)
    # add_compile_options(-Wredundant-decls)
    # add_compile_options(-Wshadow)
    # add_compile_options(-Wsign-conversion)
    # add_compile_options(-Wsign-promo)
    # add_compile_options(-Wstrict-null-sentinel)
    # add_compile_options(-Wstrict-overflow=5)
    # add_compile_options(-Wswitch-default)
    # add_compile_options(-Wundef)
    # add_compile_options(-Werror)
    # add_compile_options(-Wno-unused)
endif()

# コンパイラオプションのキャッシュ変数に代入
set(CMAKE_CXX_FLAGS ${MY_CMAKE_CXX_FLAGS} CACHE STRING "Common compiler options" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG ${MY_CMAKE_CXX_FLAGS_DEBUG} CACHE STRING "Debug mode options" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE ${MY_CMAKE_CXX_FLAGS_RELEASE} CACHE STRING "Release mode options" FORCE)
set(CMAKE_CXX_FLAGS_MINSIZEREL ${MY_CMAKE_CXX_FLAGS_MINSIZEREL} CACHE STRING "MinSizeRel mode options" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO ${MY_CMAKE_CXX_FLAGS_RELWITHDEBINFO} CACHE STRING "RelWithDebInfo mode options" FORCE)


message(STATUS "---------- Compiler options ----------")
message(STATUS ">>>>> C++ version: ${CMAKE_CXX_STANDARD}")
message(STATUS ">>>>> C++ compiler id: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS ">>>>> C++ compiler path: ${CMAKE_CXX_COMPILER}")
message(STATUS ">>>>> C++ compiler `Common` flags: ${CMAKE_CXX_FLAGS}")
message(STATUS ">>>>> C++ compiler `Debug` flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS ">>>>> C++ compiler `Release` flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS ">>>>> C++ compiler `Minsizerel` flags: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
message(STATUS ">>>>> C++ compiler `Relwithdebinfo` flags: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")


message(STATUS "========== [END] C++ All Target Options ==========")


message(STATUS "========== [START] C++ Build Components ==========")

###############################################################################
# C++ Library
###############################################################################
message(STATUS "[START] Check downloading libraries")

message(STATUS ">>>>> Now skipping download IsLibrary...")

message(STATUS "[End] Check downloading of libraries")

###############################################################################
# C++ Core
###############################################################################
if(ON)
    add_subdirectory(GuiApp)
endif()

message(STATUS "========== [END] C++ Build Components ==========")

