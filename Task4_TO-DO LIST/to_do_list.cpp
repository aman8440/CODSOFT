#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc, bool completed = false) : description(desc), completed(completed) {}
    void toggleCompleted() {
        completed = !completed;
    }
};

class TodoList {
private:
    vector<Task> tasks;
    string filename;

public:
    TodoList(const string& file) : filename(file) {
        loadTasks();
    }

    void addTask(const string& description) {
        Task task(description);
        tasks.push_back(task);
        saveTasks(); 
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Task List:" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].toggleCompleted();
            saveTasks(); 
        } else {
            cout << "Invalid task index. No task marked as completed." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex);
            saveTasks(); 
        } else {
            cout << "Invalid task index. No task removed." << endl;
        }
    }

    void saveTasks() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Task& task : tasks) {
                file << (task.completed ? "1" : "0") << " " << task.description << endl;
            }
            file.close();
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadTasks() {
        ifstream file(filename);
        if (file.is_open()) {
            tasks.clear(); 
            string line;
            while (getline(file, line)) {
                if (!line.empty()) {
                    char completed = line[0];
                    bool isCompleted = (completed == '1');
                    string description = line.substr(2);
                    tasks.push_back(Task(description, isCompleted));
                }
            }
            file.close();
        } else {
            cout << "No existing tasks file found." << endl;
        }
    }
};

int main() {
    TodoList todoList("task.txt");

    while (true) {
        cout << "\n----------To-Do List Manager----------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
        } else if (choice == 2) {
            todoList.viewTasks();
        } else if (choice == 3) {
            todoList.viewTasks();
            cout << "Enter the task number to mark as completed: ";
            size_t taskIndex;
            cin >> taskIndex;
            todoList.markAsCompleted(taskIndex - 1); 
        } else if (choice == 4) {
            todoList.viewTasks();
            cout << "Enter the task number to remove: ";
            size_t taskIndex;
            cin >> taskIndex;
            todoList.removeTask(taskIndex - 1);
        } else if (choice == 5) {
            cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}