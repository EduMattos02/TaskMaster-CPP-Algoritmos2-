#pragma once
#include <vector>
#include "../model/Task.h"

class SortService {
public:
    // Algoritmo de Ordenação por Seleção (Selection Sort)
    // Ordena por Prioridade (menor valor = maior prioridade)
    static void selectionSortByPriority(std::vector<Task>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (tasks[j].getPriority() < tasks[min_idx].getPriority()) {
                    min_idx = j;
                }
            }
            // Troca manual (poderia usar std::swap)
            if (min_idx != i) {
                std::swap(tasks[i], tasks[min_idx]);
            }
        }
    }
    
    // Auxiliar para ordenar por ID (necessário para a busca binária funcionar)
    static void selectionSortById(std::vector<Task>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (tasks[j].getId() < tasks[min_idx].getId()) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                std::swap(tasks[i], tasks[min_idx]);
            }
        }
    }
};