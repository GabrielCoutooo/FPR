/*Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno,
as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

A declaração do vetor, assim como de todos os tipos de dados necessários, caso
existam;

Uma função que leia os dados de todos os alunos da turma;

Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a
sua situação;

Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba
todos os alunos que estão nesta situação.*/
#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 20
typedef struct
{
    char nome[50];
    float AV1;
    float AV2;
    float media;
    char situacao;
} TAluno;
// Prototipo das funções
void lerDados(TAluno alunos[], int quantidade);
void situacaoAluno(TAluno alunos[], int quantidade);
void exibirPorSituacao(TAluno alunos[], int quantidade, int tipo);

int main()
{
    int n, opcao = 0;
    printf("Digite o numero de Alunos: ");
    scanf("%d", &n);
    if (n > MAX_ALUNOS)
    {
        printf("Numero de Alunos excede o maximo permitido");
        return 1;
    }
    TAluno alunos[MAX_ALUNOS];
    lerDados(alunos, n);
    situacaoAluno(alunos, n);
    while (1)
    {
        printf("\n Exibir alunos por situacao: \n");
        printf("1- Aprovado\n 2- Reprovado\n 3- Em AVF\n4- Sair\nEscolha: ");
        scanf("%d", &opcao);
        printf("\n\n");
        if (opcao == 4)
        {
            printf("Saindo....");
            break;
        }
        if(opcao >= 1 && opcao <=3){
            exibirPorSituacao(alunos, n, opcao);
        }else{
            printf("Opcao invalida!");
        }
    }
    return 0;
}
void lerDados(TAluno alunos[], int quantidade)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        printf("\n Aluno %d: \n", i + 1);
        printf("Nome: ");
        getchar();
        fgets(alunos[i].nome, 50, stdin);
        printf("Nota AV1: ");
        scanf("%f", &alunos[i].AV1);
        printf("Nota AV2: ");
        scanf("%f", &alunos[i].AV2);
    }
}
void situacaoAluno(TAluno alunos[], int quantidade)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        alunos[i].media = (alunos[i].AV1 + alunos[i].AV2) / 2;
        if (alunos[i].media >= 6.0)
        {
            alunos[i].situacao = 'A';
        }
        else if (alunos[i].media < 4)
        {
            alunos[i].situacao = 'R';
        }
        else if (alunos[i].media >= 4 && alunos[i].media < 6)
        {
            alunos[i].situacao = 'F';
        }
    }
}
void exibirPorSituacao(TAluno alunos[], int quantidade, int tipo)
{
    int i;
    char status;
    if (tipo == 1)
        status = 'A';
    else if (tipo == 2)
        status = 'R';
    else if (tipo == 3)
        status = 'F';
    printf("\n Alunos com situacao ");
    if (status == 'A')
        printf("Aprovado");
    else if (status == 'R')
        printf("Reprovado");
    else
        printf("EM AVF");
    for (i = 0; i < quantidade; i++)
    {
        if (alunos[i].situacao == status)
        {
            printf("\n Nome: %s| AV1: %.2f | AV2: %.2f | Media: %.2f\n",
                   alunos[i].nome, alunos[i].AV1, alunos[i].AV2, alunos[i].media);
        }
    }
}
