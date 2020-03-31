#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int c;
	static int xflag, yflag, zflag;

	while((c = getopt(argc, argv, "xy:z")) != -1) {
		switch(c) {
			case 'x':
				xflag = 1;
				break;
			case 'y':
				yflag = 1;
				break;
			case 'z':
				zflag = 1;
				break;
			case '?':
				printf("option -%c needs an argument\n", optopt);	
				break;
			default:
				printf("c: %c optopt:%c\n", c, optopt);	
				printf("wrong option\n");

		}
	}

	printf("xflag = %d\nyflag = %d\nzflag = %d\n", xflag, yflag, zflag);

	return 0;
}
