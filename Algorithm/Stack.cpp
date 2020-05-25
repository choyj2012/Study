#include <iostream>
#include <string>

template<class T>
class NODE {
private:
	T data;
	NODE* next;
public:
	NODE(T t) {
		data = t;
		next = NULL;
	}
};

template<class T>
class Stack {
private:
	NODE<T>* top;
	NODE<T>* head;
	int size;
public:
	Stack<T>() {
		head = NULL;
		size = 0;
	}

	~Stack<T>() {
		if (head != NULL) delete[] head;
	}

	void Push(T s);
	void Pop();
	void Top();
	void isEmpty();
};

template<class T>
void Stack<T>::Push(T s) {
	NODE<T> temp(s);
	if (head == NULL)
		head = &temp;
	else {
		top->next = &temp;
		top = &temp;
	}
}

template<class T>
void Stack<T>::Pop() {

}
int main() {

	Stack<int>* s = new Stack<int>();

}