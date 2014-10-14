#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dutch_partition(vector<int> &A, int i) {
	int x = A[i], p = -1, q = -1, r = -1, n = A.size();

	for (int j = 0; j < n; j++) {
		if (A[j] < x) {
			p++;
			if (q != -1 && p == q) {
				swap(A[q], A[r+1]);
				q++, r++;
			}
		
			if (r != j)
				swap(A[p], A[j]);
		} else if (A[j] == x) {
			if (q == -1) {
				q = p+1, r = p+1;
			} else {
				r++;
			}

			swap(A[r], A[j]);
		}
	}
}

int main() {
	vector<int> array {27, 17, 11, 10, 21, 16, 18, 10, 23, 2, 6, 28, 10, 25, 29, 20, 10, 5, 21, 10, 20, 12, 10, 24, 10, 1, 9};
	dutch_partition(array, 3);
	for (int i : array)
		cout << i << endl;
	return 0;
}

	
