#pragma once

#include <vector>

#include "CVCommon.h"

class CVIPTaskController
{
public:
    CVIPTaskController(class CVIPComponent* owner);
    ~CVIPTaskController();

    void DoRepresentativeTask();
    bool ChangeRepresentativeTask(unsigned int taskID);
    void DoTask(unsigned int taskID);
    void DoAllTask();
    bool EraseTask(unsigned int taskID);
    class CVIPComponent* GetIPCompoennt() const { return mOwner; }

    std::string GetClassName() const { return "CVIPTaskController"; }

private:
    friend class CVIPTask;
    void AddTask(class CVIPTask *task);
    void RemoveTask(class CVIPTask *task);
    std::vector<class CVIPTask *>::iterator GetTaskIDIter(unsigned int taskID);

    class CVIPComponent* mOwner;
    std::vector<class CVIPTask *> mIPTasks; // 画像処理
    unsigned int mNextTaskID;

    CV_DISABLE_COPY_AND_ASSIGN(CVIPTaskController)
};