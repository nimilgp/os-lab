#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int 
main(int argc, char* argv[])
{
	if(argc != 3){
		printf("[ussage]: revncp SOURCE DEST\n");
		return 0;
	}

	int fd_src = open(argv[1],O_RDONLY);
	if(fd_src == -1){
		printf("failed to  open src file\n");
		return -1; 
	}
	
	int fd_dest = open(argv[2], O_WRONLY|O_CREAT, 00644);
	if(fd_dest == -1){
		printf("failed to  open dest file\n");
		return -1;
	}
	
	char buffer;
	off_t offset = lseek(fd_src, 0, SEEK_END);
	ssize_t len;
	while(lseek(fd_src,offset--,SEEK_SET)+1){
		len = read(fd_src, &buffer, sizeof(buffer));
		write(fd_dest, &buffer, len);
	}
}

