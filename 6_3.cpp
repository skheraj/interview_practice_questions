#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_diff(const vector<int> &A) {
	int _min = A[0], _max = A[0], diff = 0;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] < _min) {
			_min = A[i];
			_max = A[i];
		} else if (A[i] > _max) {
			_max = A[i];
			int tmp_diff = _max - _min;
			diff = max(diff, tmp_diff);
		}
	}
	return diff;
}

int max_diff2(const vector<int> &A) {
	int _min = numeric_limits<int>::max(), res = 0;

	for (int x : A) {
		res = max(res, x - _min);
		_min = min(_min, x);
	}

	return res;
}

int main() {
	vector<int> array {3, 2, 4, 8, 1, 5, 10, 4};
	cout << max_diff2(array) << endl;
	return 0;
}
