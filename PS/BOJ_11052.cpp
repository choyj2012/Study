#include <stdio.h>

int cost[1001];
int ans[1001];
int n;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; i <= n; j++) {
			if (i - j < 0)break;

			ans[i] = (ans[i - j] + cost[j] > ans[i]) ? ans[i - j] + cost[j] : ans[i];
		}
	}
	printf("%d", ans[n]);
	return 0;
}