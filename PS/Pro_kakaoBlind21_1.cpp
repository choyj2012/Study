#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i <= new_id.length(); i++) {
		if (new_id[i] >= 65 && new_id[i] <= 90)
			new_id[i] += 32;
	}

	string temp1 = "";
	for (auto k : new_id) {
		if ((k >= '0' && k <= '9') || k == '-' || k == '_' || k == '.' ||
			(k >= 97 && k <= 122)) {
			temp1.push_back(k);
		}
	}

	string temp2 = "";
	for (auto k : temp1) {
		if (temp2.empty()) temp2.push_back(k);

		else if(k == '.' && temp2.back() == '.')
			continue;
		else temp2.push_back(k);
	}

	if (temp2[0] == '.') temp2 = temp2.substr(1, temp2.length() - 1);
	if (temp2.back() == '.') temp2.pop_back();
	if (temp2.empty()) temp2.push_back('a');

	if (temp2.length() >= 16) temp2 = temp2.substr(0, 15);

	if(!temp2.empty() && temp2.back() == '.') temp2.pop_back();

	if (temp2.length() <= 2) {
		while (temp2.length() < 3) {
			temp2.push_back(temp2.back());
		}
	}
	return answer = temp2;
}

int main() {
	freopen("input.txt", "r", stdin);

	string str;
	cin >> str;
	cout << solution(str);
	return 0;
}