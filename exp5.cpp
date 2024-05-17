#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;

    Node* createNode();
    void initNode(Node *nd, int data);

public:
    LinkedList();
    ~LinkedList();
    void attachBegin(int data);
    void attachEnd(int data);
    Node* detachBegin();
    Node* detachEnd();
    void traverse();
    Node* search(int data);
};

Node* LinkedList::createNode() {
    return new Node;
}

void LinkedList::initNode(Node *nd, int data) {
    nd->data = data;
    nd->next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void LinkedList::attachBegin(int data) {
    Node *newNode = createNode();
    initNode(newNode, data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::attachEnd(int data) {
    Node *newNode = createNode();
    initNode(newNode, data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* LinkedList::detachBegin() {
    if (head == nullptr) {
        cout << "List is empty, cannot detach.\n";
        return nullptr;
    } else {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
    }
}

Node* LinkedList::detachEnd() {
    if (head == nullptr) {
        cout << "List is empty, cannot detach.\n";
        return nullptr;
    } else if (head->next == nullptr) {
        Node *temp = head;
        head = nullptr;
        return temp;
    } else {
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = nullptr;
        return temp;
    }
}

void LinkedList::traverse() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* LinkedList::search(int data) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int main() {
    LinkedList list;

    int n, data;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        list.attachEnd(data);
    }

    // Traverse linked list
    cout << "Linked List elements: ";
    list.traverse();

    // Search data in the linked list
    int searchData;
    cout << "Enter the data to search: ";
    cin >> searchData;
    Node *searchResult = list.search(searchData);
    if (searchResult != nullptr) {
        cout << "Data " << searchData << " found in the linked list.\n";
    } else {
        cout << "Data " << searchData << " not found in the linked list.\n";
    }

    return 0;
}
