#include "TodoUtils.h"
#include <iostream>
#include <algorithm>
#include <limits>

bool comparePriority(Todo &a, Todo &b)
{
    return a.getPriority() < b.getPriority();
}

Todo *findTodo(std::vector<Todo> &todo_list, int todo_id)
{
    auto it = std::find_if(todo_list.begin(), todo_list.end(),
                           [todo_id](Todo &t)
                           { return todo_id == t.getId(); });
    if (it != todo_list.end())
    {
        return &(*it); // return pointer to found Todo
    }
    return nullptr; // not found
}

int clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

Todo createTodo()
{
    Todo todo;
    std::string name;
    int priority;

    std::cout << "Enter a task: ";
    std::getline(std::cin, name);
    std::cout << "Enter the priority: ";

    while (!(std::cin >> priority))
    {
        std::cout << "Enter a valid number: ";
        std::cin.clear();
        clearBuffer();
    }

    todo.setName(name);
    todo.setPriority(priority);

    clearBuffer();
    return todo;
}

Todo updateTodo(Todo &todo, int task_id)
{
    std::string name;
    int priority;

    std::cout << "Enter new name: ";
    std::cin >> name;
    std::cout << "Enter new priority: ";
    std::cin >> priority;

    todo.setName(name);
    todo.setPriority(priority);

    return todo;
}

void updateCompletionState(Todo &todo)
{
    todo.setCompletionState(
        todo.getCompletionState() == completionState::INCOMPLETE
            ? completionState::COMPLETE
            : completionState::INCOMPLETE);

    std::cout << "Task " << todo.getId() << " is now "
              << (todo.printCompletionState())
              << '\n';
}

void writeToFile(std::vector<Todo> &todo_list, std::ofstream &outputFile)
{
    for (auto &todo : todo_list)
    {
        outputFile << todo.getId()
                   << " -> " << todo.getName()
                   << " -> " << todo.getPriority()
                   << " -> " << (todo.printCompletionState())
                   << "\n";
    }

    outputFile.close();
}

void printTodoList(std::vector<Todo> &todo_list)
{
    std::sort(todo_list.begin(), todo_list.end(), comparePriority);

    if (todo_list.size() == 0)
    {
        std::cout << "No tasks found\n";
    }

    for (auto &todo : todo_list)
    {
        std::cout
            << todo.getId()
            << " -> "
            << todo.getName()
            << " -> "
            << todo.getPriority()
            << " -> "
            << (todo.printCompletionState())
            << "\n";
    }
}
