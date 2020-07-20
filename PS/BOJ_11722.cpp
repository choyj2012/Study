#include <stdio.h>
#include <algorithm>
using namespace std;

int d[1001];
int dp[1001];
int n, answer;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[i] < d[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	printf("%d", answer);
	return 0;
}