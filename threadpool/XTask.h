#pragma once

class XTask
{
public:
    // 一个客户端一个base
    struct event_base* base = 0;
    int thread_id = 0;
    // 初始化任务 具体如何初始化要根据需要而重载
    virtual bool Init(int arg) = 0;
};