#include <cstdio>

int main() {
	int T, n, x, y;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &n, &x, &y);

		int gap = y - x;
		int d;
		for (int i = n - 1; i > 0; i--) {
			if (gap%i == 0) {
				d = gap / i;
				break;
			}
		}

		for (int k = x; n > 0 && k <= y; n--, k+=d) {
			printf("%d ", k);
		}

		for (int k = x-d; n > 0 && k>0; n--, k-=d) {
			printf("%d ", k);
		}

		for (int k = y+d; n > 0; n--, k += d) {
			printf("%d ", k);
		}

		printf("\n");
	}
	return 0;
}