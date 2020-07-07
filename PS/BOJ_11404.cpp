#include <stdio.h>

#define N 110
#define INF 987654321

int data[N][N];
int answer[N][N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	int i, j, k, t1, t2, t3;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);

		if (data[t1][t2] == 0) {	//0이면 바로입력 아니면 비교
			data[t1][t2] = t3;
		}
		else {
			data[t1][t2] = (data[t1][t2] > t3) ? t3 : data[t1][t2];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) answer[i][j] = 0;
			else if (data[i][j] == 0) answer[i][j] = INF;
			else answer[i][j] = data[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				if (answer[j][k] > answer[j][i] + answer[i][k])
					answer[j][k] = answer[j][i] + answer[i][k];
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (answer[i][j] == INF) printf("0 ");
			else printf("%d ", answer[i][j]);
		}
		printf("\n");
	}

	return 0;
}