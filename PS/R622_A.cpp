#include <stdio.h>

int main() {

	int T, n;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		printf("%d\n", n / 2 + 1);
	}
	return 0;
}