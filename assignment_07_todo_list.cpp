#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << endl;
        return;
    }

    cout << "Task \"" << tasks[taskNumber - 1] << "\" has been removed." << endl;
    tasks.erase(tasks.begin() + taskNumber - 1);
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n============================\n";
        cout << "     TO-DO LIST MENU\n";
        cout << "============================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Delete task\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1 to 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

