/*Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome. */
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char nome[50];
    char genero;
    int idade;
} TPessoa;

// Protótipo
int estaOrdenado(TPessoa pessoas[], int quant);
void imprimirPessoas(TPessoa pessoas[], int quant);

int main()
{
    int quant = 5;
    TPessoa pessoas[MAX] = {
        {"Gabriel", 'M', 20},
        {"Karina", 'F', 20},
        {"Paulo", 'M', 25},
        {"Deborah", 'F', 30},
        {"Thiago", 'M', 35}};

    imprimirPessoas(pessoas, quant);

    if (estaOrdenado(pessoas, quant))
    {
        printf("\nO vetor esta ordenado.\n");
    }
    else
    {
        printf("\nO vetor NAO esta ordenado.\n");
    }

    return 0;
}

// Implementação das Funções
int estaOrdenado(TPessoa pessoas[], int quant)
{
    int i;
    for (i = 0; i < quant - 1; i++)
    {
        if (pessoas[i].idade > pessoas[i + 1].idade)
            return 0;
        if (pessoas[i].idade == pessoas[i + 1].idade)
        {
            if (strcmp(pessoas[i].nome, pessoas[i + 1].nome) > 0)
                return 0;
        }
    }
    return 1;
}

void imprimirPessoas(TPessoa pessoas[], int quant)
{
    int i;
    for (i = 0; i < quant; i++)
    {
        printf("Nome: %s | Genero: %c | Idade: %d\n",
               pessoas[i].nome,
               pessoas[i].genero,
               pessoas[i].idade);
    }
}
