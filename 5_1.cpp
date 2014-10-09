#include <iostream>
#include <cmath>

using namespace std;

uint8_t p[65536];

uint8_t parity_16(uint16_t x) {
	uint8_t parity = 0;
	while (x) {
		x &= (x-1);
		parity ^= 1;
	}
	return parity;
}

void generate_parity_table() {
        for (int i = 0; i < 65536; i++) {
                p[i] = parity_16(i);
	}
}

uint8_t parity_64(uint64_t x) {
	uint16_t a = x >> 48;
	uint16_t b = 0xffff & (x >> 32);
	uint16_t c = 0xffff & (x >> 16);
	uint16_t d = 0xffff & x;

	return p[a] ^ p[b] ^ p[c] ^ p[d];
}

int main() {
	generate_parity_table();
	uint64_t x = 123515;
	cout << int(parity_64(x)) << endl;

	return 0;
}	
