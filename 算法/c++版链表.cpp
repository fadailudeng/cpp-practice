#include <iostream>

class LinkedList {
private:
	struct Node {
		int value;
		Node* next;

		Node(int value, Node* next = nullptr) : value(value), next(next) {}
	};

	Node* head = nullptr;

public:
	~LinkedList() {
		clear();
	}

	void pushFront(int value) {
		head = new Node(value, head);
	}

	void pushBack(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	bool remove(int value) {
		Node* current = head;
		Node* previous = nullptr;

		while (current != nullptr) {
			if (current->value == value) {
				if (previous == nullptr) {
					head = current->next;
				} else {
					previous->next = current->next;
				}
				delete current;
				return true;
			}

			previous = current;
			current = current->next;
		}

		return false;
	}

	bool contains(int value) const {
		const Node* current = head;
		while (current != nullptr) {
			if (current->value == value) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void print() const {
		const Node* current = head;
		while (current != nullptr) {
			std::cout << current->value;
			if (current->next != nullptr) {
				std::cout << " -> ";
			}
			current = current->next;
		}
		std::cout << " -> nullptr\n";
	}

	void clear() {
		while (head != nullptr) {
			Node* nodeToDelete = head;
			head = head->next;
			delete nodeToDelete;
		}
	}
};

int main() {
	LinkedList list;

	list.pushBack(10);
	list.pushBack(20);
	list.pushFront(5);

	std::cout << "链表内容：";
	list.print();

	std::cout << "是否包含 20"
			  << (list.contains(20) ? "是" : "否") << '\n';

	list.remove(10);
	std::cout << "删除 10 后：";
	list.print();

	return 0;
}
