#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<vector<char>> strcheck;

void sol(vector<char> stack, vector<int> check, int cnt);
void Print(vector<char>);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	vector<char> v;
	vector<int> ch;
	cin >> str;
	sol(v, ch, 0);

	sort(strcheck.begin(), strcheck.end());
	vector<vector<char>>::iterator itor = strcheck.begin();
	vector<char>::iterator itor2;
	for (itor = strcheck.begin(); itor != strcheck.end(); itor++) {
		for (itor2 = itor->begin(); itor2 != itor->end(); itor2++) {
			cout << *itor2;
		}
		cout << "\n";
	}
	return 0;
}

void sol(vector<char> stack, vector<int> check, int idx) {

	if (idx == str.size()) {
		Print(stack);
		return;
	}
	char t = str[idx];

	if (t == '(') {
		//제거안할 경우
		stack.push_back(t);
		check.push_back(1);		// 1 => 제거하지 않은 괄호
		sol(stack, check, idx + 1);

		//제거할 경우
		stack.pop_back();
		check.pop_back();
		check.push_back(-1);	// -1 => 제거된 괄호
		sol(stack, check, idx + 1);
	}
	else if (t == ')') {
		if (check.back() == 1) {		//괄호 쌍이 남아있는경우
			check.pop_back();
			stack.push_back(t);
			sol(stack, check, idx + 1);
		}
		else if (check.back() == -1) {	//괄호 쌍이 제거된경우
			check.pop_back();
			sol(stack, check, idx + 1);
		}
	}
	else {
		stack.push_back(t);
		sol(stack, check, idx + 1);
	}
}

void Print(vector<char> stack) {
	if (stack.size() == str.size()) return;	//한개도 제거안된경우 출력안함

	vector<vector<char>>::iterator iit;	//중복검사
	for (iit = strcheck.begin(); iit != strcheck.end(); iit++) {
		if (stack == *iit) {
			return;
		}
	}
	strcheck.push_back(stack);
/*	여기서 바로출력하지 않고 strcheck에 다 담아 놓고 마지막에 정렬해서 출력
	vector<char>::iterator it;	//출력
	for (it = stack.begin(); it != stack.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");
	*/
}