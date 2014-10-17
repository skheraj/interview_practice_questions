#include <iostream>
#include <set>

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
class bst_node_t {
    public:
        T data;
        shared_ptr<bst_node_t<T>> left;
        shared_ptr<bst_node_t<T>> right;
        bst_node_t() {}
        bst_node_t(T val) {data = val;}
};

template <typename T>
class stack_ll {
    shared_ptr<node_t<T>> head;
    public:
        bool empty() {
            return head == nullptr;
        }
        
        void push(T val) {
            auto n = make_shared<node_t<T>>(val);
            n->next = head;
            head = n;
        }

        T pop() {
            T res = head->data;
            head = head->next;
            return res;
        }

        T peek() {
            return head->data;
        }
};

template <typename T>
void print_bst_keys(shared_ptr<bst_node_t<T>> root) {
    set<shared_ptr<bst_node_t<T>>> to_inspect {root};
    auto final = make_shared<stack_ll<T>>();
    auto tmp = make_shared<stack_ll<T>>();
    
    while (!to_inspect.empty()) {
        auto n = *(to_inspect.begin());
        
        while(!final->empty() && final->peek() != n->data) {
            tmp->push(final->pop());
        }
        
        if (!final->empty()) final->pop();
        
        if (n->right) {
            final->push(n->right->data);
            to_inspect.insert(n->right);
        }
                
        final->push(n->data);
        
        if (n->left) {
            final->push(n->left->data);
            to_inspect.insert(n->left);
        }
                
        while (!tmp->empty()) {
            final->push(tmp->pop());
        }
        
        to_inspect.erase(to_inspect.begin());
    }
    
    while (!final->empty()) {
        cout << final->pop() << endl;
    }
}

template <typename T>
void print_bst_keys2(shared_ptr<bst_node_t<T>> root) { 
    auto curr = root;
    stack_ll<shared_ptr<bst_node_t<T>>> s;
    
    while (!s.empty() || curr) {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.pop();
            cout << curr->data << endl;
            curr = curr->right;
        }
    }
}

int main() {
    auto root = make_shared<bst_node_t<int>>(12);
    
    root->left = make_shared<bst_node_t<int>>(8);
    root->left->left = make_shared<bst_node_t<int>>(4);
    root->left->right = make_shared<bst_node_t<int>>(9);
    
    root->right = make_shared<bst_node_t<int>>(15);
    root->right->left = make_shared<bst_node_t<int>>(13);
    root->right->right = make_shared<bst_node_t<int>>(18);
    
    root->right->right->left = make_shared<bst_node_t<int>>(16);
    root->right->right->right = make_shared<bst_node_t<int>>(20);
    
    print_bst_keys2(root);
    
    return 0;
}