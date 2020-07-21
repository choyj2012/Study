#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321
int square[320];
int n;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector<int> dp(n + 1, INF);

	dp[0] = 0;
	for (int i = 1; i*i < 100000; i++) {
		square[i] = i * i;
	}

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], (dp[i - square[j]] + 1));
		}
	}

	printf("%d", dp[n]);
	return 0;
}