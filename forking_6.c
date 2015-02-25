#include<stdio.h>
int main(){
	if(fork()==0){
		fork();
		exit(0);
	}else{
		if(fork()==0){
			if(fork()==0)
				exit(0);
			if(fork()==0)
				exit(0);
			exit(0);
		}
		fork();
		exit(0);
	}
}
