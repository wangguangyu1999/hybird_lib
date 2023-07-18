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
    // �����߳�
    void Start(); 
    // �߳���ں���
    void Main();
    // �̼߳���
    void Activate(int arg); 
    // ������� һ���߳�ͬʱ���������񣬹���һ��event_base�ṹ��
    void AddTask(XTask*); 
    // �̱߳��
    int id = 0;

private:
    // ������������̸߳�����Ҫʵ��
    event_base* base = 0;
    // ��������
    std::list<XTask*> tasks;
    // ����������������ӻ���ɾ������Ҫ���źŽ��л���
    std::mutex tasks_mutex;
};