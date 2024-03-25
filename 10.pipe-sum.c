#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void)
{
	int pipefd_parentTOchild[2];
	int pipefd_childTOparent[2];
	pid_t cpid;

	if(pipe(pipefd_parentTOchild)==-1 || pipe(pipefd_childTOparent)==-1) {
		printf("was unable to create pipe");
		return -1;
	}

	cpid = fork();
	switch (cpid) {
		case -1:
			printf("error in forking\n");
			return -1;
		case 0: //child proc
			close(pipefd_parentTOchild[1]) //closes write end of parent->child
			close(pipefd_childToParent[0]) //closes read end of child->parent
			return 0;
		default: //parent proc
			close(pipefd_parentTOchild[0]) //closes read end of parent->child
			close(pipefd_childToParent[1]) //closes write end of child->parent
			return 0;
	}
}

