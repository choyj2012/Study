#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int answer = -(1 << 31);
string str;
vector<int> cal;

int op(int a, char op, int b) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int calculation() {

	int ans = cal[0];

	for (int i = 1; i < cal.size(); i+=2) {
		ans = op(ans, cal[i], cal[i + 1]);
	}
	return ans;
}
void q(int idx, bool pre) {

	if (idx == N) {
		int t = calculation();
		answer = answer < t ? t : answer;
		return;
	}

	if (!pre) { //마지막에 괄호 안쳤었으면
		cal.push_back(str[idx]);
		cal.push_back(str[idx + 1] - '0');
		q(idx + 2, false);
		cal.pop_back();
		cal.pop_back();
		cal.back() = op(cal.back(), str[idx], str[idx + 1] - '0');
		q(idx + 2, true);
	}
	else {
		cal.push_back(str[idx]);
		cal.push_back(str[idx + 1] - '0');
		q(idx + 2, false);
		cal.pop_back();
		cal.pop_back();
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	cin >> str;

	
	cal.push_back(str[0] - '0');
	q(1, false);

	printf("%d", answer);
	return 0;
}