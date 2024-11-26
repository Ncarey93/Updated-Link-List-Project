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
