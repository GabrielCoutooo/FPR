/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/
#include <stdio.h>
int verificarLetras(char nomeArquivo[50])
{
    int cont = 0;
    FILE *arq;
    char caractere;
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro ao abrir o arquivo! ");
        return -1;
    }
    while ((caractere = fgetc(arq)) != EOF)
    {
        if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z'))
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}
int main()
{
    char nomeArquivo[50];
    int resultado;
    printf("Insira o nome do arquivo a ser buscado com a extensao: ");
    scanf("%s", nomeArquivo);
    resultado = verificarLetras(nomeArquivo);
    if (resultado >= 0)
    {
        printf("Foi encontrada %d letras no arquivo!", resultado);
    }
    return 0;
}
