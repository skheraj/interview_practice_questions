#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

template <typename T>
class BST {
	public:
		T data;
        int children;
		shared_ptr<BST<T>> left, right;
		BST() {children = -1;}
		BST(T val) {data = val; children = -1;}
};

template <typename T>
int num_children(shared_ptr<BST<T>> root) {
	if (!root) {
		return 0;
	} else {
        if (root->children == -1)
            root->children = num_children(root->left) + num_children(root->right) + 1;
        return root->children;
	}
}

template <typename T>
bool is_k_balanced(shared_ptr<BST<T>> root, int k) {
	if (!root)
		return true;
	int l = num_children(root->left);
	int r = num_children(root->right);
    
	return abs(l-r) <= k;
}

template <typename T>
shared_ptr<BST<T>> find_u(shared_ptr<BST<T>> root, int k) {
	if (!root) {
		return NULL;
	} else {
		if (!is_k_balanced(root, k) && 
			is_k_balanced(root->left, k) && 
			is_k_balanced(root->right, k)) {
			return root;
		} else {
			auto resl = find_u(root->left, k); 
		    if (resl) return resl;
			auto resr = find_u(root->right, k);
			if (resr) return resr;
			return NULL;
		}
	}
}

int main() {
	auto bst = make_shared<BST<int>>(314);
	bst->left = make_shared<BST<int>>(6);
	bst->right = make_shared<BST<int>>(6);
	
	bst->left->left = make_shared<BST<int>>(271);
	bst->left->right = make_shared<BST<int>>(561);

	bst->left->left->left = make_shared<BST<int>>(28);
	bst->left->left->right = make_shared<BST<int>>(0);

	bst->left->right->right = make_shared<BST<int>>(3);
	bst->left->right->right->left = make_shared<BST<int>>(17);

	bst->right->left = make_shared<BST<int>>(2);
	bst->right->right = make_shared<BST<int>>(271);
	bst->right->right->right = make_shared<BST<int>>(28);
	
	bst->right->left->right = make_shared<BST<int>>(1);
	bst->right->left->right->left = make_shared<BST<int>>(401); 
	bst->right->left->right->right = make_shared<BST<int>>(257);
	bst->right->left->right->left->right = make_shared<BST<int>>(641);

	auto res = find_u(bst, 3);		
    
    cout << res->data << endl;

	return 0;
}





