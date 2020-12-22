#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int gcd(int a, int b){

	int r=a%b;

	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}

	return b;

}


int main(){

	int fd1;
	int fd2;

	fd1 = open("toP",O_RDONLY);
	fd2 = open("toC",O_WRONLY);

	int input1;
	int input2;
	int answer;

	while(1){
		read(fd1,&input1,sizeof(input1));
		read(fd1,&input2,sizeof(input2));

		answer=gcd(input1,input2);

		write(fd2,&answer,sizeof(answer));
	}

	return 0;
}
