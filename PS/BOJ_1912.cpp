#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int t;
	int dp = -INF;
	int answer = -INF;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);

		dp = max(t, dp + t);
		answer = max(answer, dp);
	}

	printf("%d", answer);
	return 0;
}