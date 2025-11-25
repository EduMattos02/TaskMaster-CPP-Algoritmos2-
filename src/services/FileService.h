#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "../model/Task.h"

class FileService {
public:
    // Salva todas as tarefas no arquivo database.txt
    static void saveTasks(const std::vector<Task>& tasks) {
        std::ofstream file("database.txt");
        if (file.is_open()) {
            for (const auto& task : tasks) {
                // Formato: ID;Titulo;Prioridade
                file << task.getId() << ";" 
                     << task.getTitle() << ";" 
                     << task.getPriority() << "\n";
            }
            file.close();
        }
    }

    // Carrega as tarefas do arquivo ao iniciar o programa
    static std::vector<Task> loadTasks() {
        std::vector<Task> loadedTasks;
        std::ifstream file("database.txt");
        
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string segment;
                std::vector<std::string> parts;

                // Quebra a linha pelo caractere ';'
                while (std::getline(ss, segment, ';')) {
                    parts.push_back(segment);
                }

                if (parts.size() == 3) {
                    try {
                        int id = std::stoi(parts[0]);
                        std::string title = parts[1];
                        int priority = std::stoi(parts[2]);
                        loadedTasks.push_back(Task(id, title, priority));
                    } catch (...) {
                        // Ignora linhas corrompidas
                    }
                }
            }
            file.close();
        }
        return loadedTasks;
    }
};