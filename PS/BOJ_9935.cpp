#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	string s;
	vector<char> stack;

	cin >> str;
	cin >> s;

	int i;
	string::iterator it;
	for (it = str.begin(); it != str.end(); it++) {
		
		stack.push_back(*it);

		
		bool flag = 1;

		if (stack.size() >= s.size()) {
			string::reverse_iterator rs = s.rbegin();
			vector<char>::reverse_iterator rstack = stack.rbegin();

			while (rs != s.rend()) {
				if (*rstack != *rs) {
					flag = 0;
					break;
				}
				rs++;
				rstack++;
			}


			if (flag) {
				for (i = 0; i < s.size(); i++) {
					stack.pop_back();
				}
			}
		}
		
	}

	if (stack.empty()) {
		printf("FRULA");
		return 0;
	}

	vector<char>::iterator vit;
	for (vit = stack.begin(); vit != stack.end(); vit++) {
		printf("%c", *vit);
	}

	return 0;
}