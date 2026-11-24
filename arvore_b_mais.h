#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

// TMetadados - Arquivo de controle (metadados)
typedef struct {
    int d;                    // Ordem da árvore
    long raiz;                // Offset da raiz no arquivo de índice
    int raiz_e_folha;         // Flag: 1 se raiz é folha, 0 caso contrário
    int altura;               // Altura da árvore
} TMetadados;

// TNoIndice - Nós do arquivo de índice (index set)
typedef struct {
    int m;                    // Número de chaves no nó
    int folha;                // Flag: 1 se aponta para arquivo de dados, 0 para índice
    long pai;                 // Offset do nó pai
    long p0;                  // Primeiro ponteiro
    char chaves[20][200];     // Separadores (prefixos curtos)
    long ponteiros[20];       // Ponteiros para filhos
} TNoIndice;

// TNoDados - Nós do arquivo de dados/folhas (sequence set)
typedef struct {
    int m;                    // Número de registros no nó
    long pai;                 // Offset do nó pai
    long prox;                // Ponteiro para próxima folha (encadeamento)
    TFunc registros[20];      // Registros completos
} TNoDados;

// Função principal para criar a árvore 
void criar_arvore_bmais_da_base(FILE *arq_base, int nFunc);

