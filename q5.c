#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func( int sig )
{
  printf("Oops! -- I got a signal\n");
}

int main()
{
signal(SIGINT, func); //catch terminal interrupts
  for ( int i = 0; i < 20; ++i ) {
    printf("IT 215 lab on signals\n");
sleep ( 1 ); }
return 0; }