#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    // Parameterized Constructor
    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = 0;
        setMarks(m);
    }

    // Getter Functions
    int getRollNo()
    {
        return rollNo;
    }

    string getName()
    {
        return name;
    }

    float getMarks()
    {
        return marks;
    }

    // Set Marks with Validation
    void setMarks(float m)
    {
        if (m >= 0 && m <= 100)
        {
            marks = m;
        }
        else
        {
            cout << "Invalid Marks! Marks must be between 0 and 100." << endl;
        }
    }

    // Display Function
    void display()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
    }
};

// Function accepting an object
void printResult(Student s)
{
    cout << "\n\n------ Student Result ------";
    cout << "\nRoll Number: " << s.getRollNo();
    cout << "\nName: " << s.getName();
    cout << "\nMarks: " << s.getMarks();

    if (s.getMarks() >= 40)
    {
        cout << "\nResult: PASS";
    }
    else
    {
        cout << "\nResult: FAIL";
    }

    cout << "\n----------------------------";
}

int main()
{
    int r1, r2, r3;
    string n1, n2, n3;
    float m1, m2, m3;

    cout << "===== STUDENT MANAGEMENT SYSTEM =====\n";

    // Get Student Details
    cout << "\nEnter Student 1 Details";
    cout << "\nRoll Number: ";
    cin >> r1;
    cout << "Name: ";
    cin >> n1;
    cout << "Marks: ";
    cin >> m1;

    cout << "\nEnter Student 2 Details";
    cout << "\nRoll Number: ";
    cin >> r2;
    cout << "Name: ";
    cin >> n2;
    cout << "Marks: ";
    cin >> m2;

    cout << "\nEnter Student 3 Details";
    cout << "\nRoll Number: ";
    cin >> r3;
    cout << "Name: ";
    cin >> n3;
    cout << "Marks: ";
    cin >> m3;

    // Array of Objects
    Student batch[3] = {
        Student(r1, n1, m1),
        Student(r2, n2, m2),
        Student(r3, n3, m3)
    };

    // Display Student Details
    cout << "\n\n===== STUDENT DETAILS =====";

    for (int i = 0; i < 3; i++)
    {
        batch[i].display();
        cout << endl;
    }

    // Re-evaluation of Marks
    int choice;
    float newMarks;

    cout << "\nEnter Student Number for Re-evaluation (1-3): ";
    cin >> choice;

    if (choice >= 1 && choice <= 3)
    {
        cout << "Enter New Marks: ";
        cin >> newMarks;

        batch[choice - 1].setMarks(newMarks);
    }
    else
    {
        cout << "Invalid Student Number!";
    }

    // Print Final Results
    cout << "\n\n===== FINAL RESULTS =====";

    for (int i = 0; i < 3; i++)
    {
        printResult(batch[i]);
    }

    return 0;
}