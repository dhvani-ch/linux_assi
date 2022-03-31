#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

struct my_thread{
int thread_id;
char MSG[100];
};

static void *fun(void *obj)
{

pthread_t thread_ID;
struct my_thread *t1;
t1 = (struct my_thread *)obj;
thread_ID = pthread_self();
printf("\n %d Thread id: %u\n",t1->thread_id, thread_ID);
printf("\n %d Thread Message: %s\n",t1->thread_id, t1->msg);
return (void *) strlen(obj);
}


int main()
{

pthread_t thread2,thread3,thread4,thread_ID;

int rc;

struct my_thread t2,t3,t4;
printf(".....................Main starting....................\n");

t4.thread_id=4;
strcpy(t4.msg,"This is forth thread\n");

t3.thread_id=3;
strcpy(t3.msg,"This is third thread\n");

t2.thread_id=2;
strcpy(t2.msg,"This is second thread\n");
printf("Current process id: %d\n",getpid());
thread_ID = pthread_self();
printf("\nMain thread id: %u\n",thread_ID);

printf(".....................Creating threads using (pthread_create)....................\n");

pthread_create(&thread4, NULL, fun, (void *)&t4);
pthread_create(&thread3, NULL, fun, (void *)&t3);
pthread_create(&thread2, NULL, fun, (void *)&t2);

printf("\nexit\n");

pthread_join(thread2,NULL);
printf("Returned: %d\n",(int *)&t2);
pthread_join(thread2,NULL);
printf("Returned: %d\n",(int *)&t3);
pthread_join(thread2,NULL);
printf("Returned: %d\n",(int *)&t4);

pthread_exit(NULL);

return 0;
}


