#include <iostream>
#include <set>
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
class bst_node_t {
    public:
        T data;
        shared_ptr<bst_node_t<T>> left;
        shared_ptr<bst_node_t<T>> right;
        bst_node_t() {}
        bst_node_t(T val) {data = val;}
};

template <typename T>
class queue_ll {
    shared_ptr<node_t<T>> head;
    shared_ptr<node_t<T>> tail;
    public:
        bool empty() {
            return head == nullptr;
        }

        void enqueue(T val) {
            auto n = make_shared<node_t<T>>(val);
            if (!tail) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
        }

        T dequeue() {
            T res = head->data;
            head = head->next;
            return res;
        }       

        T peek() {
            return head->data;
        }
};

template <typename T>
void print_level_order(shared_ptr<bst_node_t<T>> head) {
    vector<shared_ptr<bst_node_t<T>>> to_check {head};
    queue_ll<T> keys;
    
    while(!to_check.empty()) {
        vector<shared_ptr<bst_node_t<T>>> tmp;
        for (auto n : to_check) {
            keys.enqueue(n->data);
            if (n->left) tmp.push_back(n->left);
            if (n->right) tmp.push_back(n->right);
        }
        to_check = tmp;
    }
    
    while (!keys.empty())
        cout << keys.dequeue() << endl;
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
    
    print_level_order(root);
    
    return 0;
} 