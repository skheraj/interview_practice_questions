#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<string> add_num(vector<string> sol, vector<char> new_num) {
	vector<string> res;

	for (string s : sol) {
		for (char c : new_num) {
			string tmp = s;
			tmp.insert(tmp.end(), c);
			res.push_back(tmp);
		}
	}

	return res;
}

vector<string> get_all_seq(map<char, vector<char>> key_map, string seq) {
	if (seq.empty()) {
		return vector<string> {""};
	} else {
		string s = seq.substr(0, seq.size()-1);
		char c = seq[seq.size()-1];
		auto tmp = get_all_seq(key_map, s);
		return add_num(tmp, key_map[c]);
	}
	return vector<string>();
}

int main() {
	map<char, vector<char>> key_map;
	key_map['0'] = vector<char> {' '};
	key_map['1'] = vector<char> {' '};
	key_map['2'] = vector<char> {'a', 'b', 'c'};
        key_map['3'] = vector<char> {'d', 'e', 'f'};
	key_map['4'] = vector<char> {'g', 'h', 'i'};
	key_map['5'] = vector<char> {'j', 'k', 'l'};
	key_map['6'] = vector<char> {'m', 'n', 'o'};
	key_map['7'] = vector<char> {'p', 'q', 'r', 's'};
	key_map['8'] = vector<char> {'t', 'u', 'v'};	
	key_map['9'] = vector<char> {'w', 'x', 'y', 'z'};

	vector<string> res = get_all_seq(key_map, "234");

	for (string s : res)
		cout << s << endl;

	return 0;
}
