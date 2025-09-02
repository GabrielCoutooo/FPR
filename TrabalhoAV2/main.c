#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CURSOS 100
typedef struct
{
    int codigo;                // Código do curso
    float notaEnade;           // Nota ENADE (20%)
    float idd;                 // IDD(35%)
    float doutores;            // Doutores(15%)
    float mestres;             // Mestres(7.5%)
    float regimeTrabalho;      // Regime de Trabalho(7.5%)
    float organizacaoDidatica; // Organização didática(7.5%)
    float infraestrutura;      // Infraestrutura(5%)
    float oportunidades;       // Oportunidades(2.5%)
    int alunos;                // Numero de alunos matriculados
    float cpcContinuo;         // CPC contínuo calculado
    int cpcFaixa;              // cpc faixa de 1 a 5
    char status[15];           // satisfatorio ou insatisfatorio
} Curso;
// Protótipo das funções
int lendoArquivo(char nomeArquivo[30], Curso cursos[]);
void calcularCPC(Curso *curso);
void calcularIGC(Curso cursos[], int numCursos, float *igcContinuo,
                 int *igcFaixa);
void exibirCursos(Curso cursos[], int numCursos);
void adicionarCursos(Curso cursos[], int *numCursos);
void exibirPorFaixa(Curso cursos[], int numCursos);
// Main
int main()
{
    Curso cursos[MAX_CURSOS];
    int numCursos = 0;
    float igcContinuo = 0;
    char nomeArquivo[30];
    int igcFaixa = 0;
    int opcao;
    // Menu
    do
    {
        printf("========= Menu =========\n");
        printf("1 - Ler arquivo\n");
        printf("2 - Adicionar curso manualmente\n");
        printf("3 - Processar e exibir resultados\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            // Lendo o arquivo
            printf("Insira o nome do arquivo que deseja abrir: ");
            scanf("%s", nomeArquivo);
            numCursos = lendoArquivo(nomeArquivo, cursos);
            break;
        case 2:
            if (numCursos < MAX_CURSOS)
            {
                adicionarCursos(cursos, &numCursos);
            }
            else
            {
                printf("\nLimite de cursos atingido!\n\n");
            }
            break;
        case 3:
            if (numCursos > 0)
            {
                // Calculando os CPCs
                for (int i = 0; i < numCursos; i++)
                {
                    calcularCPC(&cursos[i]);
                }
                // Exibindo os cursos
                exibirCursos(cursos, numCursos);
                // Exibindo os cursos por faixa
                exibirPorFaixa(cursos, numCursos);
                // Calculando e exibindo o IGC
                calcularIGC(cursos, numCursos, &igcContinuo, &igcFaixa);
                printf("\n ========= IGC da Instituicao =========\n");
                printf("IGC Continuo: %.2f\n", igcContinuo);
                printf("IGC Faixa: %d\n\n", igcFaixa);
            }
            else
            {
                printf("Nenhum curso foi carregado!\n\n");
            }
            break;
        }
    } while (opcao != 4);
    return 0;
}
// Implementação das funções
int lendoArquivo(char nomeArquivo[30], Curso cursos[])
{
    FILE *arq;
    int cont = 0, itensLidos;
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }
    while (cont < MAX_CURSOS)
    {
        itensLidos = fscanf(
            arq, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d", &cursos[cont].codigo,
            &cursos[cont].notaEnade, &cursos[cont].idd, &cursos[cont].doutores,
            &cursos[cont].mestres, &cursos[cont].regimeTrabalho,
            &cursos[cont].organizacaoDidatica, &cursos[cont].infraestrutura,
            &cursos[cont].oportunidades, &cursos[cont].alunos);
        // Verificando se o arquivo possui os 10 campos
        if (itensLidos == 10)
        {
            cont++;
        }
        // Verificando se chegou no final do arquivo
        else if (itensLidos == EOF)
        {
            break;
        }
    }
    if (cont > 0)
    {
        printf("\nArquivo Lido com sucesso!\n\n");
    }
    else
    {
        printf("\nArquivo vazio!\n\n");
    }
    fclose(arq);
    return cont;
}
void calcularCPC(Curso *curso)
{
    // Calculando o CPC Continuo
    (*curso).cpcContinuo =
        ((*curso).notaEnade * 0.20) + ((*curso).idd * 0.35) +
        ((*curso).doutores * 0.15) + ((*curso).mestres * 0.075) +
        ((*curso).regimeTrabalho * 0.075) +
        ((*curso).organizacaoDidatica * 0.075) +
        ((*curso).infraestrutura * 0.05) + ((*curso).oportunidades * 0.025);
    // Calculando o CPC Faixa
    if ((*curso).cpcContinuo < 0.945)
    {
        (*curso).cpcFaixa = 1;
        strcpy((*curso).status, "Insatisfatorio");
    }
    else if ((*curso).cpcContinuo < 1.945)
    {
        (*curso).cpcFaixa = 2;
        strcpy((*curso).status, "Insatisfatorio");
    }
    else if ((*curso).cpcContinuo < 2.945)
    {
        (*curso).cpcFaixa = 3;
        strcpy((*curso).status, "Satisfatorio");
    }
    else if ((*curso).cpcContinuo < 3.946)
    {
        (*curso).cpcFaixa = 4;
        strcpy((*curso).status, "Satisfatorio");
    }
    else
    {
        (*curso).cpcFaixa = 5;
        strcpy((*curso).status, "Satisfatorio");
    }
}
void calcularIGC(Curso cursos[], int numCursos, float *igcContinuo,
                 int *igcFaixa)
{
    float somaPonderada = 0;
    int i, totalAlunos = 0;
    // Calculando a soma ponderada(CPC * alunos) e o total de alunos
    for (i = 0; i < numCursos; i++)
    {
        somaPonderada += cursos[i].cpcContinuo * cursos[i].alunos;
        totalAlunos += cursos[i].alunos;
    }
    // Calculando o IGC Continuo
    *igcContinuo = somaPonderada / totalAlunos;
    // Calculando o IGC Faixa usando a mesma tabela do CPC
    if (*igcContinuo < 0.945)
    {
        *igcFaixa = 1;
    }
    else if (*igcContinuo < 1.945)
    {
        *igcFaixa = 2;
    }
    else if (*igcContinuo < 2.945)
    {
        *igcFaixa = 3;
    }
    else if (*igcContinuo < 3.945)
    {
        *igcFaixa = 4;
    }
    else
    {
        *igcFaixa = 5;
    }
}
void exibirCursos(Curso cursos[], int numCursos)
{
    int i;
    printf("\n========= Informacoes dos Cursos =========\n");
    for (i = 0; i < numCursos; i++)
    {
        printf("\nCodigo: %d\n", cursos[i].codigo);
        printf("CPC Continuo: %.2f\n", cursos[i].cpcContinuo);
        printf("CPC Faixa: %d\n", cursos[i].cpcFaixa);
        printf("Status: %s\n", cursos[i].status);
    }
}
void adicionarCursos(Curso cursos[], int *numCursos)
{
    int itensLidos;
    printf("========= Adicionar Curso =========\n");
    printf("Insira as informacoes do curso que deseja adicionar no formato: "
           "codigo|notaEnade|idd|doutores|mestres|regimeTrabalho|"
           "organizacaoDidatica|infraestrutura|oportunidades|alunos\n");
    // Lendo as informações inseridas pelo usuario e verificando se todas as 10
    // informações foram inseridas
    itensLidos =
        scanf("%d|%f|%f|%f|%f|%f|%f|%f|%f|%d", &cursos[*numCursos].codigo,
              &cursos[*numCursos].notaEnade, &cursos[*numCursos].idd,
              &cursos[*numCursos].doutores, &cursos[*numCursos].mestres,
              &cursos[*numCursos].regimeTrabalho,
              &cursos[*numCursos].organizacaoDidatica,
              &cursos[*numCursos].infraestrutura,
              &cursos[*numCursos].oportunidades, &cursos[*numCursos].alunos);
    if (itensLidos == 10)
    {
        calcularCPC(&cursos[*numCursos]);
        (*numCursos)++;
        printf("Curso adicionado com sucesso!\n");
    }
    else
    {
        printf("Formato invalido!\n");
    }
}
void exibirPorFaixa(Curso cursos[], int numCursos)
{
    int faixa, i, encontrados;
    printf("\n========= Cursos agrupados por CPC Faixa =========\n");
    // Percorrendo todas as 5 faixas
    for (faixa = 1; faixa <= 5; faixa++)
    {
        printf("\n CPC Faixa %d: \n", faixa);
        encontrados = 0;
        // Percorrendo todos os cursos
        for (i = 0; i < numCursos; i++)
        {
            if (cursos[i].cpcFaixa == faixa)
            {
                printf("Codigo: %d (CPC: %.2f, Status: %s)\n", cursos[i].codigo,
                       cursos[i].cpcContinuo, cursos[i].status);
                encontrados++;
            }
        }
        if (!encontrados)
        {
            printf("Nenhum curso nessa faixa.\n");
        }
    }
}
