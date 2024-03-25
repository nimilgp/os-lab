#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

			int sum=0;
			int temp=0;
			for(int i=0; i<length; i++) {
				read(pipefd_parentTOchild[0], &temp, sizeof(int));
				sum += temp;
			}
			close(pipefd_parentTOchild[0]);
			write(pipefd_childTOparent[1], &sum, sizeof(int));
			close(pipefd_childTOparent[1]);
			return 0;
	
		default: //parent proc
			close(pipefd_parentTOchild[0]); //closes read end of parent->child
			close(pipefd_childTOparent[1]); //closes write end of child->parent

			printf("enter number of elements:");
			scanf("%d", &length);
			write(pipefd_parentTOchild[1], &length, sizeof(int));
			
			int arr[length];
			int ans;
			for(int i=0; i<length; i++) {
				printf("num%d:",i);
				scanf("%d",&arr[i]);
				write(pipefd_parentTOchild[1], &arr[i], sizeof(int));
			}
			printf("\n");
			close(pipefd_parentTOchild[1]);
			read(pipefd_childTOparent[0], &ans, sizeof(int));
			close(pipefd_childTOparent[1]);

			printf("the sum is: %d\n",ans);
			return 0;
	}
}

