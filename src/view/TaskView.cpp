#include "TaskView.h"
#include <iostream>
#include <limits>

int TaskView::showMenu() {
    int option;
    std::cout << "\n=== TaskMaster (Grupo 3: Eduardo & Luan) ===" << std::endl;
    std::cout << "1. Adicionar Tarefa" << std::endl;
    std::cout << "2. Listar Tarefas (Ordenadas por Prioridade)" << std::endl;
    std::cout << "3. Buscar Tarefa por ID (Binaria)" << std::endl;
    std::cout << "4. Excluir Tarefa" << std::endl; // NOVO
    std::cout << "0. Sair" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> option;
    return option;
}

Task TaskView::getTaskInput() {
    int id, priority;
    std::string title;

    std::cout << "Digite o ID: ";
    std::cin >> id;
    
std::cin.ignore(); 

    std::cout << "Digite o Titulo: ";
    std::getline(std::cin, title);

    std::cout << "Digite a Prioridade (1-Alta, 5-Baixa): ";
    std::cin >> priority;
    
    return Task(id, title, priority);
}

void TaskView::showTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- Lista de Tarefas ---" << std::endl;
    if (tasks.empty()) {
        std::cout << "Nenhuma tarefa cadastrada." << std::endl;
        return;
    }
    for (const auto& task : tasks) {
        task.display();
    }
}

void TaskView::showMessage(const std::string& msg) {
    std::cout << ">> " << msg << std::endl;
}


void TaskView::clearScreen() {
    system("cls"); 
}

void TaskView::waitUser() {
    std::cout << "\nPressione ENTER para continuar...";
    
    std::cin.ignore(); 
    std::cin.get(); 
}