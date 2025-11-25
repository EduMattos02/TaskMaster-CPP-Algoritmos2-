# TaskMaster CLI 🚀

> Trabalho de Algoritmos e Estrutura de Dados - Sistema de Gerenciamento de Tarefas.

Este projeto é um sistema em linha de comando (CLI) desenvolvido em **C++** aplicando conceitos de Engenharia de Software, incluindo arquitetura **MVC**, princípios **SOLID**, **Algoritmos de Ordenação (Selection Sort)** e **Busca (Binary Search)**.

## 👥 Autores (Grupo 3)
* **Eduardo Matos Alves**
* **Luan Ariel**

## 🏗️ Arquitetura do Projeto
O projeto foi estruturado seguindo o padrão MVC para garantir modularidade e separação de responsabilidades.

## 🛠️ Instalação e Execução

Para rodar este projeto na sua máquina, você precisará de um compilador C++ (recomendado: G++ / MinGW), ou apenas rodar o arquivo 
"build_run.bat" que ele já faz a compilação automatica e rodar o sistema.

```mermaid
classDiagram
    class Task {
        +int id
        +string title
        +int priority
    }
    class TaskView {
        +showMenu()
        +clearScreen()
    }
    class TaskController {
        +run()
    }
    class FileService {
        +saveTasks()
        +loadTasks()
    }
    class SortService {
        +selectionSort()
    }

    TaskController --> TaskView : Interação
    TaskController --> SortService : Algoritmos
    TaskController --> FileService : Banco de Dados
    TaskController "1" *-- "n" Task : Gerencia
