#include "XThreadPool.h"
#include "XThread.h"
#include "myTask.h"

int main()
{
    XThreadPool::Get()->Init(10);
    CMyTask task[10];
    for (int i = 0; i < 10; i++)
    { 
        XThreadPool::Get()->Dispatch(&task[i], i);
    }

    return 0;
}