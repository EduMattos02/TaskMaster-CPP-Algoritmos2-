#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "../model/Task.h"

class FileService {
public:
    static void saveTasks(const std::vector<Task>& tasks) {
        std::ofstream file("database.txt");
        if (file.is_open()) {
            for (const auto& task : tasks) {
                file << task.getId() << ";" 
                     << task.getTitle() << ";" 
                     << task.getPriority() << "\n";
            }
            file.close();
        }
    }

    static std::vector<Task> loadTasks() {
        std::vector<Task> loadedTasks;
        std::ifstream file("database.txt");
        
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string segment;
                std::vector<std::string> parts;

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
                    }
                }
            }
            file.close();
        }
        return loadedTasks;
    }
};