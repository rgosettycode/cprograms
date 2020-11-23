#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int var = 1;

void *thread_fn(void *arg)
{
	int thread_num = *(int *)arg;

	pthread_mutex_lock(&lock);

	printf("thread %d start\n", thread_num);
	if (var == 1) {
		var = 2;
		printf("th%d start: waiting on condition variable 1\n", thread_num);
		pthread_cond_wait(&cond, &lock);
		printf("th%d end: waiting on condition variable 1\n", thread_num);

	} else {
		printf("th%d start: signaling condition variable 1\n", thread_num);
		pthread_cond_signal(&cond);
		printf("th%d end: signaling condition variable 1\n", thread_num);
	}

	printf("thread %d mutex unlock\n", thread_num);
	pthread_mutex_unlock(&lock);

	printf("thread %d end\n", thread_num);

	return NULL;
}

int main()
{
	pthread_t tid[2];
	int erno, i = 0;
	int ii = 10;

	while (i < 2) {
		erno = pthread_create(&tid[i], NULL, thread_fn, &i);
		sleep(1);
		if (erno != 0) {
			printf("pthread_create() failed: %s\n", strerror(erno));
			return 1;
		}
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
