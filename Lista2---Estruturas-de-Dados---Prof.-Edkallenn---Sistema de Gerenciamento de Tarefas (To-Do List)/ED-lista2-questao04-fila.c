/*
** Função : Fila de Agendamento Futuro
** Autor : Marlon
** Data : 18/06/2025
** Observações: Armazena tarefas para datas futuras
*/

#include <stdlib.h>

typedef struct NoFila {
    Tarefa tarefa;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio, *fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->fim = NULL;
}

void enfileirar(Fila *f, Tarefa t) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->tarefa = t;
    novo->prox = NULL;
    if (f->fim == NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
}

int desenfileirar(Fila *f, Tarefa *saida) {
    if (f->inicio == NULL) return 0;
    NoFila *temp = f->inicio;
    *saida = temp->tarefa;
    f->inicio = temp->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    return 1;
}
