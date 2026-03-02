#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;

public:
    Student(string n, int r, float m) {
        name = n;
        rollNo = r;
        marks = m;
    }

    void display() const {
        cout << "Name: " << name
             << ", Roll No: " << rollNo
             << ", Marks: " << marks
             << ", Grade: " << calculateGrade() << endl;
    }

    int getRollNo() const {
        return rollNo;
    }

    char calculateGrade() const {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 40) return 'D';
        else return 'F';
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n==== Student Grade Management System ====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int roll;
            float marks;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Roll No: ";
            cin >> roll;

            cout << "Enter Marks: ";
            cin >> marks;

            students.push_back(Student(name, roll, marks));
            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (const auto &s : students) {
                    s.display();
                }
            }
        }

        else if (choice == 3) {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;

            bool found = false;
            for (const auto &s : students) {
                if (s.getRollNo() == roll) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
