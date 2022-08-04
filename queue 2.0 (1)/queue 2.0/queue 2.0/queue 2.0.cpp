#include <iostream>
#include <utility>
using namespace std;
using std::ostream;

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;

	Node(T data) {
		this->data = data;
		next = nullptr;
	}
};

template <typename T>
class Queue {
public:
	Node<T>* front;
	Node<T>* rear;


	
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	
	~Queue() {
		Node<T>* n = front, * current = nullptr;

		while (n != nullptr) {
			current = n;
			n = n->next;
			delete(current);
		}

		front = nullptr;
		rear = nullptr;
		n = nullptr;
		delete n;
	}
	template <typename T>
	friend ostream& operator << (ostream& out, const Queue& q);

	
	bool isEmpty() {
		return (front == nullptr);
	}

	
	void add(T data) {
		Node<T>* newNode = new Node<T>(data);

		if (rear == nullptr) {
			front = newNode;
			rear = newNode;
			newNode = nullptr;
			delete newNode;

			return;

		}

		rear->next = newNode;
		rear = newNode;
		newNode = nullptr;
		delete newNode;
	}

	
	T remove() {
		if (front == nullptr) {
			return 0;
		}
		Node<T>* temp = front;
		front = front->next;

		if (front == nullptr) {
			rear = nullptr;
		}

		delete(temp);
	}

	
	T peek() {
		if (front == nullptr) {
			return 0;
		}
		return front->data;
	}

};


template <typename T>
ostream& operator << (ostream& out, const Queue<T>& q) {
	Node<T>* current = q.front;

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;

	current = nullptr;
	delete current;

	return out;
}

int main() {

	Queue<int> q;


	q.add(1);
	q.add(2);
	q.add(3);


	cout << "Front Element: " << q.peek() << endl;

	q.remove();

	cout << "Front Element: " << q.peek() << endl;

	cout << "Is Queue Empty: ";
	if (q.isEmpty() == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}


	cout << "Display queue: ";
	cout << q;
}