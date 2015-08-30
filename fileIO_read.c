#include <syslog.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, fd;
	char *path;
	char *content;
	char *buf;
	mode_t mode_privilege;
	mode_privilege = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;

	content = "here is the content of the file !\n";

	path = "/tmp/file.thy";
	fd = open(path, O_RDONLY, mode_privilege);

/*
	while (read(fd, buf, 100)
	    ) {
		printf("%s", buf);
	}
*/

	//read函数读取文件长度最大只能是7072，不能不是7073，为什么？
	read(fd, buf, 5072);
	printf("%s", buf);

	close(fd);

	return 0;

}
