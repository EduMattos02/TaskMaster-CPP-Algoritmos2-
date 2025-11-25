#include "TaskController.h"
#include "../services/SortService.h"
#include "../services/SearchService.h"
#include "../services/FileService.h" // INCLUIR ISTO
#include <iostream>

// Função auxiliar para verificar se ID existe (loop simples)
bool idExists(const std::vector<Task>& tasks, int id) {
    for (const auto& task : tasks) {
        if (task.getId() == id) return true;
    }
    return false;
}

void TaskController::run() {
    // 1. CARREGAR DADOS AO INICIAR
    tasks = FileService::loadTasks();
    
    while (true) {
        view.clearScreen();
        int option = view.showMenu();

        if (option == 0) break;

        switch (option) {
            case 1: { // ADICIONAR
                // Vamos pegar os dados manualmente para validar o ID antes
                int id;
                std::cout << "Digite o ID: ";
                std::cin >> id;

                // VALIDACAO DE ID UNICO
                if (idExists(tasks, id)) {
                    // Limpa buffer para evitar erros no proximo loop
                    std::cin.ignore(); 
                    view.showMessage("ERRO: Ja existe uma tarefa com esse ID!");
                } else {
                    // Se o ID é novo, continuamos pedindo o resto
                    std::cin.ignore(); // Limpa o enter do ID
                    std::string title;
                    int prio;
                    
                    std::cout << "Digite o Titulo: ";
                    std::getline(std::cin, title);
                    
                    std::cout << "Digite a Prioridade (1-Alta, 5-Baixa): ";
                    std::cin >> prio;

                    tasks.push_back(Task(id, title, prio));
                    
                    // SALVAR NO BANCO
                    FileService::saveTasks(tasks);
                    view.showMessage("Tarefa salva no banco de dados!");
                }
                break;
            }
            case 2: { // LISTAR
                SortService::selectionSortByPriority(tasks);
                view.showTasks(tasks);
                break;
            }
            case 3: { // BUSCAR
                int targetId;
                std::cout << "Digite o ID para buscar: ";
                std::cin >> targetId;
                
                // Copia e ordena por ID para a busca binária funcionar
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
            case 4: { // EXCLUIR (NOVO)
                int targetId;
                std::cout << "Digite o ID para excluir: ";
                std::cin >> targetId;

                bool found = false;
                // Procura e remove do vetor original
                for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                    if (it->getId() == targetId) {
                        tasks.erase(it); // Remove do vetor
                        found = true;
                        
                        // ATUALIZA O BANCO DE DADOS
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