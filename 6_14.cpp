#include <iostream>
#include <vector>

using namespace std;

bool sudoku_check(const vector<vector<int>> &sol) {
	vector<bool> x (9, false);
	vector<vector<bool>> rows (9,x);
	vector<vector<bool>> cols (9,x);
	vector<vector<bool>> sqrs (9,x);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int res = sol[i][j];
			
			if (res == 0) continue;
	
			if (rows[j][res])
				return false;
			else
				rows[j][res] = true;
			
			if (cols[i][res])
				return false;
			else
				cols[i][res] = true;
			
			if (sqrs[(i/3) + (j/3)*3][res])
				return false;
			else
				sqrs[(i/3) + (j/3)*3][res] = true;
		}
	}

	return true;
} 

int main() {
	vector<int> a {4, 3, 5, 2, 6, 9, 7, 8, 1};
	vector<int> b {6, 8, 2, 5, 7, 1, 4, 9, 3};
	vector<int> c {1, 9, 7, 8, 3, 4, 5, 6, 2};
	vector<int> d {8, 2, 6, 1, 9, 5, 3, 4, 7};
	vector<int> e {3, 7, 4, 6, 8, 2, 9, 1, 5};
	vector<int> f {9, 5, 1, 7, 4, 3, 6, 2, 8};
	vector<int> g {5, 1, 9, 3, 2, 6, 8, 7, 4};
	vector<int> h {2, 4, 8, 9, 5, 7, 1, 3, 6};
	vector<int> i {7, 6, 3, 4, 1, 8, 2, 5, 9};
	
	vector<vector<int>> sol {a, b, c, d, e, f, g, h, i}; 
	cout << sudoku_check(sol) << endl;

	return 0;
}
