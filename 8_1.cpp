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

		int peek(T &val) {
			if (head) {
				val = head->data;
				return 0;
			} else {
				return 1;
			}
		}
};

template <typename T>
class max_stack : public stack_ll<T> {
	stack_ll<T> max_vals = stack_ll<T>();
	public:
		max_stack() : stack_ll<T>() {}
		
        int get_max(T &val) {
            int max;
            int res = max_vals.peek(max);
            if (res == 0) {
                val = max;
                return 0;
            } else {
                return 1;
            }
        }
        
		void push(T val) {
			int max;
			int res = max_vals.peek(max);
			if (res == 1 || val >= max)
				max_vals.push(val);
            stack_ll<T>::push(val);
		}

		int pop(T &val) {
			int max, tmp;
            int res = max_vals.peek(max);
            if (res == 0 && val == max) {
                max_vals.pop(tmp);
            }
            stack_ll<T>::pop(tmp);
		}
};

int main() {
    auto s = make_shared<max_stack<int>>();
    s->push(4);
    s->push(12);
    s->push(5);
    s->push(14);
    s->push(1);
    s->push(9);
    s->push(7);
    
    int max, res;
    res = s->get_max(max);
    if (!res)
        cout << max << endl;
    
	return 0;
}










			
