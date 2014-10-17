#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

size_t Parent(size_t i) {
    return (i-1) / 2;
}

size_t Left(size_t i) {
    return 2*i + 1;
}

size_t Right(size_t i) {
    return 2*i + 2;
}

template <typename T>
void min_heapify(vector<T> &A, size_t i, size_t heap_size) {
    size_t l = Left(i), r = Right(i), smallest;
    
    if (l < heap_size && A[l] < A[i]) {
        smallest = l;
    } else {
        smallest = i;
    }

    if (r < heap_size && A[r] < A[smallest]) {
        smallest = r;
    }
    
    if (smallest != i) {
        swap(A[i], A[smallest]);
        min_heapify(A, smallest, heap_size);
    }
}

template <typename T>
size_t heap_increase_key(vector<T> &A, size_t i, T key) {
    A[i] = key;
    while (i > 0 && A[Parent(i)] > A[i]) {
        swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
    return i;
}

template <typename T>
class min_heap {
        vector<T> vals;
    public:
        size_t heap_size;
        
        bool empty() {
            return heap_size == 0;
        }
        
        size_t length() {
            return vals.size();
        }
        
        T get_min() {return vals[0];}
        
        T extract_min() {
            T min_val = vals[0];
            vals[0] = vals[heap_size-1];
            heap_size--;
            min_heapify(vals, 0, heap_size);
            return min_val;
        }
        
        size_t insert(T key) {
            heap_size++;
            if (heap_size > vals.size())
                vals.resize(heap_size);
            size_t i = heap_increase_key(vals, heap_size-1, key);
            return i;
        }
        
        min_heap() {heap_size = 0;}
        
        min_heap(vector<T> A) {
            heap_size = A.size();
            for (int i = Parent(A.size()-1); i >= 0; i--) {
                min_heapify(A, i, heap_size);
            }
            vals = A;
        }
};

int main() {
    vector<int> vals {4, 8, 9, 2, 5, 1, 12, 7, 3};
    min_heap<int> mh (vals);
    cout << mh.get_min() << endl;
    
    return 0;
}
