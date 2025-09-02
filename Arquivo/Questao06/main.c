/*Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/
#include <stdio.h>
#include <stdlib.h>

int numerosOrdenados(char nomeArquivo[50])
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return -1;
    }

    int anterior, atual;

    if (fscanf(arquivo, "%d", &anterior) != 1)
    {
        printf("Arquivo vazio ou inválido.\n");
        fclose(arquivo);
        return -1; // Erro
    }

    while (fscanf(arquivo, "%d", &atual) == 1)
    {
        if (atual < anterior)
        {
            fclose(arquivo);
            return 0; // Não está ordenado
        }
        anterior = atual;
    }

    fclose(arquivo);
    return 1; // Está ordenado
}

int main()
{
    char nomeArquivo[50] = "numeros.txt";

    int resultado = numerosOrdenados(nomeArquivo);

    if (resultado == 1)
    {
        printf("Os numeros estao em ordem crescente.\n");
    }
    else if (resultado == 0)
    {
        printf("Os numeros NAO estao em ordem crescente.\n");
    }
    else
    {
        printf("Erro ao processar o arquivo.\n");
    }

    return 0;
}

