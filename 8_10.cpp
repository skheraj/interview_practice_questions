#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class circular_queue {
	size_t begin, end, size;
	vector<T> vals;
	public:
		circular_queue(size_t n) {
			vals = vector<T>(n);
			begin = -1, end = -1, size = 0;
		}

		size_t get_size() {
			return size;
		}

		void enqueue(T val) {
			size++;
			if (size > vals.size())
				vals.resize(size);
			end = (end+1) % vals.size();
			if (begin == -1) begin++;
			vals[end] = val;
		}

		T dequeue() {
            if (size > 0) {
			    size--;
			    T res = vals[begin];
			    begin = (begin+1) % vals.size();
			    return res;
            }
            throw length_error("queue is empty!");
		}
};

int main() {
	auto q = make_shared<circular_queue<int>>(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);
    
    while (q->get_size() > 0) {
        cout << q->dequeue() << endl;
    }
	
	return 0;
}
