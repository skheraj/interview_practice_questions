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
void reverse_list(shared_ptr<node_t<T>> &head) {
	if (!head || !head->next)
		return;

	auto n = head->next;
	head->next = nullptr;
	auto prev = head;
	while (n) {
		auto tmp = n->next;
		n->next = prev;
		prev = n;
		n = tmp;
	}

	head = prev;
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

        reverse_list(head);
        while (head) {
                cout << head->data << endl;
                head = head->next;
        }

	return 0;
}
