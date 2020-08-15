#include <cstdio>

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}