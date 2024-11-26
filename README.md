//main
#include <iostream>
#include <chrono>
#include <random>
#include "stack.h"
#include "queue.h"

using namespace std;
using namespace std::chrono;

void measure_time(Stack& stack, Queue& queue, int num_elements) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    // Measure insert time for stack
    auto start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        stack.insert(dis(gen));
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Stack Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure insert time for queue
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        queue.insert(dis(gen));
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Queue Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure remove time for stack
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        stack.remove();
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Stack Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure remove time for queue
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        queue.remove();
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Queue Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;
}

int main() {
    Stack stack;
    Queue queue;

    // Insert elements
    for (int i = 0; i < 10; ++i) {
        stack.insert(i);
        queue.insert(i);
    }

    // Print elements
    cout << "Stack contents:" << endl;
    stack.print();
    cout << "Queue contents:" << endl;
    queue.print();

    // Remove elements
    stack.remove();
    queue.remove();

    // Print elements again
    cout << "Stack contents after one removal:" << endl;
    stack.print();
    cout << "Queue contents after one removal:" << endl;
    queue.print();

    // Performance testing
    measure_time(stack, queue, 100);
    measure_time(stack, queue, 1000);
    measure_time(stack, queue, 10000);

    return 0;

    //node.h
#ifndef NODE_H
#define NODE_H

class Node {
public:
	int data;
	Node* next;//providing direction to the next segment
	Node* prev;//providing direction to previous (or first) segment
	Node(int data) : data(data), next(nullptr), prev(nullptr) {}
	// Node(int data) = declaration //next(nullptr) = init variable next to nullptr. reps the null pointer.
	//no pointer node
   //prev(nullptr) init prev to nullptr. indicating that prev pointer has no node in beginning. 
}; // over all, node not yet linked
#endif //NODE_H

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

//queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <stdexcept>//std "throw" exception needed to be added *

class Queue {

private:
	Node* head;
	Node* tail;

public:
	Queue() : head(nullptr), tail(nullptr) {}

	void insert(int data) {
		Node* newNode = new Node(data);
		if (tail == nullptr) {
			head = tail = newNode;
		}
		else 
		{
			tail->next = newNode;//allowing the node line to continue from latest node.
			newNode->prev = tail;//allowing the node to go back to the prev node.
			tail = newNode;
		}
	}

	int remove() {
		if (head == nullptr) {
			throw std::out_of_range("Queue is Empty");
		}
		int data = head->data;
		Node* temp = head;//pointer temp refers to the node currently at the top of stack.
		//"temp" temporarily store the address of this node so that it can be safely deleted after updating.
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete temp; //deletes current top node
		return data;//returns with remaining data
	}

	void print() {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->data << "";
			current = current->next;
		}
		std::cout << std::endl;

	}
};
#endif //QUEUE_H

