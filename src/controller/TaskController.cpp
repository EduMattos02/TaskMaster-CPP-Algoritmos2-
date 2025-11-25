#include "TaskController.h"
#include "../services/SortService.h"
#include "../services/SearchService.h"
#include "../services/FileService.h" // INCLUIR ISTO
#include <iostream>

bool idExists(const std::vector<Task>& tasks, int id) {
    for (const auto& task : tasks) {
        if (task.getId() == id) return true;
    }
    return false;
}

void TaskController::run() {
    tasks = FileService::loadTasks();
    
    while (true) {
        view.clearScreen();
        int option = view.showMenu();

        if (option == 0) break;

        switch (option) {
            case 1: {
                int id;
                std::cout << "Digite o ID: ";
                std::cin >> id;

                if (idExists(tasks, id)) {
                    std::cin.ignore(); 
                    view.showMessage("ERRO: Ja existe uma tarefa com esse ID!");
                } else {
                    std::cin.ignore();
                    std::string title;
                    int prio;
                    
                    std::cout << "Digite o Titulo: ";
                    std::getline(std::cin, title);
                    
                    std::cout << "Digite a Prioridade (1-Alta, 5-Baixa): ";
                    std::cin >> prio;

                    tasks.push_back(Task(id, title, prio));
                    
                    FileService::saveTasks(tasks);
                    view.showMessage("Tarefa salva no banco de dados!");
                }
                break;
            }
            case 2: {
                SortService::selectionSortByPriority(tasks);
                view.showTasks(tasks);
                break;
            }
            case 3: {
                int targetId;
                std::cout << "Digite o ID para buscar: ";
                std::cin >> targetId;
                
                std::vector<Task> tempTasks = tasks;
                SortService::selectionSortById(tempTasks);
                int index = SearchService::binarySearchById(tempTasks, targetId);
                
                if (index != -1) {
                    view.showMessage("Tarefa encontrada:");
                    tempTasks[index].display();
                } else {
                    view.showMessage("Tarefa nao encontrada!");
                }
                break;
            }
            case 4: {
                int targetId;
                std::cout << "Digite o ID para excluir: ";
                std::cin >> targetId;

                bool found = false;
                for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                    if (it->getId() == targetId) {
                        tasks.erase(it);
                        found = true;
                        
                        FileService::saveTasks(tasks);
                        view.showMessage("Tarefa excluida com sucesso!");
                        break;
                    }
                }
                if (!found) view.showMessage("ID nao encontrado para exclusao.");
                break;
            }
            default:
                view.showMessage("Opcao invalida!");
        }
        view.waitUser();
    }
}