#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;
    float marks;
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, s.department);

    cout << "Enter Marks: ";
    cin >> s.marks;

    file << s.id << "|"
         << s.name << "|"
         << s.age << "|"
         << s.department << "|"
         << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    string line;

    cout << "\n----- Student Records -----\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    string line;
    int searchId;
    bool found = false;

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    while (getline(file, line)) {
        int id = stoi(line.substr(0, line.find('|')));

        if (id == searchId) {
            cout << "\nRecord Found:\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    file.close();
}

void deleteStudent() {
    int deleteId;
    string line;

    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    bool found = false;

    while (getline(file, line)) {
        int id = stoi(line.substr(0, line.find('|')));

        if (id != deleteId)
            temp << line << endl;
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
