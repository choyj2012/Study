#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T value;
	Node* next = nullptr;
};

template<typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	Queue<T>() : head(nullptr), tail(nullptr), size(0) {}
	~Queue<T>() {};

	void Enqueue(T value);
	T Dequeue();
	bool isEmpty();
};


int main() {

	Queue<int>* Q = new Queue<int>;
	Q->Enqueue(1);
	Q->Enqueue(2);
	cout << Q->isEmpty() << endl;
	cout << Q->Dequeue() << endl;
	cout << Q->Dequeue() << endl;
	cout << Q->Dequeue() << endl;
	cout << Q->isEmpty() << endl;
	return 0;
}

template<typename T>
void Queue<T>::Enqueue(T _value) {
	Node<T>* newNode = new Node<T>;
	newNode->value = _value;

	size++;

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
}

template<typename T>
T Queue<T>::Dequeue() {

	if (isEmpty()) return -1;

	Node<T>* delNode = head;
	T ret = delNode->value;
	head = delNode->next;
	delete delNode;
	size--;

	if (head == nullptr) tail = nullptr;
	return ret;
}

template<typename T>
bool Queue<T>::isEmpty() {
	if (tail == nullptr)
		return true;
	else return false;
}