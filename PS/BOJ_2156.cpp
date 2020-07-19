#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int d[10001];
int ans[10001];
int answer;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}

	ans[1] = d[1];
	ans[2] = d[1] + d[2];
	int answer = ans[2];
	for (int i = 3; i <= n; i++) {
		ans[i] = max(ans[i - 2] + d[i], ans[i - 3] + d[i-1]+d[i]);
		ans[i] = max(ans[i], ans[i - 1]);
	}

	printf("%d", ans[n]);
	return 0;
}