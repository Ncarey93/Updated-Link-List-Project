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