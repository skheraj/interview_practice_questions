#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_power_set(const vector<int> &A) {
	int n = A.size();
	for (int i = 0; i <= pow(2,4)-1; i++) {
		int x = i;
		for (int j = 0; j < n; j++) {
			if (x & 1)
				cout << A[j];
			x >>= 1;
		}
		cout << endl;
	}
}

int main() {
	vector<int> A {1, 2, 3, 4};
	print_power_set(A);
	return 0;
}
