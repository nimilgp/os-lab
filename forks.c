#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void)
{
	pid_t cpid;
	cpid = fork();
	switch (cpid) {
		case -1:
			printf("error in forking\n");
			return -1;
		case 0:
			printf("child pid: %d\n", (int)getpid());
			return 0;
		default:
			printf("parent pid: %d\n", (int)getpid());
			return 0;
	}
}

