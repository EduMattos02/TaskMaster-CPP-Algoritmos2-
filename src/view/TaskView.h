#pragma once
#include <vector>
#include "../model/Task.h"

class TaskView {
public:
    int showMenu();
    Task getTaskInput();
    void showTasks(const std::vector<Task>& tasks);
    void showMessage(const std::string& msg);

    void clearScreen();
    void waitUser();
};