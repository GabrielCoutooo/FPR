/*Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.*/
#include <stdio.h>
#include <string.h>
// Protótipo das Funções
int caracterIgual(char string[]);
int main()
{
    char string[20];
    int qtd;
    printf("Insira uma string: ");
    gets(string);
    string[strcspn(string, "\n")] = '\0';
    qtd = caracterIgual(string);
    printf("A quantidade de caracteres distintos em \"%s\" eh: %d\n", string, qtd);

    return 0;
}
// Implementação das funções
int caracterIgual(char string[])
{
    int i, j, ehRepetido, cont = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        ehRepetido = 0;
        for (j = 0; j < i; j++)
        {
            if (string[i] == string[j])
            {
                ehRepetido = 1;
                break;
            }
        }
        if (!ehRepetido)
        {
            cont++;
        }
    }
    return cont;
}
