#include "Task.h"

Task::Task(int id, std::string title, int priority) 
    : id(id), title(title), priority(priority) {}

int Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
int Task::getPriority() const { return priority; }

void Task::display() const {
    std::cout << "[ID: " << id << "] | P: " << priority << " | " << title << std::endl;
}