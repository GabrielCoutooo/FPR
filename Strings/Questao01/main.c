/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/
#include <stdio.h>
#include <string.h>
// Prototipo das funções
int meu_strlen(char string[]);
void meu_strcpy(char string1[], char string2[]);
void meu_strcat(char string1[], char string2[], char string3[]);
int meu_strcmp(char string1[], char string2[]);
// Implementação das funcões
int meu_strlen(char string[])
{
    int i = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    return i;
}
void meu_strcpy(char string1[], char string2[])
{
    int i = 0;
    for (i = 0; string2[i] != '\0'; i++)
    {
        string1[i] = string2[i];
    }
    string1[i] = '\0';
}
void meu_strcat(char string1[], char string2[], char string3[])
{
    int i = 0, j = 0;
    for (i = 0; string1[i] != '\0'; i++)
    {
        string3[i] = string1[i];
    }
    for (j = 0; string2[j] != '\0'; j++)
    {
        string3[i + j] = string2[j];
    }
    string3[i + j] = '\0';
}
int meu_strcmp(char string1[], char string2[])
{
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            return string1[i] - string2[i];
        }
        i++;
    }
    return string1[i] - string2[i];
}
int main()
{
    char string1[] = "Hello, World!";
    char string2[] = "Hello, Universe!";
    char string3[100];
    char string4[100];
    char resultado[200];

    // Testando meu_strlen
    printf("Tamanho de string1: %d\n", meu_strlen(string1));
    printf("Tamanho de string2: %d\n", meu_strlen(string2));

    // Testando meu_strcpy
    meu_strcpy(string3, string1);
    printf("string3 apos meu_strcpy(string1): %s\n", string3);

    meu_strcpy(string4, string2);
    printf("string4 apos meu_strcpy(string2): %s\n", string4);

    // Testando meu_strcat
    meu_strcat(string1, string2, resultado);
    printf("Resultado da concatenacao: %s\n", resultado);

    // Testando meu_strcmp
    int cmp = meu_strcmp(string1, string2);
    if (cmp == 0)
    {
        printf("string1 e string2 sao iguais.\n");
    }
    else if (cmp < 0)
    {
        printf("string1 eh menor que string2.\n");
    }
    else
    {
        printf("string1 eh maior que string2.\n");
    }

    return 0;
}
