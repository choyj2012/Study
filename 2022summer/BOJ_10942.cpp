#include <cstdio>
#include <vector>
using namespace std;

vector<int> num;
vector<vector<int>> dp;
int N, M;

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	dp.assign(N, vector<int>(N, 0));
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		num.push_back(t);
		
		dp[i][i] = 1;
		if (i != 0 && num[i] == num[i - 1]) dp[i - 1][i] = 1;
	}


	int x, y;
	for (int i = 2; i < N; i++) {
		y = 0;
		x = i;
		while (x < N) {
			if (dp[y + 1][x - 1] == 1 && num[y] == num[x])
				dp[y][x] = 1;
			y++; x++;
		}
	}

	scanf("%d", &M);
	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s - 1][e - 1]);
	}

	return 0;
}