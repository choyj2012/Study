#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

struct person {
	string lang;
	string depart;
	string career;
	string food;
	string score;
};
vector<person> DATA;

vector<int> type[3][2][2][2];
void add(vector<string> tok, int idx) {
	int a1, a2, a3, a4;
	if (tok[0] == "java") a1 = 0;
	else if (tok[0] == "cpp") a1 = 1;
	else if (tok[0] == "python") a1 = 2;

	if (tok[1] == "backend") a2 = 0;
	else if (tok[1] == "frontend") a2 = 1;

	if (tok[2] == "junior") a3 = 0;
	else if (tok[2] == "senior") a3 = 1;

	if (tok[3] == "chicken") a4 = 0;
	else if (tok[3] == "pizza") a4 = 1;

	type[a1][a2][a3][a4].push_back(stoi(tok[4]));
}

int QQ(vector<string> tok) {//0, 2, 4, 6, 7

	int a1, a2, a3, a4;
	if (tok[0] == "java") a1 = 0;
	else if (tok[0] == "cpp") a1 = 1;
	else if (tok[0] == "python") a1 = 2;
	else if (tok[0] == "-") a1 = -1;

	if (tok[2] == "backend") a2 = 0;
	else if (tok[2] == "frontend") a2 = 1;
	else if (tok[2] == "-") a2 = -1;

	if (tok[4] == "junior") a3 = 0;
	else if (tok[4] == "senior") a3 = 1;
	else if (tok[4] == "-") a3 = -1;

	if (tok[6] == "chicken") a4 = 0;
	else if (tok[6] == "pizza") a4 = 1;
	else if (tok[6] == "-") a4 = -1;

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (a1 == -1 || a1 == i)
		{
			for (int j = 0; j < 2; j++) {
				if (a2 == -1 || a2 == j)
				{
					for (int k = 0; k < 2; k++) {
						if (a3 == -1 || a3 == k)
						{
							for (int l = 0; l < 2; l++) {
								if (a4 == -1 || a4 == l) {
									auto cut = lower_bound(type[i][j][k][l].begin(), type[i][j][k][l].end(), stoi(tok[7])) - type[i][j][k][l].begin();
									ans += (type[i][j][k][l].size() - cut);
								}
							}
						}
					}
				}
			}
		}
	}

	return ans;
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	int idx = 0;
	for (auto inf : info) {
		string buf;
		stringstream ss(inf);
		vector<string> tok;

		while (ss >> buf) {
			tok.push_back(buf);
		}
		
		add(tok, idx++);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					sort(type[i][j][k][l].begin(), type[i][j][k][l].end());
				}
			}
		}
	}

	for (auto q : query) {
		string buf;
		stringstream ss(q);
		vector<string> tok;
		while (ss >> buf) {
			tok.push_back(buf);
		}

		answer.push_back(QQ(tok));
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m;
	char t;
	cin >> n;
	scanf("%c", &t);
	string temp;
	vector<string> a;
	vector<string> b;
	for (int i = 1; i <= n; i++) {
		getline(cin, temp);
		a.push_back(temp);
	}
	cin >> m;
	scanf("%c", &t);
	for (int i = 1; i <= m; i++) {
		getline(cin, temp);
		b.push_back(temp);
	}

	for (auto k : solution(a, b))
		cout << k << "\n";
}