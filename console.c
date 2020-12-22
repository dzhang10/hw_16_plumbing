#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {

	mkfifo("toP",0644);
	mkfifo("toC",0644);

	int fd1;
	int fd2;

	fd1 = open("toP",O_WRONLY);
	fd2 = open("toC",O_RDONLY);

	int input;
	int output;

	while(1) {

		printf("First Int: ");
		scanf("%d",&input);
		write(fd1,&input,sizeof(input));
		printf("Second Int: ");
		scanf("%d",&input);
		write(fd1,&input,sizeof(input));


		read(fd2,&output,sizeof(output));
		printf("Response: %d\n",output);
    	}

    return 0;
}

