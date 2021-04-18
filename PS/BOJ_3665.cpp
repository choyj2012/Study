#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(const tuple<int, int, int> &A, const tuple<int, int, int> &B) {
	return get<1>(A) > get<1>(B);
}

int main() {

	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	int N, Q;
	while (T--) {

		scanf("%d", &N);
		vector<vector<int>> verse(N + 1, vector<int>(N + 1, 0));
		vector<tuple<int, int, int>> WinLose(N + 1, { 0, 0, 0 });	//index, Win, Lose

		int team;
		for (int i = 0; i < N; i++) {
			scanf("%d", &team);
			get<0>(WinLose[i + 1]) = i + 1;
			for (int j = 1; j <= N; j++) {
				if (j != team && verse[team][j] == 0) {
					verse[team][j] = 1;
					get<1>(WinLose[team]) += 1;
					
					verse[j][team] = -1;
					get<2>(WinLose[j]) += 1;
				}
			}
		}


		scanf("%d", &Q);
		int t1, t2;
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &t1, &t2);

			int d = (verse[t1][t2] == 1) ? 1 : -1;
			
			get<1>(WinLose[t1]) -= d;
			get<2>(WinLose[t1]) += d;

			get<1>(WinLose[t2]) += d;
			get<2>(WinLose[t2]) -= d;
		}

		sort(WinLose.begin() + 1, WinLose.end(), compare);

		bool isImpossible = false;
		for (int i = 1; i < N; i++) {
			if (get<1>(WinLose[i]) == get<1>(WinLose[i + 1])) {
				isImpossible = true;
				break;
			}
		}

		if (isImpossible) {
			printf("IMPOSSIBLE\n");
		}
		else {
			for (int i = 1; i <= N; i++) {
				printf("%d ", get<0>(WinLose[i]));
			}
			printf("\n");
		}
	}

	return 0;
}