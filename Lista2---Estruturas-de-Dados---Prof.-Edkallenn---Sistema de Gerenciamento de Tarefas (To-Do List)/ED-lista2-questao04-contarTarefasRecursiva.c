int contarTarefasRecursiva(NoLista *lista) {
    if (lista == NULL) return 0;
    return 1 + contarTarefasRecursiva(lista->prox);
}
