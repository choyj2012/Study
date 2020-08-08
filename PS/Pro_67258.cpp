#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer{ 1, (int)gems.size() };
	unordered_map<string, int> hash;
	vector<int> Gems;

	int mapping = 0;
	for (auto& k : gems) {
		if (hash.find(k) == hash.end())
			hash[k] = ++mapping;

		Gems.push_back(hash[k]);
	}

	vector<int> cnt(mapping + 1, 0);

	int L = 0, R = 0;
	int kind = 1;
	cnt[Gems[L]]++;

	while (1) {


		if (kind == mapping) {
			if (answer[1] - answer[0] > R - L) {
				answer[1] = R + 1;
				answer[0] = L + 1;
			}
			if (cnt[Gems[L]] == 1) kind--;
			cnt[Gems[L]]--;
			L++;
		}
		else {
			R++;
			if (R == Gems.size()) break;
			if (cnt[Gems[R]] == 0) kind++;
			cnt[Gems[R]]++;
		}

	}


	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	string str;
	vector<string> DATA;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		DATA.push_back(str);
	}

	vector<int> answer = solution(DATA);
	cout << answer[0] << answer[1];

	return 0;
}