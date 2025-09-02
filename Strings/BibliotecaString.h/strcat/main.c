#include <stdio.h>
#include <string.h>
// Adiciona a string origem ao final da string destino.
int main()
{
    char saudacao[50] = "Ola, ";
    char nome[] = "Gabriel";

    strcat(saudacao, nome);

    printf("Frase: %s\n", saudacao);
    return 0;
}