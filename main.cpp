#include <iostream>
#include <vector>
#include <fstream>

enum completionState
{
    COMPLETE,
    INCOMPLETE
};

struct Todo
{
    int id;
    static int next_id;
    std::string name;
    int priority;
    completionState completion_state;

    Todo()
    {
        id = ++next_id;
    }
};

int Todo::next_id{0};

bool comparePriority(const Todo &a, const Todo &b)
{
    return a.priority < b.priority;
}

Todo *findTodo(std::vector<Todo> &todo_list, int todo_id)
{
    auto it = std::find_if(todo_list.begin(), todo_list.end(),
                           [todo_id](const Todo &t)
                           { return todo_id == t.id; });
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

    std::cout << "Enter a task: ";
    std::getline(std::cin, todo.name);
    std::cout << "Enter the priority: ";

    while (!(std::cin >> todo.priority))
    {
        std::cout << "Enter a valid number: ";
        std::cin.clear();
        clearBuffer();
    }

    clearBuffer();
    return todo;
}

Todo updateTodo(Todo &todo, int task_id)
{
    std::cout << "Enter an ID: ";
    std::cin >> task_id;
    std::cout << "Enter new name: ";
    std::cin >> todo.name;
    std::cout << "Enter new priority: ";
    std::cin >> todo.priority;

    return todo;
}

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

            std::cout << "1) Create task\n2) Update task\n3) Delete task\n4) Exit\n";
            std::cout << "Select an option: ";

            std::cin >> choice;
            clearBuffer();

            switch (choice)
            {
            case 1:
                todo_list.push_back(createTodo());
                break;
            case 2:
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
                return 0;

            default:
                break;
            }

            std::sort(todo_list.begin(), todo_list.end(), comparePriority);

            if (todo_list.size() == 0)
            {
                std::cout << "No tasks found\n";
            }

            for (const auto &todo : todo_list)
            {
                outputFile << todo.id << " -> " << todo.name << " -> " << todo.priority << "\n";
            }
        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }

    outputFile.close();

    return 0;
}