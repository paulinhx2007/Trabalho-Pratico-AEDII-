
#include "arvore_b_mais.h"  // Importa as estruturas, constantes e declaracoes da Arvore B+

// Cria a Arvore B+ utilizando os funcionarios existentes na base de dados
void criar_arvore_b_mais(FILE *arq_base, int nFunc) {

    FILE *arq_meta = NULL;    // Ponteiro para o arquivo de metadados
    FILE *arq_indice = NULL;  // Ponteiro para o arquivo dos nos internos
    FILE *arq_dados = NULL;   // Ponteiro para o arquivo dos nos folhas
    int inseridos = 0;       // Contador de funcionarios inseridos
    TFunc *func = NULL;      // Ponteiro para o funcionario lido da base

    // Verifica se o arquivo da base de funcionarios existe
    if (arq_base == NULL) {
        printf("Erro: arquivo da base de dados invalido.\n");
        return;              // Encerra a funcao em caso de erro
    }
    // Verifica se a quantidade de funcionarios e valida
    if (nFunc < 0) {
        printf("Erro: quantidade de funcionarios invalida.\n");
        return;
    }

    // Abre os tres arquivos utilizados pela Arvore B+
    abrir_arquivos_b_mais(&arq_meta, &arq_indice, &arq_dados);
    // Verifica se todos os arquivos foram abertos corretamente
    if (arq_meta == NULL || arq_indice == NULL || arq_dados == NULL) {
        printf("Erro ao abrir os arquivos da Arvore B+.\n");
        // Fecha os arquivos que foram abertos
        if (arq_meta != NULL)
            fclose(arq_meta);
        if (arq_indice != NULL)
            fclose(arq_indice);
        if (arq_dados != NULL)
            fclose(arq_dados);
        return;
    }

    // Inicializa a estrutura da arvore com ordem d = 3
    inicializar_arvore_b_mais(ORDEM_B_MAIS);
    // Posiciona o cursor no inicio da base de funcionarios
    rewind(arq_base);
    // Percorre os funcionarios existentes na base
    for (int i = 0; i < nFunc; i++) {
        // Le um funcionario da posicao atual do arquivo
        func = le_funcionario(arq_base);
        // Verifica se a leitura foi realizada corretamente
        if (func == NULL) {
            printf("Erro ao ler o funcionario %d.\n", i + 1);
            break;
        }
        // Insere o funcionario na estrutura da Arvore B+
        inserir_b_mais(func, arq_meta, arq_indice, arq_dados);
        // Incrementa a quantidade de insercoes solicitadas
        inseridos++;
        // Libera a memoria alocada pela funcao le_funcionario()
        free(func);
        // Evita manter um ponteiro para memoria ja liberada
        func = NULL;
    }
    // Exibe a quantidade de insercoes solicitadas
    printf("\nArvore B+: %d insercoes solicitadas.\n", inseridos);
    // Fecha os arquivos de metadados, indice e dados
    fechar_arquivos_b_mais(arq_meta, arq_indice, arq_dados);
}

inserir_b_mais(func, arq_meta, arq_indice, arq_dados); // Insere um funcionario

buscar_b_mais();                                // Busca funcionario pelo codigo

remover_b_mais();                               // Remove funcionario pelo codigo

imprimir_arvore_b_mais();                              // Imprime a estrutura da arvore
