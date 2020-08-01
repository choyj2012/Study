/*
*	https://programmers.co.kr/learn/courses/30/lessons/1835
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> Data;
string Fr = "ACFJMNRT";
int answer = 0;

int solution(int n, vector<string> Data);
void check_data();

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		Data.push_back(str);
	}
	solution(n, Data);
	printf("%d", answer);
}

int solution(int n, vector<string> Data) {
	int answer = 0;
	
	do {
		check_data();
	} while (next_permutation(Fr.begin(), Fr.end()));

	return answer;
}

void check_data() {

	for (int i = 0; i < Data.size(); i++) {
		
		auto a = find(Fr.begin(), Fr.end(), Data[i][0]);
		auto b = find(Fr.begin(), Fr.end(), Data[i][2]);

		char op = Data[i][3];
		int c = Data[i][4] - '0';
		int gap = abs(distance(a, b)) - 1;

		if (op == '>'&& gap <= c) return;
		if (op == '<' && gap >= c) return;

		if (op == '=' &&  gap != c) return;
	}
	answer++;
}