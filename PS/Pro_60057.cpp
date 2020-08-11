/*
*	https://programmers.co.kr/learn/courses/30/lessons/60057
*	문자열 압축
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
	int len = s.length();
	int answer = len;

	for (int i = 1; i <= len / 2; i++) {
		
		int tmplen = i;
		string comp = s.substr(0, i);
		int rep = 1;
		for (int k = i; k < len; k += i) {
			string sub = s.substr(k, i);
			if (sub.length() < i) {
				tmplen += sub.length();
				break;
			}
			if (sub == comp) {
				rep++;
			}
			else {
				tmplen += i;
				if (rep > 1) {
					while (rep) {
						rep /= 10;
						tmplen++;
					}
				}
				rep = 1;
				comp = sub;
			}
		}
		if (rep > 1) {
			while (rep) {
				rep /= 10;
				tmplen++;
			}
		}
		answer = min(answer, tmplen);
	}



	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T = 5;
	while (T--) {
		string str;
		cin >> str;
		cout << solution(str) << endl;
	}
	return 0;
}