#include <stdio.h>

int main() {
	int n, i;

	scanf("%d", &n);

	int p[1001];
	p[1] = 1;
	p[2] = 2;
	for (i = 3; i <= n; i++) {
		p[i] = p[i - 1] + p[i - 2];
		if (p[i] > 10007) p[i] %= 10007;
	}
	printf("%d", p[n]);
	return 0;
}