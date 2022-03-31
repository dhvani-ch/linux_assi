#define _XOPEN_SOURCE 600
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<bits/types.h>

static pthread_spinlock_t spinlock;

volatile int slock;

void *spinlockthread(void *i)
{
int rc;
int count =0;
printf("\nentered thread %d ,and getting spin lock\n",(int *)i);
rc = pthread_spin_lock(&spinlock);

printf("thread no. %d unlock the spin lock\n",(int *)i);
rc = pthread_spin_unlock(&spinlock);

printf("thread %d complete\n",(int *)i);
return NULL;

}



int main()
{
int rc=0;
pthread_t thread,thread1;

if(pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE)!=0)
	perror("init");

printf("Main get spin lock\n");
rc = pthread_spin_lock(&spinlock);

printf("main create the spin lock thread\n");
rc = pthread_create(&thread, NULL, spinlockthread,(int *)1);

printf("main wait a bit holding the spin lock\n");
sleep(10);

printf("\n\nmain now unlock the spin lock");
rc = pthread_spin_unlock(&spinlock);

if(rc==0)
	printf("\nMain thread successfully unlocked\n");
else
	printf("\nMain thread unsuccessfully unlocked\n");

printf("\nmain,wait for the thread to end\n");
rc = pthread_join(thread, NULL);

printf("\nmain complete\n");
return 0;

}
