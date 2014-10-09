#include <iostream>
#include <cinttypes>

using namespace std;

uint64_t swap_bits(int i, int j, uint64_t x) {
	int i_bit = (x >> i) & 1;
	int j_bit = (x >> j) & 1;
	if (i_bit != j_bit) {
		x ^= (1 << i);
		x ^= (1 << j);
	}
	return x;
}

int main() {
	cout << swap_bits(5, 13, 3251234) << endl;
	return 0;
} 
