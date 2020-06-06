#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, str;
	cin >> s;
	cin >> str;
	int lens = s.size();
	bool flag = 0;
	while (1) {

		string::iterator it;
		for (it = str.begin(); !flag && it != str.end(); it++) {
			string::iterator sit = s.begin();
			string::iterator strit = it;
			while (strit != str.end() && *sit == *strit) {
				sit++;
				strit++;

				if (sit == s.end()) {	//지울거있음
					str.erase(it, strit);
					flag = true;
					break;
				}
			}
			
		}

		if (!flag) break;
		flag = false;

		string::reverse_iterator rit;
		for (rit = str.rbegin(); !flag && rit != str.rend(); rit++) {
			string::reverse_iterator rsit = s.rbegin();
			string::reverse_iterator rstrit = rit;
			while (rstrit!=str.rend() && *rsit == *rstrit) {
				rsit++;
				rstrit++;

				if (rsit == s.rend()) {
					str.erase(rstrit.base(), rit.base());
					flag = true;
					break;
				}
			}
		}

		if (!flag)break;
		flag = false;
	}
	cout << str << endl;
	return 0;
}