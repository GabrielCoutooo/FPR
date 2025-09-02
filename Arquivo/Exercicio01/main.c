/*lendo o conteudo de um arquivo e exibindo-o na tela*/
#include <stdio.h>
int main()
{
    int numero;
    FILE *arq;
    arq = fopen("numeros.txt", "r");
    if (!arq)
    {
        printf("Erro na abertura do arquivo!");
    }
    // eof - end of file
    while (fscanf(arq, "%d\n", &numero) != EOF)
    {
        printf("%d\n", numero);
    }
    fclose(arq);
}
