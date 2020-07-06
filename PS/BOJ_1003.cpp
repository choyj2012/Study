#include <stdio.h>
#define N 45

int cnt0[N];
int cnt1[N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, i, n;
	cnt0[0] = 1; cnt1[0] = 0;
	cnt0[1] = 0; cnt1[1] = 1;

	for (i = 2; i <= 40; i++) {
		cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
		cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
	}
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d", &n);
		printf("%d %d\n", cnt0[n], cnt1[n]);
	}
	return 0;
}