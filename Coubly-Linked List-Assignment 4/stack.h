// stack.h
#ifndef STACK_H
#define STACK_H

#include "node.h"

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int remove() {
        if (head == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        int data = head->data;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return data;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // STACK_H