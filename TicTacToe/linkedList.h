#pragma once

using namespace std;

class SNode {
public:
	SNode(char val) : value(val), next(nullptr) {}
	char getValue() const {
		return value;
	}
	void setValue(char val) {
		value = val;
	}
	SNode* getNext() const {
		return next;
	}
	void setNext(SNode* nextNode) {
		next = nextNode;
	}
private:
	char value;
	SNode* next;
	friend class SLinkedList;
};

class SLinkedList {
public:
	SLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~SLinkedList() {
		while (head) {
			SNode* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}
	void addOnEmpty(char val) {
		SNode* newNode = new SNode(val);
		head = newNode;
		tail = newNode;
		size++;
	}
	void addFront(char val) {
		if (head == nullptr) addOnEmpty(val);
		else {
			SNode* newNode = new SNode(val);
			newNode->next = head;
			head = newNode;
			size++;
		}
	}
	void addBack(char val) {
		if (tail == nullptr) addOnEmpty(val);
		else {
			SNode* newNode = new SNode(val);
			tail->next = newNode;
			tail = newNode;
			size++;
		}
	}
	void clearList() {
		while (head) {
			SNode* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		size = 0;
	}
	unsigned int getSize() const {
		return size;
	}
	SNode* getHead() {
		return head;
	}
	SNode* getTail() {
		return tail;
	}
private:
	SNode* head;
	SNode* tail;
	unsigned int size;
};