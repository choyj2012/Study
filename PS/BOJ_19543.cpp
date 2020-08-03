#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> pat;
string order;

int N, M, K;
long long answer = 0;

void init() {
	scanf("%d %d %d", &N, &M, &K);
	string str;
	for (int i = 1; i <= K; i++) {
		cin >> str;
		pat.push_back(str);
	}
	cin >> order;
}

int getline(int i) {
	return N - i - 1;
}

void sol() {
	int L, R;
	R = M - 1;
	L = 0;
	int line = order[getline(0)] - 'A';
	for (int i = R - 1; i >= 0; i--) {
		if (pat[line][i] == 'U') {
			L = i + 1;
			break;
		}
	}
	answer += R - L + 1;

	for (int i = 1; i < N; i++) {
		line = order[getline(i)] - 'A';
		bool isfound = false;
		for (int j = R; j >= L; j--) {
			if (pat[line][j] == 'U') {
				isfound = true;
				R = j;
				break;
			}
		}

		if (isfound == false) return;
		else {
			isfound = false;
			if (L != 0) {
				for (int j = L - 1; j >= 0; j--) {
					if (pat[line][j] == 'U') {
						L = j + 1;
						isfound = true;
						break;
					}
				}

				if (isfound == false) L = 0;
			}
			answer += R - L + 1;
		}
	}
}

int main() {
	init();
	sol();

	printf("%lld", answer);
	return 0;
}