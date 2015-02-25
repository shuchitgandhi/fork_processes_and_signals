#include<stdio.h>
#include<stdlib.h>
int main(){
	pid_t c1=fork();
	printf("The pid is %d\n",c1);

	pid_t c2=fork();
	printf("The pid is %d\n",c2);

	if(getppid()==c1)
		exit(0);

	if(getpid()==c1)
		exit(0);
	
	pid_t c3=fork();
	printf("The pid is %d\n",c3);

	if(c3==0)
		exit(0);

	if(getpid()==c2){
		c3=fork();
		printf("The pid is %d\n",c3);
	}
}
