#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int 
main(int argc, char* argv[])
{
	if(argc == 1){
		printf("[ussage]: ncp SOURCE DEST\n");
		return 0;
	}

	int fd_src = open(argv[1],O_RDONLY);
	if(fd_src == -1){
		printf("failed to  open src file\n");
		return -1; 
	}
	/*
	int fd_dest = open(argv[2],O_WRONLY);
	if(fd_dest == -1){
		printf("failed to  open dest file\n");
		return -1;
	}*/
	
	char buffer[10];
	while(read(fd_src, buffer, sizeof(buffer))){
		printf("%s",buffer);
	}
}

