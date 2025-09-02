/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.
 */
#include <stdio.h>
int verificarCaracter(char nomeArquivo[])
{
    FILE *arquivo;
    char c;
    int cont = 0;
    arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo");
        return -1;
    }
    while ((c = fgetc(arquivo)) != EOF)
    {
        cont++;
    }
    fclose(arquivo);
    return cont;
}
int main()
{
    int c;
    char nomeArquivo[50];
    printf("Insira o nome do arquivo que deseja abrir com a extensao: ");
    scanf("%s", nomeArquivo);
    c = verificarCaracter(nomeArquivo);
    if (c != -1)
    {
        printf("Existem %d caracteres no arquivo", c);
    }
    return 0;
}
