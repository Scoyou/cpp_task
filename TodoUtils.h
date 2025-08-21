#ifndef TODO_UTILS_H
#define TODO_UTILS_H

#include "Todo.h"
#include <vector>
#include <fstream>

bool comparePriority(Todo &a, Todo &b);
int clearBuffer();
Todo* findTodo(std::vector<Todo> &todo_list, int todo_id);
Todo createTodo();
Todo updateTodo(Todo &todo, int task_id);
void printTodoList(std::vector<Todo> &todo_list);
void writeToFile(std::vector<Todo> &todo_list, std::ofstream &outputFile);

#endif
