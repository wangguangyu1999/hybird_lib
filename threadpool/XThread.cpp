#include "XTask.h"
#include "XThread.h"

// 先启动线程但是不一定执行任务，有可能里面没添加任务
void XThread::Start()
{
    std::cout << "thread id: " << id << "thread at Start()" << std::endl;
    // 线程一旦被创建就开始执行了
    std::thread th(&XThread::Main, this);
    // 从调用线程分离出本线程
    th.detach();
}

// 线程启动的时候做的事情
void XThread::Main()
{
    std::cout << id << ": thread::Main() begin" << std::endl;
    // 线程启动的时候做的事情
    //.....
    std::cout << id << ": thread::Main() end" << std::endl;
}

// 激活线程 通常是有了任务激活
void XThread::Activate(int arg)
{
    std::cout << "thread id: " << id << "thread at Activate()" << std::endl;
    // 从任务列表中获取任务
    XTask* t = NULL;
    tasks_mutex.lock();
    if (tasks.empty())
    {
        tasks_mutex.unlock();
        return;
    }
    t = tasks.front();
    tasks.pop_front();
    tasks_mutex.unlock();
    t->Init(arg);
}

// 添加任务
void XThread::AddTask(XTask* t)
{
    if (!t) return;
    t->base = this->base;
    tasks_mutex.lock();
    tasks.push_back(t);
    tasks_mutex.unlock();
}