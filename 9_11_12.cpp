#include <iostream>
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
shared_ptr<BST<T>> LCA(shared_ptr<BST<T>> root, shared_ptr<BST<T>> A, shared_ptr<BST<T>> B) {
    if (!root)
        return NULL;
    
    if (root == A || root == B) {
        return root;
    } else {
        auto l_res = LCA(root->left, A, B);
        auto r_res = LCA(root->right, A, B);
        if (l_res && r_res) {
            cout << root->data << endl;
            return root;
        } else if (l_res) {
            return l_res;
        } else {
            return r_res;
        }
    }
    
    return NULL;
}

template <typename T>
shared_ptr<BST<T>> LCA2(shared_ptr<BST<T>> root, shared_ptr<BST<T>> A, shared_ptr<BST<T>> B) {
    auto tmp_A = A, tmp_B = B;
    
    while (tmp_A->parent && tmp_B->parent) {
        tmp_A = tmp_A->parent;
        tmp_B = tmp_B->parent;
    }
    
    while (tmp_A->parent) {
        tmp_A = tmp_A->parent;
        A = A->parent;
    }
 
    while (tmp_B->parent) {
        tmp_B = tmp_B->parent;
        B = B->parent;
    }
    
    while (A != B) {
        A = A->parent;
        B = B->parent;
    }
    
    return A;
}

int main() {
	auto bst = make_shared<BST<char>>('A');
	bst->left = make_shared<BST<char>>('B');
    bst->left->parent = bst;
	bst->right = make_shared<BST<char>>('I');
    bst->right->parent = bst;
	
	bst->left->left = make_shared<BST<char>>('C');
    bst->left->left->parent = bst->left;
	bst->left->right = make_shared<BST<char>>('F');
    bst->left->right->parent = bst->left;

	bst->left->left->left = make_shared<BST<char>>('D');
    bst->left->left->left->parent = bst->left->left;
	bst->left->left->right = make_shared<BST<char>>('E');
    bst->left->left->right->parent = bst->left->left;

	bst->left->right->right = make_shared<BST<char>>('G');
    bst->left->right->right->parent = bst->left->right;
	bst->left->right->right->left = make_shared<BST<char>>('H');
    bst->left->right->right->left->parent = bst->left->right->right;

	bst->right->left = make_shared<BST<char>>('J');
    bst->right->left->parent = bst->right;
	bst->right->right = make_shared<BST<char>>('O');
    bst->right->right->parent = bst->right;
	bst->right->right->right = make_shared<BST<char>>('P');
	bst->right->right->right->parent = bst->right->right;
    
	bst->right->left->right = make_shared<BST<char>>('K');
    bst->right->left->right->parent =  bst->right->left;
	bst->right->left->right->left = make_shared<BST<char>>('L'); 
    bst->right->left->right->left->parent = bst->right->left->right;
	bst->right->left->right->right = make_shared<BST<char>>('N');
    bst->right->left->right->right->parent =  bst->right->left->right;
	bst->right->left->right->left->right = make_shared<BST<char>>('M');
    bst->right->left->right->left->right->parent = bst->right->left->right->left;
    
    auto res = LCA2(bst, bst->right->left->right->left->right, bst->right->right->right);
    cout << res->data << endl;
}