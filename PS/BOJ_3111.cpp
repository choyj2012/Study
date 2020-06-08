#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str, word;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> word;
	cin >> str;

	int wlen = word.size();
	int slen = str.size();
	int start = 0;
	int end = slen - 1;
	int i, j;
	bool flag1 = true, flag2 = true;

	while (1) {
		flag1 = 1;
		flag2 = 1;

		for (i = start; i <= slen; i++) {
			if (word == str.substr(i, wlen)) {
				str.erase(i, wlen);
				flag1 = false;
				slen = str.size();
				if (i - wlen - wlen < 0) start = 0;
				else start = i - wlen - wlen;

				if (end > slen) end = slen;
				
				break;
			}
		}

		if (flag1) break;

		for (j = end; j >= 0; j--) {
			if (word == str.substr(j, wlen)) {
				str.erase(j, wlen);
				slen = str.size();
				end = j;
				flag2 = false;

				break;
			}
		}

		if (flag2) break;
	}

	cout << str << endl;
	return 0;
}