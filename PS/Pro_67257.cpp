/*
*	수식 최대화
*	https://programmers.co.kr/learn/courses/30/lessons/67257
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

char order[][3]{
	{ '+', '-', '*' },
	{ '+', '*', '-' },
	{ '-', '+', '*' },
	{ '-', '*', '+' },
	{ '*', '+', '-' },
	{ '*', '-', '+' }
};


ll test(vector<ll> num, vector<char> oper, int type) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < oper.size(); j++) {
			
			if(oper[j] == order[type][i]) {
				auto delop = oper.begin() + j;
				auto del = num.begin() + j + 1;
				if (order[type][i] == '+')
					num[j] = num[j] + num[j + 1];
				if (order[type][i] == '-')
					num[j] = num[j] - num[j + 1];
				if (order[type][i] == '*')
					num[j] = num[j] * num[j + 1];

				num.erase(del);
				oper.erase(delop);
				j--;
			}
		}
	}

	return num.front();
}

ll solution(string expression) {

	ll answer = 0;
	vector<ll> num;
	vector<char> oper;

	int t = 0;
	for (auto& k : expression) {
		if (k >= '0' && k <= '9') {
			t = t * 10 + k - '0';
		}
		else {
			num.push_back(t);
			oper.push_back(k);
			t = 0;
		}
	}
	num.push_back(t);
	
	for (int i = 0; i < 6; i++) {
		answer = max(answer, abs(test(num, oper, i)));
	}
	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	cin >> str;

	cout << solution(str);
}