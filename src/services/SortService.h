#pragma once
#include <vector>
#include "../model/Task.h"

class SortService {
public:

    static void selectionSortByPriority(std::vector<Task>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (tasks[j].getPriority() < tasks[min_idx].getPriority()) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                std::swap(tasks[i], tasks[min_idx]);
            }
        }
    }
    
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