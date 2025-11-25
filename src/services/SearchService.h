#pragma once
#include <vector>
#include "../model/Task.h"

class SearchService {
public:
    static int binarySearchById(const std::vector<Task>& tasks, int targetId) {
        int left = 0;
        int right = tasks.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (tasks[mid].getId() == targetId) {
                return mid;
            }
            
            if (tasks[mid].getId() < targetId) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};