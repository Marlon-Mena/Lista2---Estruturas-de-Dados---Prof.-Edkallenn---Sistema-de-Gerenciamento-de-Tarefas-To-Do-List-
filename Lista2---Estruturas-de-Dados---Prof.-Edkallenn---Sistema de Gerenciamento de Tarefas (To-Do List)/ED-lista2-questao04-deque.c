/*
** Função : Deque para manipulação eficiente
** Autor : Marlon
** Data : 18/06/2025
** Observações: Permite adicionar/remover início e fim
*/

#include <stdlib.h>

typedef struct NoDeque {
    Tarefa tarefa;
    struct NoDeque *ant, *prox;
} NoDeque;

typedef struct {
    NoDeque *inicio, *fim;
} Deque;

void inicializarDeque(Deque *d) {
    d->inicio = d->fim = NULL;
}

void inserirInicio(Deque *d, Tarefa t) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->tarefa = t;
    novo->ant = NULL;
    novo->prox = d->inicio;
    if (d->inicio == NULL) d->fim = novo;
    else d->inicio->ant = novo;
    d->inicio = novo;
}

void inserirFim(Deque *d, Tarefa t) {
    NoDeque *novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->tarefa = t;
    novo->prox = NULL;
    novo->ant = d->fim;
    if (d->fim == NULL) d->inicio = novo;
    else d->fim->prox = novo;
    d->fim = novo;
}
