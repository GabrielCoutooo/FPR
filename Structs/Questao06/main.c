/*O histórico de um aluno é representado por um
vetor de structs onde cada posição armazena o
código da disciplina cursada, semestre e ano
que a cumpriu e a média final na disciplina.
Implementar uma função que exiba o histórico
do aluno com o seguinte formato:
NomeDisciplina1 (código1) MédiaDisciplina1
NomeDisciplina2 (código2) MédiaDisciplina2
NomeDisciplinaN (códigoN) MédiaDisciplinaN
Coeficiente de rendimento: CR
Observações:
1. Para obter os dados da disciplina, um outro
vetor de structs deve ser consultado. Este,
por sua vez, armazena para cada disciplina
do curso as seguintes informações: código,
nome e número de créditos;
2. O coeficiente de rendimento consiste em
uma média ponderada de todos os graus
atribuídos às disciplinas cursadas, onde os
pesos são representados pelo número de
créditos da disciplina;
3. Todos os dados em negrito apresentados no
formato do histórico devem ser obtidos a
partir dos vetores.*/
#include <stdio.h>
#include <string.h>

#define MAX_DISCIPLINAS 10
#define MAX_HISTORICO 20

typedef struct
{
    int codigo;
    char nome[50];
    int creditos;
} TDisciplina;

typedef struct
{
    int codigoDisciplina;
    int semestre;
    int ano;
    float mediaFinal;
} THistorico;

// Protótipos
void exibirHistorico(THistorico historico[], int quantHistorico, TDisciplina disciplinas[], int quantDisciplinas);

int main()
{
    TDisciplina disciplinas[MAX_DISCIPLINAS] = {
        {101, "Matematica", 4},
        {102, "Fisica", 3},
        {103, "Quimica", 3},
        {104, "Historia", 4},
        {105, "Geografia", 4}};
    THistorico historico[MAX_HISTORICO] = {
        {101, 1, 2023, 7.5},
        {104, 1, 2023, 9.0},
        {102, 2, 2023, 8.0},
        {105, 2, 2023, 6.5},
        {103, 2, 2023, 7.0}};

    int quantDisciplinas = 5;
    int quantHistorico = 5;

    exibirHistorico(historico, quantHistorico, disciplinas, quantDisciplinas);

    return 0;
}

// Implementação das Funções
void exibirHistorico(THistorico historico[], int quantHistorico, TDisciplina disciplinas[], int quantDisciplinas)
{
    float somaPonderada = 0.0;
    int somaCreditos = 0;

    printf("Historico do aluno:\n\n");

    for (int i = 0; i < quantHistorico; i++)
    {
        for (int j = 0; j < quantDisciplinas; j++)
        {
            if (historico[i].codigoDisciplina == disciplinas[j].codigo)
            {
                printf("%s (%d) %.2f\n", disciplinas[j].nome, disciplinas[j].codigo, historico[i].mediaFinal);

                somaPonderada += historico[i].mediaFinal * disciplinas[j].creditos;
                somaCreditos += disciplinas[j].creditos;
                break;
            }
        }
    }

    float coeficienteRendimento = 0.0;
    if (somaCreditos > 0)
    {
        coeficienteRendimento = somaPonderada / somaCreditos;
    }

    printf("\nCoeficiente de Rendimento: %.2f\n", coeficienteRendimento);
}
