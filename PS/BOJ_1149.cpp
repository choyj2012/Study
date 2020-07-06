#include <stdio.h>


int answer[1010][3];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i, t0, t1, t2;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &t0, &t1, &t2);
		int min;
		min = (answer[i - 1][1] < answer[i - 1][2]) ? answer[i - 1][1] : answer[i - 1][2];
		answer[i][0] = t0 + min;
		min = (answer[i - 1][0] < answer[i - 1][2]) ? answer[i - 1][0] : answer[i - 1][2];
		answer[i][1] = t1 + min;
		min = (answer[i - 1][0] < answer[i - 1][1]) ? answer[i - 1][0] : answer[i - 1][1];
		answer[i][2] = t2 + min;
	}

	int ans = answer[n][0];
	for (i = 1; i < 3; i++) {
		if (ans > answer[n][i])
			ans = answer[n][i];
	}
	printf("%d", ans);
	return 0;
}