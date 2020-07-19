#include <stdio.h>

int ans[2][10002];
int n, k;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &n, &k);
	int t;
	int flag = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		flag = !flag;
		for (int j = 1; j <= k; j++) {
			if (j < t) ans[flag][j] = ans[!flag][j];
			else if (t == j) ans[flag][j] = ans[!flag][j] + 1;
			else ans[flag][j] = ans[!flag][j] + ans[flag][j - t];
		}
	}

	printf("%d", ans[flag][k]);
	return 0;
}