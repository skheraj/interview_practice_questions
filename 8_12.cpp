#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class two_stack_queue {
	stack<T> first, second;
	public:
		void enqueue(T val) {
			first.push(val);
		}

		T dequeue() {
			if (second.size() == 0 && first.size() > 0)
				empty_first();
			T res = second.top();
			second.pop();
			return res;
		}

		void empty_first() {
			if (first.size() > 0) {
				while (first.size() > 0) {
					second.push(first.top());
					first.pop();
				}
			} else {
				throw length_error("Queue is empty!");
			}
		}

		size_t get_size() {
			return first.size() + second.size();
		}
};

int main() {
	auto q = make_shared<two_stack_queue<int>>();
	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	q->enqueue(4);
	q->enqueue(5);

	while (q->get_size() > 0) {
		cout << q->dequeue() << endl; 
	}

	return 0;
}
