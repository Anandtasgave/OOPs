#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;

    Node* createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int data) {
        Node *newNode = createNode(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            int data = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return data;
        }
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node *current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, data;

    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                cout << "Popped element: " << s.pop() << endl;
                break;
            case 3:
                cout << "Stack elements: ";
                s.display();
                break;
            case 4:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
