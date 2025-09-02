/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
 */
#include <stdio.h>
int contCaracter(char nomeArquivo[50], char c)
{
    FILE *arq;
    int cont = 0;
    char caracter;
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    while ((caracter = fgetc(arq)) != EOF)
    {
        if (caracter == c)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}
int main()
{
    int resultado;
    char caracteres, nomeArquivo[50];
    printf("Insira o nome do arquivo que deseja buscar: ");
    scanf("%s", nomeArquivo);
    getchar();
    printf("Insira o caractere a ser buscado no arquivo: ");
    scanf("%c", &caracteres);
    resultado = contCaracter(nomeArquivo, caracteres);
    if (resultado != -1)
    {
        printf("foi encontrado %d caracteres igual a letra %c", resultado, caracteres);
    }
    return 0;
}
