# 📝 Todo List Application (C++)

[![C++](https://img.shields.io/badge/Language-C++17-blue)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A simple command-line **Todo List application** in C++ that allows you to create, update, delete, and view tasks with priorities. Tasks are saved to a file (`tasks.txt`) when the program exits.

---

## Features

* ✅ Create tasks with a **name** and **priority**
* ✏️ Update existing tasks by **ID**
* ❌ Delete tasks by **ID**
* 📄 Display tasks sorted by **priority**
* 💾 Save tasks to `tasks.txt`

---

## Demo

```bash
1) Create task
2) Update task
3) Delete task
4) Exit
Select an option: 1
Enter a task: Buy groceries
Enter the priority: 2
```

Output after creating tasks:

```
1 -> Buy groceries -> 2
2 -> Finish homework -> 1
```

---

## Installation

1. **Clone the repository**

```bash
git clone <repository_url>
cd <repository_directory>
```

2. **Compile the project**

```bash
g++ -std=c++17 -o todo main.cpp Todo.cpp TodoUtils.cpp
```

3. **Run the program**

```bash
./todo
```

> On **Mac / VSCode**, open the folder, use the terminal or configure build tasks to compile and run.

---

## Project Structure

```
.
├── main.cpp        # Main menu & program loop
├── Todo.h          # Todo class declaration
├── Todo.cpp        # Todo class definition
├── TodoUtils.h     # Utility function declarations
├── TodoUtils.cpp   # Utility function definitions
└── tasks.txt       # Saved tasks (created on exit)
```

---

## Usage

* **Create task:** Enter task name and priority
* **Update task:** Enter task ID, then new name and priority
* **Delete task:** Enter task ID
* **Exit:** Saves tasks to `tasks.txt`

Tasks are displayed **sorted by priority** automatically after each operation.

---

## Future Improvements

* Load tasks from `tasks.txt` on startup
* Toggle completion status (`COMPLETE` / `INCOMPLETE`)
* Add due dates and reminders
* Use **smart pointers** for dynamic allocation

---

## License

This project is released under the [MIT License](LICENSE).
