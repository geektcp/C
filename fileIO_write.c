#include <syslog.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char * argv[]) 
{
	int n,fd;
	char * path;
	char content[10000];
	char * num_str;
	
	mode_t mode_privilege;
	mode_privilege = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ;
	
	

	path = "/tmp/file.thy";
	fd = open(path,O_WRONLY | O_CREAT | O_TRUNC, mode_privilege);

	for(n = 0; n < 10000 ; n++){
	//	sprintf(content, "%d---%s", n, content);
		sprintf(content, "this is the line %d====\n", n);
	//	strcat( content, num_str );
		write(fd, content, strlen(content));
	}
	
	close(fd);
	
	return 0;

}

