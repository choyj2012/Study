#include <cstdio>

int T, n, m;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		char map[110][110];
		
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &map[i][j]);
			}
		}

		int answer = 0;
		for (int i = 0; i < m; i++) {
			if (map[n - 1][i] == 'D') answer++;
		}
		for(int i = 0; i < n; i++) {
			if (map[i][m - 1] == 'R') answer++;
		}

		printf("%d\n", answer);
	}
}