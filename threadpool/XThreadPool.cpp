#include "XTask.h"
#include "XThread.h"
#include "XThreadPool.h"

void XThreadPool::Dispatch(XTask* task, int arg)
{
    std::cout << "main thread at XThreadPool::Dispatch()" << std::endl;

    if (!task) return;
    // ��ȡ�µ��߳�id
    int tid = (lastThread + 1) % threadCount;
    lastThread = tid;
    XThread* t = threads[tid];
    // ����߳�
    t->AddTask(task);
    // �����߳�
    t->Activate(arg);
}

void XThreadPool::Init(int threadCount)
{
    std::cout << "main thread at XThreadPool::Init()" << std::endl;

    this->threadCount = threadCount;
    this->lastThread = -1;
    for (int i = 0; i < threadCount; i++)
    {
        std::cout << "Create thread: " << i << std::endl;
        XThread* t = new XThread();
        t->id = i;
        t->Start();
        threads.push_back(t);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}