#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void)
{
	int pipefd_parentTOchild[2];
	int pipefd_childTOparent[2];
	int length;
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
			close(pipefd_parentTOchild[1]); //closes write end of parent->child
			close(pipefd_childTOparent[0]); //closes read end of child->parent
			
			read(pipefd_parentTOchild[0], &length, sizeof(int));
			printf("number:%d\n",length);
			return 0;
	
		default: //parent proc
			close(pipefd_parentTOchild[0]); //closes read end of parent->child
			close(pipefd_childTOparent[1]); //closes write end of child->parent

			printf("enter number of elements:");
			scanf("%d", &length);
			write(pipefd_parentTOchild[1], &length, sizeof(int));
			return 0;
	}
}

