/*
** Função : Sistema de Gerenciamento de Tarefas
** Autor : Marlon - Ciência da Computação - Estruturas de Dados I
** Data : 18/06/2025
** Observações: Executa o fluxo geral: adiciona, agenda, conclui, e conta tarefas
*/

#include <stdio.h>
#include <string.h>
#include "ED-lista2-questao04-tarefa.h"

#include "ED-lista2-questao04-lista.c"
#include "ED-lista2-questao04-pilha.c"
#include "ED-lista2-questao04-fila.c"
#include "ED-lista2-questao04-deque.c"

// Função recursiva para contar número de tarefas na lista
int contarTarefasRecursiva(NoLista *lista) {
    if (lista == NULL) return 0;
    return 1 + contarTarefasRecursiva(lista->prox);
}

// Função auxiliar para verificar se a tarefa está vencida ou não
int hoje() {
    return 18062025; // Simulação da data atual: 18/06/2025
}

int main() {
    // 1. Inicialização
    NoLista *todoList = NULL;
    NoPilha *concluidas = NULL;
    Fila agendadas;
    Deque tarefasImportantes;
    inicializarFila(&agendadas);
    inicializarDeque(&tarefasImportantes);

    // 2. Adição de Tarefas (To-Do List)
    Tarefa t1 = {"Estudar para prova", 3, 18062025};
    Tarefa t2 = {"Enviar email", 2, 18062025};
    Tarefa t3 = {"Organizar pasta", 1, 19062025}; // agendada para o futuro
    todoList = adicionarFim(todoList, t1);
    todoList = adicionarInicio(todoList, t2);

    // 3. Agendamento de Tarefa com data futura
    enfileirar(&agendadas, t3);

    // 4. Mover da fila para lista (caso data de vencimento tenha chegado)
    Tarefa temp;
    int hojeData = hoje();
    Fila filaTemporaria;
    inicializarFila(&filaTemporaria);
    while (desenfileirar(&agendadas, &temp)) {
        if (temp.dataVencimento <= hojeData)
            todoList = adicionarFim(todoList, temp);
        else
            enfileirar(&filaTemporaria, temp); // Reenfileira
    }
    agendadas = filaTemporaria;

    // 5. Concluir uma tarefa
    todoList = removerTarefa(todoList, "Enviar email");
    Tarefa tarefaConcluida = {"Enviar email", 2, 18062025};
    concluidas = empilhar(concluidas, tarefaConcluida);

    // 6. Inserir tarefas de alta prioridade no deque
    if (t1.prioridade == 3) inserirFim(&tarefasImportantes, t1);
    if (t2.prioridade == 3) inserirFim(&tarefasImportantes, t2);
    if (t3.prioridade == 3) inserirFim(&tarefasImportantes, t3);

    // 7. Exibir tudo

    imprimirLista(todoList);

    printf("\n>>> Tarefas Concluídas (Pilha):\n");
    Tarefa concluidaTemp;
    while ((concluidas = desempilhar(concluidas, &concluidaTemp)) != NULL) {
        printf(" - %s (Prioridade %d | Vencimento %d)\n",
               concluidaTemp.descricao,
               concluidaTemp.prioridade,
               concluidaTemp.dataVencimento);
    }

    printf("\n>>> Tarefas Agendadas (Fila):\n");
    while (desenfileirar(&agendadas, &temp)) {
        printf(" - %s (Prioridade %d | Vencimento %d)\n",
               temp.descricao,
               temp.prioridade,
               temp.dataVencimento);
    }

    printf("\n>>> Tarefas de Alta Prioridade (Deque):\n");
    NoDeque *d = tarefasImportantes.inicio;
    while (d != NULL) {
        printf(" - %s (Prioridade %d | Vencimento %d)\n",
               d->tarefa.descricao,
               d->tarefa.prioridade,
               d->tarefa.dataVencimento);
        d = d->prox;
    }

    // 8. Contar tarefas com função recursiva
    int total = contarTarefasRecursiva(todoList);
    printf("\n>>> Total de tarefas restantes (recursivo): %d\n", total);

    return 0;
}
