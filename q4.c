#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void cont(){
	
}
int main(){
	signal(SIGTRAP,cont);
	char command[80];
	while (1) {
		if(fork()==0)
		{
			printf("%% ");
			fgets(command, 80, stdin);
			// char* a[]={"/bin/sh","-c",command,NULL};
			execl("/bin/sh","/bin/sh","-c",command,NULL);
		}
		else
		{
			wait(NULL);
		}
	} 
}
