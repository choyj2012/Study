#include <stdio.h>

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int a[] = { 2, 1, 2, 3, 4, 5, 4, 3 };

	scanf("%d", &n);

	printf("%d", a[n % 8]);
	return 0;
}