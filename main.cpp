#include <iostream>
#include <vector>
#include <fstream>
#include "TodoUtils.h"

int main()
{
    std::ofstream outputFile("tasks.txt");
    std::vector<Todo> todo_list;

    while (true)
    {
        if (outputFile.is_open())
        {
            int choice;
            int task_id;

            std::cout << "1) Create task\n2) Update task\n3) Delete task\n4) Update task completion state\n5) Exit\n";
            std::cout << "Select an option: ";

            std::cin >> choice;
            clearBuffer();

            if (choice == 5)
            {
                break;
            }

            switch (choice)
            {
            case 1:
                todo_list.push_back(createTodo());
                break;
            case 2:
                std::cout << "Enter an ID: ";
                std::cin >> task_id;
                if (Todo *todo = findTodo(todo_list, task_id))
                {
                    updateTodo(*todo, task_id);
                }
                else
                {
                    std::cout << "task not found with ID: " << task_id << '\n';
                }
                clearBuffer();
                break;
            case 3:
                std::cout << "Enter an ID: ";
                std::cin >> task_id;
                if (Todo *todo = findTodo(todo_list, task_id))
                {
                    todo_list.erase(todo_list.begin() + (task_id - 1));
                }
                else
                {
                    std::cout << "task not found with ID: " << task_id << '\n';
                }
                break;
            case 4:
                std::cout << "Enter an ID: ";
                std::cin >> task_id;
                if (Todo *todo = findTodo(todo_list, task_id))
                {
                    updateCompletionState(*todo);
                }
                else
                {
                    std::cout << "task not found with ID: " << task_id << '\n';
                }
                break;

            default:
                break;
            }

            printTodoList(todo_list);
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    writeToFile(todo_list, outputFile);
    return 0;
}
