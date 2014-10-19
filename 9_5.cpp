#include <iostream>
#include <memory>
#include <cmath>

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
void print_inorder(shared_ptr<BST<T>> n) {
    if (!n) {
        return;
    } else if (n->left) {
        n = n->left;
    } else {
        cout << n->data << endl;
        if (n->right)
            n = n->right;
        else
            return;
    }
    
    while (n->parent) {
        if (n->left) {
            n = n->left;
        } else if (n->right) {
            cout << n->data << endl;
            n = n->right;
        } else {
            cout << n->data << endl;
            while (n->parent && (n->parent->right == n || !n->parent->right)) {
                if (n->parent->left == n)
                    cout << n->parent->data << endl;
                n = n->parent;
            }
            if (!n->parent) {
                return;
            } else {
                cout << n->parent->data << endl;
                n = n->parent->right;
            }
        }
    }
}

int main() {
	auto bst = make_shared<BST<int>>(314);
	bst->left = make_shared<BST<int>>(6);
    bst->left->parent = bst;
	bst->right = make_shared<BST<int>>(6);
    bst->right->parent = bst;
	
	bst->left->left = make_shared<BST<int>>(271);
    bst->left->left->parent = bst->left;
	bst->left->right = make_shared<BST<int>>(561);
    bst->left->right->parent = bst->left;

	bst->left->left->left = make_shared<BST<int>>(28);
    bst->left->left->left->parent = bst->left->left;
	bst->left->left->right = make_shared<BST<int>>(0);
    bst->left->left->right->parent = bst->left->left;

	bst->left->right->right = make_shared<BST<int>>(3);
    bst->left->right->right->parent = bst->left->right;
	bst->left->right->right->left = make_shared<BST<int>>(17);
    bst->left->right->right->left->parent = bst->left->right->right;

	bst->right->left = make_shared<BST<int>>(2);
    bst->right->left->parent = bst->right;
	bst->right->right = make_shared<BST<int>>(271);
    bst->right->right->parent = bst->right;
	bst->right->right->right = make_shared<BST<int>>(28);
	bst->right->right->right->parent = bst->right->right;
    
	bst->right->left->right = make_shared<BST<int>>(1);
    bst->right->left->right->parent =  bst->right->left;
	bst->right->left->right->left = make_shared<BST<int>>(401); 
    bst->right->left->right->left->parent = bst->right->left->right;
	bst->right->left->right->right = make_shared<BST<int>>(257);
    bst->right->left->right->right->parent =  bst->right->left->right;
	bst->right->left->right->left->right = make_shared<BST<int>>(641);
    bst->right->left->right->left->right->parent = bst->right->left->right->left;

    print_inorder(bst);

	return 0;
}
