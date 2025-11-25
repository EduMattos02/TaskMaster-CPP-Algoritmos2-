#pragma once
#include <vector>
#include "../model/Task.h"
#include "../view/TaskView.h"

class TaskController {
private:
    std::vector<Task> tasks;
    TaskView view;

public:
    void run();
};