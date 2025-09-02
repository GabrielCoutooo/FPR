#include <stdio.h>

void criarArquivoC(char arqA[], char arqB[], char arqC[]);

int main()
{
    criarArquivoC("A.txt", "B.txt", "C.txt");
    printf("Arquivo C.txt criado com sucesso!\n");
    return 0;
}

void criarArquivoC(char arqA[], char arqB[], char arqC[])
{
    FILE *a = fopen(arqA, "r");
    FILE *b = fopen(arqB, "r");
    FILE *c = fopen(arqC, "w");

    if (!a || !b || !c)
    {
        printf("Erro ao abrir os arquivos!\n");
        if (a)
            fclose(a);
        if (b)
            fclose(b);
        if (c)
            fclose(c);
        return;
    }

    double numA, numB;
    int leituraA = fscanf(a, "%lf", &numA);
    int leituraB = fscanf(b, "%lf", &numB);
    double ultimo = -1e308;

    while (leituraA == 1 && leituraB == 1)
    {
        if (numA < numB)
        {
            if (numA != ultimo)
            {
                fprintf(c, "%lf\n", numA);
                ultimo = numA;
            }
            leituraA = fscanf(a, "%lf", &numA);
        }
        else if (numA > numB)
        {
            if (numB != ultimo)
            {
                fprintf(c, "%lf\n", numB);
                ultimo = numB;
            }
            leituraB = fscanf(b, "%lf", &numB);
        }
        else
        {
            if (numA != ultimo)
            {
                fprintf(c, "%lf\n", numA);
                ultimo = numA;
            }
            leituraA = fscanf(a, "%lf", &numA);
            leituraB = fscanf(b, "%lf", &numB);
        }
    }
    while (leituraA == 1)
    {
        if (numA != ultimo)
        {
            fprintf(c, "%lf\n", numA);
            ultimo = numA;
        }
        leituraA = fscanf(a, "%lf", &numA);
    }
    while (leituraB == 1)
    {
        if (numB != ultimo)
        {
            fprintf(c, "%lf\n", numB);
            ultimo = numB;
        }
        leituraB = fscanf(b, "%lf", &numB);
    }

    fclose(a);
    fclose(b);
    fclose(c);
}
