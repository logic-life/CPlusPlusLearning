#include <string>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
void *working(void *arg)
{

    printf("我是子线程，线程id为：%d\n", pthread_self());
    for (int i = 0; i < 9; i++)
    {
        printf("child = %d\n", i);
    }
    return NULL;
}

int main()
{
    // 创建一个线程
    // 主线程一直在运行，执行期间创建出了子线程，说明主线程有 CPU 时间片，在这个时间片内将代码执行完毕了，主线程就退出了。
    // 子线程被创建出来之后需要抢cpu时间片, 抢不到就不能运行，如果主线程退出了, 虚拟地址空间就被释放了, 子线程就一并被销毁了。
    // 但是如果某一个子线程退出了, 主线程仍在运行, 虚拟地址空间依旧存在。

    pthread_t tid;
    pthread_create(&tid, NULL, working, NULL);

    printf("子线程创建成功，线程id:%d\n", tid);

    printf("我是主线程，线程id为：%d\n", pthread_self());
    for (int i = 0; i < 9; i++)
    {
        printf("parent i = %d\n", i);
    }
    // 保留虚拟地址空间，让子线程有时间执行
    // sleep(1);
    pthread_exit(NULL);
    return 0;
}