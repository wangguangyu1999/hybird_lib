#pragma once
#include <vector>
#include <iostream>

class XThread;
class XTask;
class XThreadPool
{
public:
    // 单例模式
    static XThreadPool* Get()
    {
        static XThreadPool p;
        return &p;
    }
    // 初始化所有线程
    void Init(int threadCount);
    // 分发任务给线程
    // arg是任务所带的参数，可以自己重新实现弄的更复杂
    void Dispatch(XTask* task, int arg);

private:
    // 线程的数量
    int threadCount = 0;
    // 上一个的线程号码，方便给下一个计数
    int lastThread = -1;
    // 所有线程的向量（线程的数组
    std::vector<XThread*> threads;
    XThreadPool() = default;
};