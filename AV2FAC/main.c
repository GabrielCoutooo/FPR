#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAP 10

// Protótipo das funções
void inserir_numero(int vetor[], int *quantidade, int numero, int posicao);
int remover_numero(int vetor[], int *quantidade, int numero);
int remover_posicao(int vetor[], int *quantidade, int posicao);
int alterar_valores(int vetor[], int *quantidade, int numero1, int numero2);
int buscar_numero(int vetor[], int quantidade, int numero);
void exibir_valores(int A[], int quantidade);
void preencher_vetor(int A[], int *quantidade, int limite);
// Main
int main()
{
    int vetor[CAP];
    int quant = 0;
    int escolha, numero, posicao, numero1, numero2;
    preencher_vetor(vetor, &quant, CAP);
    // Menu
    do
    {
        printf("Menu:\n");
        printf("1- Inserir novo numero\n");
        printf("2- Remover valor\n");
        printf("3- Remocao do elemento que encontra-se em uma dada posicao\n");
        printf("4- Alteracao de um valor por outro\n");
        printf("5- Buscar numero\n");
        printf("6- Exibir todos os elementos do vetor\n");
        printf("7- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        switch (escolha)
        {

        case 1:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &numero);
            inserir_numero(vetor, &quant, numero, -1); // Obs: -1 para o valor sempre entrar no final do vetor
            printf("Vetor modificado: \n");
            exibir_valores(vetor, quant);
            printf("\n\n");
            break;
        case 2:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("Digite o valor a ser removido: ");
            scanf("%d", &numero);
            remover_numero(vetor, &quant, numero);
            printf("Vetor modificado: \n");
            exibir_valores(vetor, quant);
            printf("\n\n");
            break;
        case 3:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("Digite a posicao do elemento a ser removido: ");
            scanf("%d", &posicao);
            remover_posicao(vetor, &quant, posicao);
            printf("Vetor modificado: \n");
            exibir_valores(vetor, quant);
            printf("\n\n");
            break;
        case 4:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("Digite o valor a ser alterado: ");
            scanf("%d", &numero1);
            printf("Digite o novo valor: ");
            scanf("%d", &numero2);
            alterar_valores(vetor, &quant, numero1, numero2);
            printf("Vetor modificado: \n");
            exibir_valores(vetor, quant);
            printf("\n\n");
            break;
        case 5:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &numero);
            posicao = buscar_numero(vetor, quant, numero);
            if (posicao != -1)
            {
                printf("O numero %d esta na posicao %d\n", numero, posicao);
            }
            else
            {
                printf("Numero nao encontrado!");
            }
            printf("\n\n");
            break;
        case 6:
            printf("Vetor: ");
            exibir_valores(vetor, quant);
            printf("\n\n");
            break;
        case 7:
            printf("Saindo...");
            printf("\n\n");
            break;
        default:
            printf("Opcao Invalida!\n");
            printf("\n\n");
            break;
        }
    } while (escolha != 7);
    return 0;
}
// Implementação das funções
void inserir_numero(int vetor[], int *quant, int numero, int posicao)
{
    int i;
    // Caso a posição seja -1 o valor sera inserido no final da função
    if (posicao == -1)
    {
        posicao = *quant;
    }
    if (posicao < 0 || posicao > *quant)
    {
        printf("Posicao invalida!\n");
        return;
    }
    for (i = *quant; i > posicao; i--)
    {
        vetor[i] = vetor[i - 1];
    }
    vetor[posicao] = numero;
    (*quant)++;
}

int remover_numero(int vetor[], int *quantidade, int numero)
{
    int posicao = buscar_numero(vetor, *quantidade, numero);
    if (posicao == -1)
    {
        printf("Numero nao encontrado!\n");
        return 0;
    }
    for (int i = posicao; i < *quantidade - 1; i++)
    {
        vetor[i] = vetor[i + 1];
    }
    (*quantidade)--;
    return 1;
}

int remover_posicao(int vetor[], int *quantidade, int posicao)
{
    int i;
    if (posicao < 0 || posicao >= *quantidade)
    {
        printf("Posicao invalida!\n");
        return 0;
    }

    for (i = posicao; i < *quantidade - 1; i++)
    {
        vetor[i] = vetor[i + 1];
    }
    (*quantidade)--;
    return 1;
}

int alterar_valores(int vetor[], int *quantidade, int numero1, int numero2)
{
    int posicao = buscar_numero(vetor, *quantidade, numero1);
    if (posicao == -1)
    {
        printf("Numero nao encontrado!\n");
        return 0;
    }
    remover_numero(vetor, quantidade, numero1);
    inserir_numero(vetor, quantidade, numero2, posicao);

    return 1;
}

int buscar_numero(int vetor[], int quantidade, int numero)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        if (vetor[i] == numero)
        {
            return i;
        }
    }
    return -1;
}

void exibir_valores(int vetor[], int quantidade)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void preencher_vetor(int A[], int *quantidade, int limite)
{
    int i;
    *quantidade = CAP;
    for (i = 0; i < *quantidade; i++)
    {
        A[i] = i;
    }
}
