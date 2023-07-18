#pragma once
#include <vector>
#include <iostream>

class XThread;
class XTask;
class XThreadPool
{
public:
    // ����ģʽ
    static XThreadPool* Get()
    {
        static XThreadPool p;
        return &p;
    }
    // ��ʼ�������߳�
    void Init(int threadCount);
    // �ַ�������߳�
    // arg�����������Ĳ����������Լ�����ʵ��Ū�ĸ�����
    void Dispatch(XTask* task, int arg);

private:
    // �̵߳�����
    int threadCount = 0;
    // ��һ�����̺߳��룬�������һ������
    int lastThread = -1;
    // �����̵߳��������̵߳�����
    std::vector<XThread*> threads;
    XThreadPool() = default;
};