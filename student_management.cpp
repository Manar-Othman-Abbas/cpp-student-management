// Student Management System in C++
// A small console app to practice structs, arrays and menu-driven programs.
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "List is full!" << endl;
        return;
    }
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter GPA: ";
    cin >> s.gpa;
    students[studentCount++] = s;
    cout << "Student added." << endl;
}

void listStudents() {
    if (studentCount == 0) {
        cout << "No students yet." << endl;
        return;
    }
    cout << "ID\tName\t\tGPA" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].gpa << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Found: " << students[i].name << " (GPA " << students[i].gpa << ")" << endl;
            return;
        }
    }
    cout << "No student with ID " << id << endl;
}

void topStudent() {
    if (studentCount == 0) {
        cout << "No students yet." << endl;
        return;
    }
    int best = 0;
    for (int i = 1; i < studentCount; i++) {
        if (students[i].gpa > students[best].gpa) best = i;
    }
    cout << "Top student: " << students[best].name << " (GPA " << students[best].gpa << ")" << endl;
}

int main() {
    int choice;
    do {
        cout << "\n=== Student Management ===" << endl;
        cout << "1. Add student" << endl;
        cout << "2. List students" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Top student by GPA" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: searchStudent(); break;
            case 4: topStudent(); break;
            case 0: cout << "Bye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
