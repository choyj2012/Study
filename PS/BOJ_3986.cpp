#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i, cnt = 0;
	scanf("%d", &n);
	string str;

	for (i = 1; i <= n; i++) {
		cin >> str;
		vector<char> stack;
		string::iterator it;
		for (it = str.begin(); it != str.end(); it++) {
			if (!stack.empty() && stack.back() == *it) {
				stack.pop_back();
				continue;
			}
			
			stack.push_back(*it);
		}
		if (stack.empty()) cnt++;
	}

	printf("%d", cnt);
	return 0;
}