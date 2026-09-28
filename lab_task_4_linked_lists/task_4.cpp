#include <iostream>
using namespace std;

class Course
{
    struct Node
    {
        int rollNumber;
        Node* next;
    };

    Node* head;

public:

    Course()
    {
        head = NULL;
    }

    // Add student at the end
    void addStudent(int roll)
    {
        Node* newNode = new Node;

        newNode->rollNumber = roll;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Insert student at beginning
    void insertBeginning(int roll)
    {
        Node* newNode = new Node;

        newNode->rollNumber = roll;
        newNode->next = head;

        head = newNode;
    }

    // Search student
    void search(int roll)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNumber == roll)
            {
                cout << "Student Found!" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student Not Found!" << endl;
    }

    // Display students
    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->rollNumber << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    Course course;

    course.addStudent(22);
    course.addStudent(35);
    course.addStudent(41);
    course.addStudent(56);

    cout << "Initially:" << endl;
    course.display();

    course.insertBeginning(18);

    cout << "\nAfter inserting 18:" << endl;
    course.display();

    cout << "\nSearching for 41:" << endl;
    course.search(41);

    return 0;
}
