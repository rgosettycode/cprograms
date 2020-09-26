#include <stdio.h>
#include <unistd.h>

int x = 1;

void in_parent()
{
	sleep(2);
	printf("in parent process %d\n", ++x);
}

void in_child()
{
	sleep(3);
	printf("in child process %d\n", --x);
}

int main()
{
	printf("Before fork()\n");
	if (0 == fork()) {
		in_parent();
	} else {
		in_child();
	}

	printf("x addr %p\n", &x);
	printf("main x %d\n", x);
	return 0;
}
