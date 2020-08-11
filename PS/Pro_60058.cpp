#include <string>
#include <vector>
#include <iostream>
using namespace std;

string SSS;

void q(string p) {
	int cnt1 = 0, cnt2 = 0;
	int chvps = 0;
	bool isvps = true;
	string u = "";
	for (int k = 0; k < p.length(); k++) {
		if (p[k] == '(') {
			cnt1++; chvps++;
		}
		if (p[k] == ')') {
			cnt2++; chvps--;
		}

		if (chvps < 0) isvps = false;
		u += p[k];

		if (cnt1 == cnt2) {
			if (isvps) {
				SSS += u;
				q(p.substr(k + 1));
			}
			else {
				SSS += '(';
				q(p.substr(k + 1));
				SSS += ')';
				for (int l = 1; l < u.length() - 1; l++) {
					if (u[l] == '(') SSS += ')';
					if (u[l] == ')') SSS += '(';
				}
			}
			return;
		}
	}
}
string solution(string p) {
	string answer = "";

	q(p);

	return answer = SSS;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string str;
	cin >> str;

	cout << solution(str);
	return 0;
}