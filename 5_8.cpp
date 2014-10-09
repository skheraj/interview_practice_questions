#include <iostream>
#include <string>

using namespace std;

int ssDecodeColID (string s) {
	int len = s.size(), res = 0, b = 1;
	
	for (int i = len-1; i >= 0; i--) {
		int d = s[i] - 'A' + 1;
		res += d*b;
		b *= 26;
	}

	return res;
}

int main() {
	cout << ssDecodeColID("AZC") << endl;
	return 0;
}
