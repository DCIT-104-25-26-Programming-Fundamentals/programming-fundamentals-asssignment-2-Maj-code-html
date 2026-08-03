#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }

    double total = 0.0;
    for (double score : scores) {
        total += score;
    }
    return total / scores.size();
}

void addStudent(vector<Student>& students) {
    Student student;
    int count;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> count;

    student.scores.clear();
    for (int i = 0; i < count; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\nName\t\tID\t\tScores\t\tAverage\n";
    for (const Student& student : students) {
        cout << student.name << "\t" << student.id << "\t";
        for (double score : student.scores) {
            cout << score << " ";
        }
        cout << "\t" << fixed << setprecision(2) << calculateAverage(student.scores) << endl;
    }
}

void calculateAverageForStudent(const vector<Student>& students) {
    int targetId;
    cout << "Enter student ID: ";
    cin >> targetId;

    for (const Student& student : students) {
        if (student.id == targetId) {
            cout << student.name << "'s average score: "
                 << fixed << setprecision(2) << calculateAverage(student.scores) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "===============================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
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

