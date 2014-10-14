#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class node_t {
        public:
                T data;
                shared_ptr<node_t<T>> next;
                node_t() {}
                node_t(T val) {data = val;}
};

template <typename T>
shared_ptr<node_t<T>> find_cycle(shared_ptr<node_t<T>> head) {
	auto slow = head, fast = head;
	
	do {
		if (!fast->next || !fast->next->next)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	int size = 1;
	slow = slow->next;
	while (slow != fast) {
		size++;
		slow = slow->next;
	}

	slow = head, fast = head;
	while (size > 0) {
		fast = fast->next;
		size--;
	}

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main() {
	auto head = make_shared<node_t<int>> (7);
	head->next = make_shared<node_t<int>> (3);
	head->next->next = make_shared<node_t<int>> (12);
	head->next->next->next = make_shared<node_t<int>> (5);
	head->next->next->next->next = make_shared<node_t<int>> (8);
	head->next->next->next->next->next = make_shared<node_t<int>> (1);
	head->next->next->next->next->next->next = head->next->next;

	auto res = find_cycle(head);
	cout << res->data << endl;

	return 0;
}
