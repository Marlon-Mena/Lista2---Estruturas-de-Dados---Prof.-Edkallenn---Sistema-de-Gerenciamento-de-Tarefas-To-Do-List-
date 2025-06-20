/*
** Função : Pilha de Tarefas Concluídas
** Autor : Marlon
** Data : 18/06/2025
** Observações: Implementação clássica de pilha encadeada
*/

#include <stdlib.h>
#include <string.h>

typedef struct NoPilha {
    Tarefa tarefa;
    struct NoPilha *prox;
} NoPilha;

NoPilha* empilhar(NoPilha *topo, Tarefa t) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->tarefa = t;
    novo->prox = topo;
    return novo;
}

NoPilha* desempilhar(NoPilha *topo, Tarefa *saida) {
    if (topo == NULL) return NULL;
    *saida = topo->tarefa;
    NoPilha *temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}
