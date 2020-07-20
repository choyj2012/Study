#include <stdio.h>
#include <algorithm>
using namespace std;

int d[1001];
int dp[1001];
int n;
int answer;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = d[i];
		for (int j = 1; j < i; j++) {
			if (d[i] > d[j])
				dp[i] = max(dp[j] + d[i], dp[i]);
		}
		answer = max(answer, dp[i]);
	}

	printf("%d", answer);
	return 0;
}