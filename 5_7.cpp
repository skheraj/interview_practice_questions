#include <iostream>
#include <string>

using namespace std;

string base_convert(int b1, int b2, string x) {
	int len = x.size(), sum = 0, b = 1;
	
	for (int i = len-1; i >= 0; i--) {
		char c = x[i];
		int d;
		if (c >= 'A') 
			d = 10 + (c - 'A');
		else
			d = c - '0';
		sum += d*b;
		b *= b1;
	}

	string s = "";
	while (sum) {
		int d = sum % b2;
		char c;
		if (d >= 10)
			c = 'A' + d - 10;
		else
			c = '0' + d;
		s.insert(s.begin(), c);
		sum /= b2;
	}

	return s;
}

int main() {
	string res = base_convert(16, 10, "5131AF4C");
	cout << res << endl;
	return 0;
}
