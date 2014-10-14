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
shared_ptr<node_t<T>> merge(shared_ptr<node_t<T>> L, shared_ptr<node_t<T>> F) {
	shared_ptr<node_t<T>> M;
	
	if (L->data < F->data) {
		M = L;
		L = L->next;
	} else {
		M = F;
		F = F->next;
	}
	
	auto iter = M;

	while (L && F) {
		if (L->data < F->data) {
			iter->next = L;
			iter = iter->next;
			L = L->next;
		} else {
			iter->next = F;
			iter = iter->next;
			F = F->next;
		}
	}

	if (L) iter->next = L;
	if (F) iter->next = F;

	return M;
}

int main() {
	auto L = make_shared<node_t<int>>(2);
	L->next = make_shared<node_t<int>>(5);
	L->next->next = make_shared<node_t<int>>(7);

	auto F = make_shared<node_t<int>>(3);
	F->next = make_shared<node_t<int>>(11);

	auto res = merge(L, F);
	while (res) {
		cout << res->data << endl;
		res = res->next;
	}	

	return 0;
}	
