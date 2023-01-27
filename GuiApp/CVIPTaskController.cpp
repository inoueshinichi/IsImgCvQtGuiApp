#include "CVIPTaskController.h"
#include "CVIPTask.h"
#include "CVIPComponent.h"

CVIPTaskController::CVIPTaskController(CVIPComponent* owner)
    : mOwner(owner)
    , mNextTaskID(0)
{

}

CVIPTaskController::~CVIPTaskController()
{
    while (!mIPTasks.empty())
    {
        delete mIPTasks.back();
    }
}

void CVIPTaskController::DoRepresentativeTask()
{
    if (mIPTasks.size() > 0)
    {
        // 先頭のタスクがTry&Errorの結果選ばれた代表タスク
        mIPTasks[0]->Setup(mOwner);
        mIPTasks[0]->Execute();
        mIPTasks[0]->Attatch(mOwner);
    }   
}

void CVIPTaskController::DoTask(unsigned int taskID)
{
    auto iter = GetTaskIDIter(taskID);
    if (iter != mIPTasks.end())
    {
        (*iter)->Setup(mOwner);
        (*iter)->Execute();
    }
}

bool CVIPTaskController::ChangeRepresentativeTask(unsigned int taskID)
{
    auto iter = GetTaskIDIter(taskID);
    if (iter != mIPTasks.end())
    {
        // 該当タスクを配列の先頭と交換
        std::iter_swap(mIPTasks.begin(), iter);
        return true;
    }
    return false;
}

bool CVIPTaskController::EraseTask(unsigned int taskID)
{
    auto iter = GetTaskIDIter(taskID);
    if (mIPTasks.size() > 0 && iter != mIPTasks.end())
    {
        // タスクを削除
        delete (*iter);
        return true;
    }
    return false;
}

void CVIPTaskController::AddTask(CVIPTask *task)
{
    mIPTasks.push_back(task);
}

void CVIPTaskController::RemoveTask(CVIPTask *task)
{
    auto iter = std::find(mIPTasks.begin(), mIPTasks.end(), task);
    if (iter != std::end(mIPTasks))
    {
        // Avoid copy with erase()
        std::iter_swap(mIPTasks.begin(), mIPTasks.end() - 1);
        mIPTasks.pop_back();
    }
}

std::vector<CVIPTask *>::iterator CVIPTaskController::GetTaskIDIter(unsigned int taskID)
{
    auto judgeFunc = [&taskID](const auto p) {
        return (p->GetID() == taskID) ? true : false;
    };
    auto iter = std::find_if(mIPTasks.begin(),
                             mIPTasks.end(),
                             judgeFunc);
    return iter;
}


