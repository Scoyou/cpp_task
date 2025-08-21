#ifndef TODO_H
#define TODO_H

#include<string>

enum class completionState{
    COMPLETE,
    INCOMPLETE
};

class Todo{
    private: 
        int id;
        static int next_id;
        std::string name;
        int priority;
        completionState completion_state;
    public:
        // Constructor
        Todo(const std::string &name="", int priority=0);

        std::string printCompletionStateStr();

        // Getters
        int getId();
        std::string getName();
        int getPriority();
        completionState getCompletionState();

        // Setters
        void setName(std::string &name);
        void setPriority(int priority);
        void setCompletionState(completionState state);
};

#endif
