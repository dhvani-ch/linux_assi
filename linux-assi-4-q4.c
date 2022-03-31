#include<stdio.h>
#include<pthread.h>

void *my(void *i)
{
printf("\n I am in %d thread\n", (int *)i);
}


//To execute this program we have to got to sudo first.....

int main()
{
pthread_t tid;
//pthread_create(&tid,NULL,my,(void *)1);
struct sched_param param;
int priority, policy, ret;
//pthread_create(&tid,NULL,my,(void *)1);

ret = pthread_getschedparam(pthread_self(), &policy, &param);

printf("-----------------main thread-----------------\npolicy: %d \t priority: %d\n", policy, param.sched_priority);

policy = SCHED_FIFO;
param.sched_priority = 10;

pthread_setschedparam(pthread_self(), policy, &param);

pthread_getschedparam(pthread_self(), &policy, &param);
printf("--------------main thread---------------------\npolicy: %d \t priority: %d\n",policy, param.sched_priority);


return 0;
}
