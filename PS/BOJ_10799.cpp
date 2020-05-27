#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cnt = 0;
	int sum = 0;
	string s;

	std::cin >> s;
	string::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if (*it == '(') {
			if (*(it + 1) == '(') cnt++;
			if (*(it + 1) == ')') {
				sum += cnt;
				it++;
			}
		}
		else if (*it == ')') {
			sum++;
			cnt--;
		}
	}
	printf("%d", sum);
	return 0;
}