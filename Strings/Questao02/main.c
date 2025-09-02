/*Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.(ou seja, se ela lê da mesma forma de trás pra frente. )*/
#include <stdio.h>
#include <string.h>
// Prototipo das funções
int palindromo(char string[]);
int main()
{
    char string[20];
    printf("Digite uma string: ");
    gets(string);
    if (palindromo(string) == 1)
    {
        printf("A string %s eh um palindromo!!!\n", string);
    }
    else
    {
        printf("A string %s nao eh um palindromo!!!\n", string);
    }
}
// Implementação das Funções
int palindromo(char string[])
{
    int i, j;
    for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        if (string[i] != string[j])
        {
            return 0;
        }
    }
    return 1;
}