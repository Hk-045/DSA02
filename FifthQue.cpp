#include <cstddef> 
#include <iostream> 

class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
private:
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        size--;
    }
};

int main() {
    MyLinkedList linkedList;

    linkedList.addAtHead(1);
    std::cout << "Added 1 at head. Get(0): " << linkedList.get(0) << std::endl; // Expected output: 1

    linkedList.addAtTail(3);
    std::cout << "Added 3 at tail. Get(1): " << linkedList.get(1) << std::endl; // Expected output: 3

    linkedList.addAtIndex(1, 2);
    std::cout << "Added 2 at index 1. Get(1): " << linkedList.get(1) << std::endl; // Expected output: 2
    std::cout << "Get(2): " << linkedList.get(2) << std::endl; // Expected output: 3

    linkedList.deleteAtIndex(1);
    std::cout << "Deleted element at index 1. Get(1): " << linkedList.get(1) << std::endl; // Expected output: 3

    return 0;
}

