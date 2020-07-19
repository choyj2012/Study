#include <stdio.h>

#define MOD 10007
int ans[1001];
int n;

int main() {

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	ans[1] = 1;
	ans[2] = 3;
	for (int i = 3; i <= n; i++) {
		ans[i] = (ans[i - 1] + 2 * ans[i - 2]) % MOD;
	}

	printf("%d", ans[n]);
	return 0;
}