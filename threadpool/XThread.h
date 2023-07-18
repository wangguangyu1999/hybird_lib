#pragma once

#include <list>
#include <mutex>
#include <iostream>
class XTask;
struct event_base;

class XThread
{
public:
    XThread() = default;
    ~XThread() = default;
    // 启动线程
    void Start(); 
    // 线程入口函数
    void Main();
    // 线程激活
    void Activate(int arg); 
    // 添加任务 一个线程同时处理多个任务，共用一个event_base结构体
    void AddTask(XTask*); 
    // 线程编号
    int id = 0;

private:
    // 方便管理所有线程根据需要实现
    event_base* base = 0;
    // 任务链表
    std::list<XTask*> tasks;
    // 在任务链表里面添加或者删除任务要用信号进行互斥
    std::mutex tasks_mutex;
};