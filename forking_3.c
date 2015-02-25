#include<stdio.h>
#include<stdlib.h>

int main(){
	pid_t A,B,C,D,E,F,G;
	A=getpid();
	printf("A is %d %d\n",A,getpgid(getpid()));
	pid_t c1=fork();
	
	if(c1==0){
		C=getpid();
		printf("C is %d %d\n",getpid(),getpgid(getpid()));
	}else
		wait(c1);
	
	pid_t c2=fork();

	if(c2==0){
		if(getppid()==A){
			D=getpid();
			printf("D is %d %d\n",D,getpgid(getpid()));
		}
		else{
			E=getpid();
			printf("E is %d %d\n",E,getpgid(getpid()));
		}
	}else
		wait(c2);
	
	if(getppid()==C)
		exit(0);

	pid_t c3=fork();

	if(c3==0){
		if(getppid()==A){
			B=getpid();
			printf("B is %d %d\n",B,getpgid(getpid()));
		}else if(getppid()==C){
			F=getpid();
			printf("F is %d %d\n",F,getpgid(getpid()));
		}else{
			G=getpid();
			printf("G is %d %d\n",G,getpgid(getpid()));
		}
	}else
		wait(c3);
	
}
