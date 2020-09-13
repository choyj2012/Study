#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto com_num : course) {

		vector<pair<int, string>> setcount;
		vector<int> combine(26, 0);
		
		for (int i = 1; i <= com_num; i++) combine[i] = 1;

		sort(combine.begin(), combine.end());

		int cnt = 0;
		do
		{
			cnt = 0;
			for (int k = 0; k < orders.size(); k++) {
				bool flag = true;
				int ccnt = 0;
				for (int i = 0; i < 26; i++) {
					if (ccnt == com_num) break;
					if (combine[i] == 1) {
						ccnt++;
						int f = orders[k].find(i + 65);
						if (f == -1) {
							flag = false;
							break;
						}
					}
				}
				if (flag == true) cnt++;
			}

			if (cnt >= 2) {
				string temp;
				for (int i = 0; i < 26; i++) {
					if (combine[i] == 1) {
						temp.push_back(i + 65);
					}
				}
				setcount.push_back({ cnt, temp });
			}
		} while (next_permutation(combine.begin(), combine.end()));

		sort(setcount.begin(), setcount.end());

		for (int k = setcount.size() - 1; k >= 0; k--) {
			if (setcount[k].first == setcount.back().first)
				answer.push_back(setcount[k].second);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}


int main() {

	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<string> ord;
	vector<int> cor;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		ord.push_back(temp);
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		cor.push_back(k);
	}

	for (auto k : solution(ord, cor)) {
		cout << k << "\n";
	}
	return 0;
}