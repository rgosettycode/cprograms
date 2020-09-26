/*
 * If you want to compile using Makefile in this project
 * just give "make shm" will generate executables "shmrd" and "shmwr"
 * by compiling "shmrd.c" and "shmwr.c" 
 *
 * Makefile script is as below
 *
 *	shm: shmrd.c shmwr.c
 * 		gcc -o shmrd shmrd.c
 * 		gcc -o shmwr shmwr.c
 */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
	key_t key;
	int shmid;
	char *str;

	key = ftok("shmfile", 65);
	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	str = (char *) shmat(shmid, (void *)0, 0);

	printf("write data : ");
	scanf("%s", str);

	printf("data written in memory: %s\n", str);

	shmdt(str);

	return 0;
}
