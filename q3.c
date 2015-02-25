#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int b,char* filename[]){
	pid_t c1=fork();
	if(c1==0){
		printf("Child pid %d ppid %d gpid %d\n",getpid(),getppid(),getpgid(getpid()));
		char c[]={"cat -t -b -v "};
		strcat(c,filename[1]);
		char* a[]={"/bin/sh","-c",c,NULL};
		// execv("/bin/sh",a);
		execl("/bin/sh","/bin/sh","-c",c,NULL);
	}else{
		wait(NULL);
		printf("parent pid %d ppid %d gpid %d\n",getpid(),getppid(),getpgid(getpid()));
	}
}
