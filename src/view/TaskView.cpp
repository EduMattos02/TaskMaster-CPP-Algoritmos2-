#include "TaskView.h"
#include <iostream>
#include <limits> // Para limpar o buffer

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
    
    // Esse ignore é essencial para limpar o 'Enter' do ID antes de ler o Título
    std::cin.ignore(); 

    std::cout << "Digite o Titulo: ";
    std::getline(std::cin, title);

    std::cout << "Digite a Prioridade (1-Alta, 5-Baixa): ";
    std::cin >> priority;
    
    // IMPORTANTE: Adicione um ignore extra aqui para não pular o waitUser lá na frente
    // pois sobrará um 'Enter' depois de digitar a prioridade.
    // MAS ATENÇÃO: Isso pode conflitar se a gente usar ignore no waitUser. 
    // Vamos simplificar: NÃO coloque ignore aqui, deixe o waitUser tratar.

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

// ... (restante do código acima igual)

void TaskView::clearScreen() {
    // No Windows usa "cls", no Linux usaria "clear"
    system("cls"); 
}

void TaskView::waitUser() {
    std::cout << "\nPressione ENTER para continuar...";
    
    // Limpa o buffer de entrada e espera uma tecla
    std::cin.ignore(); 
    std::cin.get(); 
}