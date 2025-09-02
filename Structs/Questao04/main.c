/*Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto). */
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int matricula;
    char nome[50];
    char genero;
    float salario;
} TFuncionario;

// Protótipos das Funções
void deslocarGenero(TFuncionario funcionarios[], int quant, char genero);
void imprimirFuncionarios(TFuncionario funcionarios[], int quant);

int main()
{
    int quant = 5;
    TFuncionario funcionarios[MAX] = {
        {101, "Gabriel", 'M', 3500.0},
        {102, "Karina", 'F', 4000.0},
        {103, "Paulo", 'M', 3200.0},
        {104, "Deborah", 'F', 3700.0},
        {105, "Thiago", 'M', 3100.0}};

    printf("Antes do deslocamento:\n");
    imprimirFuncionarios(funcionarios, quant);
    deslocarGenero(funcionarios, quant, 'F');

    printf("\nDepois do deslocamento (F no início):\n");
    imprimirFuncionarios(funcionarios, quant);

    return 0;
}
// Implementação das Funções
void deslocarGenero(TFuncionario funcionarios[], int quant, char genero)
{
    int i, pos = 0;

    for (i = 0; i < quant; i++)
    {
        if (funcionarios[i].genero == genero)
        {
            if (i != pos)
            {
                TFuncionario temp = funcionarios[i];
                int j;
                for (j = i; j > pos; j--)
                {
                    funcionarios[j] = funcionarios[j - 1];
                }
                funcionarios[pos] = temp;
            }
            pos++;
        }
    }
}
void imprimirFuncionarios(TFuncionario funcionarios[], int quant)
{
    int i;
    for (i = 0; i < quant; i++)
    {
        printf("Matricula: %d | Nome: %s | Genero: %c | Salario: %.2f\n",
               funcionarios[i].matricula,
               funcionarios[i].nome,
               funcionarios[i].genero,
               funcionarios[i].salario);
    }
}
