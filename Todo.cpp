#include "Todo.h"
#include <iostream>

int Todo::next_id{0};

Todo::Todo(const std::string &name, int priority)
    : id(++next_id), name(name), priority(priority), completion_state(completionState::INCOMPLETE) {}

int Todo::getId()
{
    return id;
}
std::string Todo::getName()
{
    return name;
}
int Todo::getPriority()
{
    return priority;
}
completionState Todo::getCompletionState()
{
    return completion_state;
}
void Todo::setName(std::string &name)
{
    this->name = name;
}
void Todo::setPriority(int priority)
{
    this->priority = priority;
}
void Todo::setCompletionState(completionState state)
{
    this->completion_state = state;
}
std::string Todo::printCompletionState()
{
    return completion_state == completionState::COMPLETE ? "COMPLETE" : "INCOMPLETE";
}
