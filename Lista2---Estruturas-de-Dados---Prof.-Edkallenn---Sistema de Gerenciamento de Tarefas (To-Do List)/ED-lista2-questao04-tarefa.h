/*
** Função : TAD Tarefa
** Autor : Marlon - Ciência da Computação - Estruturas de Dados I
** Data : 18/06/2025
** Observações: Representa uma tarefa com descrição, prioridade e vencimento
*/

#ifndef TAREFA_H
#define TAREFA_H

typedef struct {
    char descricao[100];
    int prioridade;      // 1 (baixa), 2 (média), 3 (alta)
    int dataVencimento;  // formato DDMMYYYY
} Tarefa;

#endif
