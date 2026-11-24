#ifndef ARVORE_B_MAIS_H       // Verifica se este arquivo ainda nao foi incluido
#define ARVORE_B_MAIS_H       // Define a protecao contra inclusao duplicada

#include <stdio.h>            
#include <stdlib.h>          
#include "funcionarios.h"     // Importa a estrutura TFunc dos funcionarios

#define ORDEM_B_MAIS 3                        // Define a ordem d = 3 da arvore B+
#define MAX_CHAVES_B_MAIS (2 * ORDEM_B_MAIS)  // Numero maximo de chaves por no: 2 * 3 = 6
#define TAM_SEPARADOR 200                     // Espaco reservado para cada separador textual
#define PONTEIRO_NULO -1L                     // Representa uma pagina ou endereco inexistente

// Estrutura utilizada para controlar as informacoes gerais da arvore B+
typedef struct {
    int d;                 // Ordem da arvore B+ (exemplo: d = 3)
    long raiz;             // Offset ou endereco da raiz no arquivo correspondente
    int raiz_e_folha;      // 1 se a raiz for folha; 0 se for no de indice
    int altura;            // Altura atual da arvore B+
} TMetadados;              // Nome da estrutura de metadados

// Estrutura dos nos internos, utilizados para navegar pela arvore
typedef struct {
    int m;                 // Quantidade atual de chaves separadoras no no
    int folha;             // 1 se os filhos forem folhas; 0 se forem nos internos
    long pai;              // Offset do no pai no arquivo de indice
    long p0;               // Ponteiro para o primeiro filho do no
    char chaves[MAX_CHAVES_B_MAIS][TAM_SEPARADOR]; // Armazena ate 6 separadores textuais
    long ponteiros[MAX_CHAVES_B_MAIS];            // Ponteiros para os demais filhos (p1 ate p6)
} TNoIndice;               // Nome da estrutura dos nos internos

// Estrutura dos nos folhas, que armazenam os registros completos
typedef struct {
    int m;                 // Quantidade atual de funcionarios armazenados na folha
    long pai;              // Offset do no pai no arquivo de indice
    long prox;             // Offset da proxima folha; -1 se nao existir
    TFunc registros[MAX_CHAVES_B_MAIS]; // Vetor com capacidade para ate 6 funcionarios
} TNoDados;                // Nome da estrutura dos nos folhas

// Cria a arvore B+ utilizando os funcionarios existentes na base
void criar_arvore_b_mais(FILE *arq_base, int nFunc);

#endif // Encerra a protecao contra inclusao multipla
