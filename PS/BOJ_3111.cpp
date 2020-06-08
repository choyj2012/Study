#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str, word;
	
	cin >> word;
	int wlen = word.size();

	cin >> str;
	int front = 0;
	int back = str.size() - 1;
	int i;
	bool flag1 = false, flag2 = false;

	while (front<=back) {
		if (str.size() < wlen) break;
		while (front <= back) {
			string part = str.substr(front, wlen);
			if (word == part) {
				string p1 = str.substr(0, front);
				string p2 = str.substr(front + wlen, str.size()-(front+wlen-1));
				str = p1 + p2;
				if (back >= front && back <= front + wlen - 1) {
					back = back - wlen + 1;
				}
				else
					back -= wlen;
				if (front > 0) front--;
				flag1 = 1;
				break;
			}
			front++;
		}
		if (str.size() < wlen) break;
		if (!flag1) break;
		while (front <= back) {
			string part = str.substr(back - wlen + 1, wlen);
			if (word == part) {
				string p1 = str.substr(0, back - wlen+1);
				string p2 = str.substr(back + 1, str.size() - back);
				str = p1 + p2;
				if (front >= back - wlen + 1 && front <= back)
					front = back - wlen - wlen;
				if (front < 0) front = 0;
				back = back - wlen + 1;
				flag2 = 1;
				break;
			}
			back--;
		}
		if (!flag2) break;
	}

	cout << str << endl;
	return 0;
}

