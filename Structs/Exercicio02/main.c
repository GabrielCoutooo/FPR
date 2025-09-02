/*Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
 Determinar a quantidade de pessoas que
fazem aniversário no mês M;
 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/
#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int dia;
    int mes;
} TData;
typedef struct
{
    char nome[30];
    TData aniversario;

} TPessoa;

// Prototipo das funções
int quantNiver(TPessoa pessoas[], int tamanho, int mes);
int compararDatas(TData a, TData b);
void exibirAniversariante(TPessoa pessoas[], int tamanho, TData data1, TData data2);
int main()
{
    TPessoa pessoas[TAM] = {
        {"Gabriel", {20, 5}},
        {"Thiago", {4, 9}},
        {"Karina", {6, 5}},
        {"Paulo", {1, 11}},
        {"Deborah", {2, 2}}

    };
    int mes, quantidade;
    TData d1, d2;
    printf("Digite o mes para verificar quantos fazem aniversario: ");
    scanf("%d", &mes);
    quantidade = quantNiver(pessoas, TAM, mes);
    printf("%d pessoas fazem aniversario no mes %d!\n", quantidade, mes);
    printf("Digite a primeira data(dia mes): ");
    scanf("%d %d", &d1.dia, &d1.mes);
    printf("Digite a segunda data(dia mes): ");
    scanf("%d %d", &d2.dia, &d2.mes);
    printf("\nAniversariantes entre %02d/%02d e %02d/%02d: \n", d1.dia, d1.mes, d2.dia, d2.mes);
    exibirAniversariante(pessoas, TAM, d1, d2);
    return 0;
}
// Implementação das funções
int quantNiver(TPessoa pessoas[], int tamanho, int mes)
{
    int i, cont = 0;
    for (i = 0; i < tamanho; i++)
    {
        if (pessoas[i].aniversario.mes == mes)
        {
            cont++;
        }
    }
    return cont;
}
int compararDatas(TData a, TData b)
{
    if (a.mes < b.mes || (a.mes == b.mes && a.dia < b.dia))
    {
        return -1;
    }
    else if (a.mes == b.mes && a.dia == b.dia)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void exibirAniversariante(TPessoa pessoas[], int tamanho, TData data1, TData data2)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (compararDatas(pessoas[i].aniversario, data1) >= 0 && compararDatas(pessoas[i].aniversario, data2) <= 0)
        {
            printf("%s (%02d/%02d)\n", pessoas[i].nome, pessoas[i].aniversario.dia, pessoas[i].aniversario.mes);
        }
    }
}
