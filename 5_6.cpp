#include <iostream>
#include <string>

using namespace std;

string intToString(int x) {
	string res = "";
	while (x) {
		int d = x % 10;
		res.insert(res.begin(), '0' + d);
		x /= 10;
	}
	return res;
}

int stringToInt(string s) {
	int len = s.size(), res = 0, b = 1;

	for(int i = len-1; i >= 0; i--) {
		int d = s[i] - '0';
		res += d*b;
		b *= 10;
	}

	return res;
}

int main() {
	cout << intToString(4215583) << endl;
	cout << stringToInt("4215583") << endl;
	return 0;
}
