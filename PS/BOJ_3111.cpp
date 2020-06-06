#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str, tar;
	cin >> tar;
	cin >> str;
	string answer = str;

	string::iterator it = str.begin();
	string::reverse_iterator rit = str.rbegin();

	vector<char> stack1, stack2;

	int i;
	bool flag = false;

	while (1) {
		
		for (; it != rit.base(); it++) {
			stack1.push_back(*it);

			string::reverse_iterator rit_tar = tar.rbegin();
			vector<char>::reverse_iterator rit_stack = stack1.rbegin();
			while (stack1.size() >= tar.size()) {
				if (rit_tar == tar.rend()) {
					for (i = 1; i <= tar.size(); i++) {
						stack1.pop_back();
					}
					flag = true;
					
					break;
				}
				if (*rit_tar != *rit_stack) break;

				rit_tar++;
				rit_stack++;
			}
		}
		string temp1(it, rit.base());
		answer = temp1;
		if (!flag) break;
		flag = false;

		for (; !flag && rit.base() != it; rit++) {
			stack2.push_back(*rit);

			string::reverse_iterator rit_tar = tar.rbegin();
			vector<char>::reverse_iterator rit_stack = stack2.rbegin();
			while (stack2.size() >= tar.size()) {
				if (rit_tar == tar.rend()) {
					for (i = 1; i <= tar.size(); i++) {
						stack2.pop_back();
					}
					flag = true;
					break;
				}
				if (*rit_tar != *rit_stack) break;

				rit_tar++;
				rit_stack++;
			}
		}
		string temp2(it, rit.base());
		answer = temp2;
		if (!flag)break;
		flag = false;
	}
	
	vector<char>::iterator vi = stack1.begin();
	while (vi != stack1.end()) {
		cout << *vi++;
	}
	cout << answer << endl;
	vi = stack2.begin();
	while (vi != stack2.end()) {
		cout << *vi++;
	}
	return 0;
}

/*
시간초과
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
*/