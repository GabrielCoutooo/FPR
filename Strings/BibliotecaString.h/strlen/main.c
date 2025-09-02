#include <stdio.h>
#include <string.h>
// Retorna o número de caracteres da string s, sem contar o '\0'.
int main()
{
    char nome[] = "Gabriel";
    printf("Tamanho: %lu\n", strlen(nome));
    return 0;
}