/*
** Função : Lista Encadeada de Tarefas (To-Do List)
** Autor : Marlon
** Data : 18/06/2025
** Observações: Permite adicionar no início ou fim, e remover tarefas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ED-lista2-questao04-tarefa.h"

typedef struct NoLista {
    Tarefa tarefa;
    struct NoLista *prox;
} NoLista;

NoLista* adicionarInicio(NoLista *lista, Tarefa t) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
    novo->tarefa = t;
    novo->prox = lista;
    return novo;
}

NoLista* adicionarFim(NoLista *lista, Tarefa t) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
    novo->tarefa = t;
    novo->prox = NULL;
    if (lista == NULL) return novo;

    NoLista *aux = lista;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;
    return lista;
}

NoLista* removerTarefa(NoLista *lista, char descricao[]) {
    NoLista *atual = lista, *ant = NULL;
    while (atual != NULL && strcmp(atual->tarefa.descricao, descricao) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return lista; // não encontrou

    if (ant == NULL) lista = atual->prox;
    else ant->prox = atual->prox;

    free(atual);
    return lista;
}

void imprimirLista(NoLista *lista) {
    printf("\n>>> Tarefas a Fazer:\n");
    while (lista != NULL) {
        printf(" - %s (Prioridade: %d | Vencimento: %d)\n",
               lista->tarefa.descricao,
               lista->tarefa.prioridade,
               lista->tarefa.dataVencimento);
        lista = lista->prox;
    }
}
