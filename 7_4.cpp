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
shared_ptr<node_t<T>> find_overlap(shared_ptr<node_t<T>> L1, shared_ptr<node_t<T>> L2) {
	auto r1 = L1, r2 = L2;
	
	while (r1->next && r2->next) {
		r1 = r1->next;
		r2 = r2->next;
	}

	int size = 0;
	if (r1->next) {
		while (r1 != r2) {
			r1 = r1->next;
			size++;
		}
		r1 = L1, r2 = L2;
		while (size > 0) {
			r1 = r1->next;
			size--;
		}
	} else if (r2->next) {
		while (r1 != r2) {
                        r2 = r2->next;
                        size++;
                }
                r1 = L1, r2 = L2;
                while (size > 0) {
                        r2 = r2->next;
                        size--;
                }
	} else {
		r1 = L1, r2 = L2;
	}

	while (r1 != r2) {
		r1 = r1->next;
		r2 = r2->next;
	}

	return r1;
}

int main() {
	auto L2 = make_shared<node_t<int>>(12);
        L2->next = make_shared<node_t<int>>(4);
        L2->next->next = make_shared<node_t<int>>(8);
        L2->next->next->next = make_shared<node_t<int>>(2);
        L2->next->next->next->next = make_shared<node_t<int>>(7);
        L2->next->next->next->next->next = make_shared<node_t<int>>(17);

	auto L1 = make_shared<node_t<int>>(5);
	L1->next = make_shared<node_t<int>>(3);
	L1->next->next = L2->next->next->next->next;	

	auto res = find_overlap(L1, L2);

	cout << res->data << endl;

	return 0;
}






