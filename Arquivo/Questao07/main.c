/*Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição
*/
#include <stdio.h>
#define MAX 1000

// Protótipos das funções
int lerNumeros(char nomeArquivo[50], double numeros[]);
void ordenarDecrescente(double numeros[], int n);
void removerRepetidos(double numeros[], int *n);
void escreverArquivo(char nomeArquivo[50], double numeros[], int n);

int main()
{
    double numeros[MAX];
    int n;
    n = lerNumeros("A.txt", numeros);

    ordenarDecrescente(numeros, n);

    removerRepetidos(numeros, &n);

    escreverArquivo("B.txt", numeros, n);

    printf("Arquivo B.txt criado com sucesso!\n");

    return 0;
}

// Implementação das funções
int lerNumeros(char nomeArquivo[50], double numeros[])
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int n = 0;
    while (fscanf(arquivo, "%lf", &numeros[n]) == 1)
    {
        n++;
        if (n >= MAX)
            break;
    }

    fclose(arquivo);
    return n;
}

// (Bubble Sort)
void ordenarDecrescente(double numeros[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (numeros[j] < numeros[j + 1])
            {
                double temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

void removerRepetidos(double numeros[], int *n)
{
    int j = 0;
    for (int i = 1; i < *n; i++)
    {
        if (numeros[i] != numeros[j])
        {
            j++;
            numeros[j] = numeros[i];
        }
    }
    *n = j + 1;
}

void escreverArquivo(char nomeArquivo[50], double numeros[], int n)
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo)
    {
        printf("Erro ao criar o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(arquivo, "%.2lf\n", numeros[i]);
    }

    fclose(arquivo);
}

