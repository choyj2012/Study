#include <stdio.h>

int main() {
		long long int sum = 1, i = 1;
		long long int n;

		scanf("%lld", &n);
		while (1)
		{
			if (sum >= n) break;
			sum += 6 * i;
			i++;
		}

		printf("%lld\n", i);
	return 0;
}