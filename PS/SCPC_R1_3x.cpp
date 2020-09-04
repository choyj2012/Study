/**
*	29점
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, k, m;
		cin >> N >> k >> m;
		//N = 세로선, k = 가로선, m = 쿼리
		Answer = 0;

		vector<vector<int>> DB(N + 1, vector<int>(N + 1, -1));
		vector<vector<int>> ladder(k + 1, vector<int>(N + 1));
		vector<pair<int, int>> hori(k + 1);

		for (int i = 1; i <= N; i++) ladder[0][i] = i;

		for (int i = 0; i < k; i++) {
			cin >> hori[i].first >> hori[i].second;
			for (int j = 1; j <= N; j++) {
				if (j == hori[i].first) ladder[i + 1][hori[i].first] = ladder[i][hori[i].second];
				else if (j == hori[i].second) ladder[i + 1][hori[i].second] = ladder[i][hori[i].first];
				else ladder[i + 1][j] = ladder[i][j];
			}

			if (i + 1 == k) {
				for (int j = 1; j <= N; j++) DB[ladder[i + 1][j]][j] = 0;
			}
		}
/*
		for (int i = 0; i <= k; i++) {
			for (int j = 1; j <= 4; j++) {
				cout << ladder[i][j];
			}
			cout << endl;
		}*/


		for (int del = 1; del <= k; del++) {

			vector<int> temp;
			for (int i = 1; i <= k; i++) {
				if (i <= del) temp.push_back(1);
				else temp.push_back(0);
			}

			int tar1, tar2;
			sort(temp.begin(), temp.end());
			do {
				vector<int> simul = ladder.back();
				for (int i = k; i >= 1; i--) {
					if (temp[i - 1] == 1) {
						tar1 = ladder[i - 1][hori[i - 1].first];
						tar2 = ladder[i - 1][hori[i - 1].second];
						auto a = find(simul.begin(), simul.end(), tar1);
						auto b = find(simul.begin(), simul.end(), tar2);
						*a = tar2;
						*b = tar1;

						
					}
				}
				for (int j = 1; j <= N; j++) {
					if (DB[simul[j]][j] < 0)
						DB[simul[j]][j] = del;
				}
			} while (next_permutation(temp.begin(), temp.end()));

		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			cout << DB[a][b] << endl;
			Answer += DB[a][b];
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}