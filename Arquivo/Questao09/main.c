/*Desenvolver uma função que, dados dois 
arquivos textos arqA e arqB, crie um novo 
arquivo arqC, considerando que:
 arqA e arqB contém números reais, 
um por linha, ordenados 
crescentemente e sem repetição no 
arquivo;
 arqC deve conter apenas os números 
comuns aos dois arquivos originais;
 Assim como arqA e arqB, arqC
também não possuirá repetições de 
elementos e estes deverão estar 
ordenados de forma crescente.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

// Protótipos das Funções
int lerArquivo(char nomeArquivo[50], double numeros[]);
void criarArquivoComum(char arqA[50], char arqB[50], char arqC[50]);

int main()
{
    criarArquivoComum("A.txt", "B.txt", "C.txt");
    printf("Arquivo C.txt criado com sucesso com os numeros comuns!\n");
    return 0;
}

// Implementação das funções
int lerArquivo(char nomeArquivo[50], double numeros[])
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

void criarArquivoComum(char arqA[50], char arqB[50], char arqC[50])
{
    double a[MAX], b[MAX];
    int nA = lerArquivo(arqA, a);
    int nB = lerArquivo(arqB, b);

    FILE *c = fopen(arqC, "w");
    if (!c)
    {
        printf("Erro ao criar o arquivo %s\n", arqC);
        return;
    }

    int i = 0, j = 0;
    double ultimoEscrito = -1e308; 

    while (i < nA && j < nB)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            if (a[i] != ultimoEscrito)
            {
                fprintf(c, "%.2lf\n", a[i]);
                ultimoEscrito = a[i];
            }
            i++;
            j++;
        }
    }

    fclose(c);
}
