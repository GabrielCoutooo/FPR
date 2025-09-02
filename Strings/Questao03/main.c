/*Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de
s e contenha n caracteres.
Observações: se p e/ou n forem inválidos, a
substring será vazia; ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s.*/
#include <stdio.h>
#include <string.h>

void subString(char string[], int p, int n, char subs[]);
int main()
{
    char string[20], subs[20];
    int p, n;
    printf("Digite a string: ");
    gets(string);
    printf("Digite a posicao inicial: ");
    scanf("%d", &p);
    printf("Digite a quantidade de caracteres: ");
    scanf("%d", &n);
    subString(string, p, n, subs);
    printf("\nSubstring: %s\n", subs);
}
void subString(char string[], int p, int n, char subs[])
{
    int i, j, tam;
    tam = strlen(string);
    if ((p < 0) || (p >= tam) || (n < 1) || (n > tam))
    {
        subs[0] = '\0';
    }
    else
    {

        for (i = p, j = 0; (j < n) && (string[i]); i++, j++)
        {
            subs[j] = string[i];
        }
        subs[j] = '\0';
    }
}