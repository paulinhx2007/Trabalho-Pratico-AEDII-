#include "arvore_b_mais.h"
void criar_arvore_b_mais(FILE *arq_base, int nFunc) {
    FILE *arq_meta, *arq_indice, *arq_dados;
    abrir_arquivos_b_mais(&arq_meta, &arq_indice, &arq_dados);
    
    inicializar_arvore_b_mais(3);  // Ordem d=3
    
    rewind(arq_base);
    for (int i = 0; i < nFunc; i++) {
        TFunc *func = le_funcionario(arq_base);
        if (func) {
            inserir_b_mais(func, arq_meta, arq_indice, arq_dados);
            free(func);
        }
    }
    
    printf("Arvore B+ criada com %d funcionarios da base de dados.\n", nFunc);
    fechar_arquivos_b_mais(arq_meta, arq_indice, arq_dados);
}
