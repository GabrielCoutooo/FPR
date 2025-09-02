/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
#include <stdio.h>
#include <string.h>
// Protótipo das funções
int removerOcorrencias(char string[], char n);
int main()
{
    int removidos;
    char string[20], n;
    printf("Digite uma palavra: ");
    gets(string);
    printf("Digite o caracter a ser removido: ");
    scanf("%c", &n);
    removidos = removerOcorrencias(string, n);
    printf("Palavra apos a remocao: %s\n", string);
    printf("O caracter %c foi removido %d vezes.\n", n, removidos);
}
// Implementação das funções
int removerOcorrencias(char string[], char n)
{
    int i, j = 0, cont = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != n)
        {
            string[j++] = string[i];
        }
        else
        {
            cont++;
        }
    }
    string[j] = '\0';
    return cont;
}