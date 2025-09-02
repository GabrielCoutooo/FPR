/*Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.*/
#include <stdio.h>
#include <string.h>

void questao02(char string1[], char string2[], char string3[])
{
    int i, j, k = 0, repetido, estaEMs2;

    for (i = 0; string1[i] != '\0'; i++)
    {
        estaEMs2 = 0;
        for (j = 0; string2[j] != '\0'; j++)
        {
            if (string1[i] == string2[j])
            {
                estaEMs2 = 1;
                break;
            }
        }
        if (!estaEMs2)
        {
            repetido = 0;
            for (j = 0; j < k; j++)
            {
                if (string3[j] == string1[i])
                {
                    repetido = 1;
                    break;
                }
            }
            if (!repetido)
            {
                string3[k] = string1[i];
                k++;
            }
        }
    }
    string3[k] = '\0';
}
int main()
{
    char s1[100], s2[100], s3[100];

    printf("Digite a primeira string (s1): ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Digite a segunda string (s2): ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    questao02(s1, s2, s3);

    printf("Resultado (s3): %s\n", s3);

    return 0;
}
