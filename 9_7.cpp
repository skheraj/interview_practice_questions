#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class BST {
	public:
		T data;
        int children;
		shared_ptr<BST<T>> left, right, parent;
		BST() {children = -1;}
		BST(T val) {data = val; children = -1;}
};

template <typename T>
shared_ptr<BST<T>> make_tree(vector<T> A, vector<T> B) {
    if (A.size() == 0)
        return NULL;
    
    if (A.size() == 1)
        return make_shared<BST<T>>(A[0]);
    
    T first = B[B.size()-1];
    
    int i = 0;
    vector<T> C, D, E, F;
    while (A[i] != first) {
        i++;
    }
    
    C.insert(C.end(), A.begin(), A.begin()+i);
    D.insert(D.end(), A.begin()+i+1, A.end());
    
    E.insert(E.end(), B.begin(), B.begin()+i);
    F.insert(F.end(), B.begin()+i, B.end()-1);
    
    auto res = make_shared<BST<T>>(first);
    res->left = make_tree(C, E);
    res->right = make_tree(D, F);
    
    return res;
}

template <typename T>
void print_in_order(shared_ptr<BST<T>> n) {
    if (n) {
        print_in_order(n->left);
        cout << n->data << endl;
        print_in_order(n->right);
    }
}

int main() {
    vector<char> in {'F', 'B', 'A', 'E', 'H', 'C', 'D', 'I', 'G'};
    vector<char> post {'F', 'A', 'E', 'B', 'I', 'G', 'D', 'C', 'H'};
    auto res = make_tree(in, post);
    
    print_in_order(res);
    
    return 0;
}



