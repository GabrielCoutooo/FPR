#include <stdio.h>
#include <string.h>

// Copia o conteúdo de origem para destino, incluindo o caractere '\0'.
int main()
{
    char origem[] = "C eh legal!";
    char destino[20];

    strcpy(destino, origem);

    printf("Destino: %s\n", destino);
    return 0;
}
