#pragma once

#include "CVSingletonManager.h"
#include "CVRtti.h"

template <typename SINGLETON>
SINGLETON *CVSingletonManager::Get()
{
    // 内部リンケージのstatic変数は必ずdll側の*.cppで定義すること.
    // https://qiita.com/Chironian/items/3fb61cffa2a20dbee5c2
    std::mutex &mtx = CVSingletonManager::GetMutex();

    // クリティカルセクション作成
    std::lock_guard<std::mutex> locker(mtx);

    static SINGLETON *instance{nullptr}; // 初回だけnullptrで初期化される
    if (instance)
    {
        return instance;
    }

    CVSingletonManager &self = CVSingletonManager::GetSelf();
    instance = new SINGLETON{};
    CV_SINGLETON_LOG(Create, SINGLETON)

    auto deleter = [&]() -> void
    {
        CV_SINGLETON_LOG(Delete, SINGLETON)
        delete instance;
        instance = nullptr;
    };

    int id = self.mCount;
    self.mSingletons.insert({id, {(uintptr_t)instance, deleter}}); // Register deleter
    self.mAddress2Id.insert({(uintptr_t)instance, id});            // Register ID
    self.mCount += 1;
    return instance;
}

template <typename SINGLETON>
int CVSingletonManager::GetId()
{
    CVSingletonManager &self = CVSingletonManager::GetSelf();
    auto address = (uintptr_t)(Get<SINGLETON>());
    return self.mAddress2Id[address];
}

template <typename SINGLETON>
void CVSingletonManager::Erase()
{
    EraseById(GetId<SINGLETON>());
}