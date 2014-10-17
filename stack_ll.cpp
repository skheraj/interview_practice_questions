#include <iostream>
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
class stack_ll {
	shared_ptr<node_t<T>> head;
	public:
		void push(T val) {
			auto n = make_shared<node_t<T>>(val);
			n->next = head;
			head = n;
		}

		int pop(T &val) {
			if (head) {
				val = head->data;
				head = head->next;
				return 0;
			} else {
				return 1;
			}
		}
};

int main() {
	auto s = make_shared<stack_ll<int>>();
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);

	int res;
	do {
		int x;
		res = s->pop(x);
		if (!res)
			cout << x << endl;
	} while (!res);

	return 0;
}	
