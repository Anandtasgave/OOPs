#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;

    Node* createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    void enqueue(int data) {
        Node *newNode = createNode(data);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            int data = front->data;
            Node *temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return data;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node *current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, data;

    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                cout << "Dequeued element: " << q.dequeue() << endl;
                break;
            case 3:
                cout << "Queue elements: ";
                q.display();
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
