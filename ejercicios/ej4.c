#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

void* myprint (void* arg){
	char *mensaje= (char *) arg;
	printf("%s\n", mensaje);
}

int main(int argc, char** argv){
pthread_t thread1, thread2, thread3;
char* mensaje="hola, ese";

pthread_create(&thread1, NULL, myprint, mensaje);
pthread_create(&thread2, NULL, myprint, mensaje);
pthread_create(&thread3, NULL, myprint, mensaje);

pthread_join (thread1, NULL);
pthread_join (thread2, NULL);
pthread_join (thread3, NULL);

return 0;
}
