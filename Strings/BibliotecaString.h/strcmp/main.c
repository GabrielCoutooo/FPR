#include <stdio.h>
#include <string.h>
/*
Compara s1 com s2:

Retorna 0 se forem iguais;

Retorna valor < 0 se s1 < s2;

Retorna valor > 0 se s1 > s2;
*/
int main()
{
    char a[] = "casa";
    char b[] = "carro";

    int resultado = strcmp(a, b);

    if (resultado == 0)
        printf("As strings são iguais.\n");
    else if (resultado < 0)
        printf("A string a vem antes da string b.\n");
    else
        printf("A string a vem depois da string b.\n");

    return 0;
}