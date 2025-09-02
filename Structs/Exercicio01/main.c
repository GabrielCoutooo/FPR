/*Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char placa[8];
    char modelo[20];
    char marca[20];
    char cor[20];
    int quilometragem;
    int anoModelo;
    int anoFabricacao;
    float valorCarro;
} TCarro;
// Prototipo das funções
void exibirCarros(TCarro carros[], int tamanho, char modelo[], int ano1, int ano2, float valor_max);
void reajustarValores(TCarro carros[], int tamanho, float aumento);
void retirarEstoque(TCarro carros[], int *tamanho, char placa[8]);
void exibirTodosCarros(TCarro carros[], int tamanho);
void mostrarMenu();

int main()
{
    TCarro estoque[100] = {
        {"ABC1234", "Gol", "Volkswagen", "Vermelho", 0, 2023, 2022, 65000.00},
        {"DEF5678", "Onix", "Chevrolet", "Prata", 45000, 2021, 2020, 58000.00},
        {"GHI9012", "HB20", "Hyundai", "Branco", 0, 2023, 2023, 72000.00},
        {"JKL3456", "Gol", "Volkswagen", "Preto", 80000, 2019, 2018, 45000.00},
        {"MNO7890", "Argo", "Fiat", "Azul", 20000, 2022, 2021, 55000.00}};
    int tamanhoEstoque = 5;
    int opcao;

    do
    {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao)
        {
        case 1:
        {
            // Exibir todos os carros
            printf("\n=== TODOS OS CARROS ===\n");
            exibirTodosCarros(estoque, tamanhoEstoque);
            break;
        }
        case 2:
        {
            // Buscar carros por filtros
            char modelo[20];
            int ano1, ano2;
            float valor;

            printf("\nModelo: ");
            scanf("%s[^\n]", modelo);
            getchar();

            printf("Ano inicial: ");
            scanf("%d", &ano1);
            getchar();

            printf("Ano final: ");
            scanf("%d", &ano2);
            getchar();

            printf("Valor máximo: ");
            scanf("%f", &valor);
            getchar();

            printf("\n=== RESULTADOS DA BUSCA ===\n");
            exibirCarros(estoque, tamanhoEstoque, modelo, ano1, ano2, valor);
            break;
        }
        case 3:
        {
            // Reajustar valores 0km
            float aumento;
            printf("\nPercentual de aumento para carros 0km: ");
            scanf("%f", &aumento);
            getchar();

            reajustarValores(estoque, tamanhoEstoque, aumento);
            printf("Reajuste aplicado!\n");
            break;
        }
        case 4:
        {
            // Remover carro
            char placa[8];
            printf("\nPlaca do carro a remover: ");
            scanf("%s[^\n]", placa);
            getchar();

            retirarEstoque(estoque, &tamanhoEstoque, placa);
            break;
        }
        case 0:
            printf("\nSaindo do sistema...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }

        if (opcao != 0)
        {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0);

    return 0;
}
// Implementação das funções
void exibirCarros(TCarro carros[], int tamanho, char modelo[], int ano1, int ano2, float valor_max)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (strcmp(carros[i].modelo, modelo) == 0 && carros[i].anoFabricacao >= ano1 && carros[i].anoFabricacao <= ano2 && carros[i].valorCarro <= valor_max)
        {
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Marca: %s\n", carros[i].marca);
            printf("Ano de Fabricacao: %d\n", carros[i].anoFabricacao);
            printf("Cor: %s\n", carros[i].cor);
            printf("Placa: %s\n", carros[i].placa);
        }
    }
}
void exibirTodosCarros(TCarro carros[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Marca: %s\n", carros[i].marca);
        printf("Ano de Fabricacao: %d\n", carros[i].anoFabricacao);
        printf("Cor: %s\n", carros[i].cor);
        printf("Placa: %s\n", carros[i].placa);
        printf("Quilometragem: %d\n", carros[i].quilometragem);
        printf("Ano do modelo: %d\n", carros[i].anoModelo);
        printf("Valor: R$ %f\n", carros[i].valorCarro);
        printf("------------------------------------------------------------------\n\n");
    }
}
void reajustarValores(TCarro carros[], int tamanho, float aumento)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (carros[i].quilometragem == 0)
        {
            carros[i].valorCarro *= (1 + aumento / 100);
        }
    }
}
void retirarEstoque(TCarro carros[], int *tamanho, char placa[8])
{
    int i, j;
    for (i = 0; i < *tamanho; i++)
    {
        if (strcmp(carros[i].placa, placa) == 0)
        {
            for (j = i; j < *tamanho - 1; j++)
            {
                carros[j] = carros[j + 1];
            }
            (*tamanho)--;
            printf("Carro removido do estoque!\n");
            return;
        }
    }
    printf("Carro com a placa %s nao encontrada!", placa);
}
void mostrarMenu()
{
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Exibir todos os carros\n");
    printf("2. Buscar carros por filtros\n");
    printf("3. Reajustar valores (0km)\n");
    printf("4. Remover carro do estoque\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}
