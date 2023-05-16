#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 2510
char str[MAX];
bool isPal[MAX][MAX];
int dp[MAX];
int N;

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%s", str);
	N = strlen(str);
	for (int i = 0; i < N; i++) {
		isPal[i][i] = true;
		if (i < N-1 && str[i] == str[i + 1]) isPal[i][i + 1] = true;
	}
	for (int j = 2; j < N; j++) {
		int x = j;
		for (int i = 0; i < N; i++, x++) {
			isPal[i][x] = isPal[i + 1][x - 1] && str[i] == str[x];
		}
	}

	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		int mi = MAX;
		for (int j = i; j >= 1; j--) {
			if (isPal[j-1][i-1] == true)
				mi = min(mi, dp[j - 1]);
		}
		dp[i] = mi + 1;
	}
	printf("%d", dp[N]);
	return 0;
}