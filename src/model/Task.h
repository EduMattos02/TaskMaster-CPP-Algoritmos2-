#pragma once
#include <string>
#include <iostream>

class Task {
private:
    int id;
    std::string title;
    int priority; // 1 (Alta) a 5 (Baixa)

public:
    Task(int id, std::string title, int priority);
    
    int getId() const;
    std::string getTitle() const;
    int getPriority() const;

    void display() const;
};