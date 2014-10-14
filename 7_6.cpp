#include <iostream>
#include <vector>
#include <memory>

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
void even_odd(shared_ptr<node_t<T>> head) {
	shared_ptr<node_t<T>> odd_start;
	if (head && head->next) {
		odd_start = head->next;
	} else {
		return;
	}

	auto n = head;
	int i = 0;
	while (n->next->next) {
		auto tmp = n->next;
		n->next = n->next->next;
		n = tmp;
		i++;
	}

	if (i % 2 == 0) {
		n->next = odd_start;
		return;
	} else {
		auto tmp = n->next;
		n->next = nullptr;
		tmp->next = odd_start;
		return;
	}

	return;
}

int main() {
	auto head = make_shared<node_t<int>>(2);
	head->next = make_shared<node_t<int>>(3);
	head->next->next = make_shared<node_t<int>>(4);
	head->next->next->next = make_shared<node_t<int>>(5);
	head->next->next->next->next = make_shared<node_t<int>>(6);
	head->next->next->next->next->next = make_shared<node_t<int>>(7);
	head->next->next->next->next->next->next = make_shared<node_t<int>>(8);

	even_odd(head);
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}

	return 0;
}




