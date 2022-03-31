#include<stdio.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
printf("I am init fun\n");
printf("I am initialization code and I will call by thread only once.\n");
}

void *mythread(void *i)
{
printf("\nI am in mythtread: %d\n", (int *)i);
pthread_once(&once, (void*)myinit);
printf("exit from mythread: %d\n", (int *)i);
}

int main()
{
pthread_t thread,thread1,thread2;
pthread_create(&thread,NULL,mythread,(void *)1);

pthread_create(&thread1,NULL,mythread,(void *)2);

pthread_create(&thread2,NULL,mythread,(void *)3);

pthread_join(thread, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("Statement after joining threads\n");
pthread_exit(NULL);

//printf("Statement after joining threads\n");
}
