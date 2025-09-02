/* Exemplo 4: lendo o conteudo de um arquivo e exibindo-o na tela
   (qualquer arquivo)*/
#include <stdio.h>
int main()
{
    char caracter;
    FILE *arq;
    arq = fopen("arquivos4.c", "r");
    if (!arq)
    {
        printf("Erro na abertura do arquivo!");
    }
    while (fscanf(arq, "%c", &caracter) != EOF)
    {
        printf("%c", caracter);
    }
    fclose(arq);
}
