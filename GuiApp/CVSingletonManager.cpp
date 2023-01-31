#include "CVSingletonManager-Internal.h"

// 静的初期化
CVSingletonManager *CVSingletonManager::sSelf = nullptr;

std::mutex &CVSingletonManager::GetMutex()
{
    // 内部リンケージ
    static std::mutex sMtx;
    return sMtx;
}

CVSingletonManager::CVSingletonManager()
{}

CVSingletonManager::~CVSingletonManager()
{}

CVSingletonManager &CVSingletonManager::GetSelf()
{
    if (!sSelf)
    {
        sSelf = new CVSingletonManager{};
    }
    return *sSelf;
}

void CVSingletonManager::Clear()
{
    CVSingletonManager &self = CVSingletonManager::GetSelf();
    for (int i = 0; i < self.mCount; ++i)
    {
        // Singletonインスタンスを破棄
        EraseById(i);
    }

    // clear
    self.mSingletons.clear();
    self.mAddress2Id.clear();
    self.mCount = 0;
}

void CVSingletonManager::EraseById(int id)
{
    CVSingletonManager &self = CVSingletonManager::GetSelf();
    auto iter = self.mSingletons.find(id);
    if (iter == self.mSingletons.end())
    {
        return;
    }

    iter->second.second(); // Invoke deleter
    self.mAddress2Id.erase(iter->second.first);
    self.mSingletons.erase(iter);
}