#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* minhathread(void *argumento){
    // Quando p1/p2 for criado, ao entrar em executando, vai chamar sleep e ficar bloqueado por 1 segundo.
    sleep(1);
    printf("%s\n", (char*) argumento); // pega uma variavel sem tipo e converte para char
    return NULL;
}

int main(int argc, char **argv){
    pthread_t p1, p2; // vamos criar duas threads!
    printf("Main: inicio\n");
    pthread_create(&p1, NULL, minhathread, "A"); // cria uma linha nova de execução (chamada de função minhathread, que vai imprimir A)
    pthread_create(&p2, NULL, minhathread, "B"); // cria outra linha de execução, que vai imprimir B

    // Main espera p1 e p2 acabarem, após isso, imprimirá fim
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Main: fim\n");
    return 0;
}