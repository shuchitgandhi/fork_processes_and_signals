#include<stdio.h>
#include<stdlib.h>
int main(){
	pid_t c1=fork();
	printf("The pid is %d\n",c1);
	if(c1==0){
		pid_t c2=fork();
		printf("The pid is %d\n",c2);
		exit(0);
	}else{
		pid_t c3=fork();
		printf("The pid is %d\n",c3);
		if(c3==0){
			pid_t c4=fork();
			printf("The pid is %d\n",c4);
			if(c4==0)
				exit(0);
		}
		fork();
		exit(0);
	}
}
