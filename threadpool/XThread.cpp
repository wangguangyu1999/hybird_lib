#include "XTask.h"
#include "XThread.h"

// �������̵߳��ǲ�һ��ִ�������п�������û�������
void XThread::Start()
{
    std::cout << "thread id: " << id << "thread at Start()" << std::endl;
    // �߳�һ���������Ϳ�ʼִ����
    std::thread th(&XThread::Main, this);
    // �ӵ����̷߳�������߳�
    th.detach();
}

// �߳�������ʱ����������
void XThread::Main()
{
    std::cout << id << ": thread::Main() begin" << std::endl;
    // �߳�������ʱ����������
    //.....
    std::cout << id << ": thread::Main() end" << std::endl;
}

// �����߳� ͨ�����������񼤻�
void XThread::Activate(int arg)
{
    std::cout << "thread id: " << id << "thread at Activate()" << std::endl;
    // �������б��л�ȡ����
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

// �������
void XThread::AddTask(XTask* t)
{
    if (!t) return;
    t->base = this->base;
    tasks_mutex.lock();
    tasks.push_back(t);
    tasks_mutex.unlock();
}