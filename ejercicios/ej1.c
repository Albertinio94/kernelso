#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv){
int fatherpid=getpid();
fork();
if (getpid()==fatherpid){
	fork();
}
printf("Hola, mi pid es %d\n", getpid());

return 0;
}
