#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv){
int fatherpid=getpid();
int i=0;

while (getpid()==fatherpid && i<atoi(*(argv+1))){
fork(); 
i++;
}

printf("Hola, mi pid es %d\n", getpid());
return 0;
}
