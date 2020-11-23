#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock;
int counter;

void * thread_fn(void *arg)
{
	pthread_mutex_lock(&lock);
	counter++;

	printf("task %d started\n", counter);
	sleep(1);
	printf("task %d ended\n", counter);
	
	pthread_mutex_unlock(&lock);

	return NULL;
}

int main()
{
	pthread_t tid[2];
	int i = 0;
	int erno;
#if 1
	erno = pthread_mutex_init(&lock, NULL);
	if (erno != 0) {
		printf("pthread_mutex_init() failed: %s\n", strerror(erno));
		return 1;
	}
#endif
	while(i < 2) {
		erno = pthread_create(&tid[i], NULL, thread_fn, NULL);
		if (erno != 0) {
			printf("pthread_create() failed: %s\n", strerror(erno));
			return 1;
		}
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
