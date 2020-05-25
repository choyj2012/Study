#include <iostream>
#include <string>
using namespace std;

template<class T>
class NODE {
public:
	T data;
	NODE* next = nullptr;
	NODE(T s) {
		data = s;
	}
};

template<class T>
class Stack {
private:
	NODE<T>* top;
	int size;
public:
	Stack<T>() {
		top = nullptr;
		size = 0;
	}

	~Stack<T>() {
		while (!isEmpty()) {
			Pop();
		}
	}

	void Push(T s);
	void Pop();
	T Top();
	bool isEmpty();
	void PrintStack();
};

template<class T>
void Stack<T>::Push(T s) {
	NODE<T>* newNode = new NODE<T>(s);
	if (top == nullptr)
		top = newNode;
	else {
		newNode->next = top;
		top = newNode;
	}
	size++;
}

template<class T>
void Stack<T>::Pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return;
	}

	NODE<T>* temp;
	temp = top;
	top = top->next;
	delete temp;
	size--;
}

template<class T>
T Stack<T>::Top() {
	return top->data;
}

template<class T>
bool Stack<T>::isEmpty() {
	if (top == nullptr)
		return true;
	else 
		return false;
}

template<class T>
void Stack<T>::PrintStack() {
	NODE<T>* ptr;
	for (ptr = top; ptr != nullptr; ptr = ptr->next) {
		cout << ptr->data << " ";
	}
	cout << "\n";
}

int main() {
	Stack<int>* s = new Stack<int>();
	
	s->Push(1);
	s->Push(2);
	s->Push(3);
	s->PrintStack();
	cout << s->Top() << endl;
	s->Pop();
	s->Pop();
	s->PrintStack();
	s->Pop();
	cout << s->isEmpty() << endl;
	s->Pop();
	delete s;
	return 0;
}