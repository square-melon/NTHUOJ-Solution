#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class Node {
	private:
		char instrm;
		Node *neighbors[2];
		/* disconnect the link with a specific node */
		void unLink(Node *delNeighbor) {
			/* you could consider "nullptr" as "NULL" */
			if(neighbors[0] == delNeighbor) neighbors[0] = nullptr;
			if(neighbors[1] == delNeighbor) neighbors[1] = nullptr;
		}
	public:
		Node() {}
		Node(char instrument) : instrm(instrument), neighbors{nullptr, nullptr} {}
		/* connect this node with another node */
		void link(Node *newNeighbor) {
			neighbors[(neighbors[0] == nullptr ? 0 : 1)] = newNeighbor;
		}
		void output(Node *prevNode) {
			std::cout << instrm;
			for(int i=0;i<2;i++)
				if(neighbors[i] != nullptr && neighbors[i] != prevNode)
					neighbors[i]->output(this);
		}
		/* TODO: destructor for this class */
		~Node();
};

class List { 
	private:
		Node *head, *tail;	// point to the first and the last node of this linked list
	public:
		List() : head(nullptr), tail(nullptr) {}
		/* TODO: using a string to initialize this linked list */
		void init(std::string s);
		/* TODO: make this linked list be a new linked list which is merged from two linked list */
		void merge(List &front, List &back);
		void clear() { head = tail = nullptr; }
		/* TODO: exchange this linked list with another linked list; try to use std::swap! */
		void swap(List &swapList);
		/* TODO: reverse the order of this linked list */
		void reverse();
		void output() {
			if(head != nullptr) head->output(nullptr);
			std::cout << '\n';
		}
		/* TODO: destructor for this class */
		~List();
};

#endif
