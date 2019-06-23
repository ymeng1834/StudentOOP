#include <iostream>
#include "llist.hpp"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (!nd) {
		os << "nullptr"; }
	else {
		os << "data: " << nd->data << ", next: ";
	}
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d, nullptr);
	}
	else {
		add_at_end(head->next, d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	os << curr;
	if (curr) {
		print_list(os, curr->next);
	}
	else {
		os << endl;
	}
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (!head) { return nullptr; }
	else if(!head->next) { return head; }
	else {
		return last(head->next);
	}
}


/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);
}


/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head) {
	if (!head) { return false; }
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
}


/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head) {
	if (!head) { return false; }
	else {
		if (!head->next) {
			delete head;
			head = nullptr;
			return true;
		}
		else {
			return del_tail(head->next);
		}
	}
}


/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next) {
	if (!curr) { return new_next; }
	else {
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}


/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head) {
	if (!head) { return nullptr; }
	else {
		return new Node(head->data, duplicate(head->next));
	}
}


/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node* list1, Node* list2) {
	if (!list1) {
		if (!list2) { return nullptr; }
		else { return list2; }
	}
	else {
		if (!list2) { return list1; }
		else {
			last(list1)->next = list2;
			return list1;
		}
	}
}


