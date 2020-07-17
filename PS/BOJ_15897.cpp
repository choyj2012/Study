#include <stdio.h>

int main() {	

	int n;
	scanf("%d", &n);
	long long sum = 0;
	long long skip = 0;
	for (int i = 1; i <= n; i += skip) {

		int div = (n - 1) / i;
		int mod = (n - 1) % i;
		if (div == 0) skip = 1;
		else
			skip = mod / div + 1;
		sum += (div + 1)*skip;
	}

	printf("%lld", sum);
	return 0;
}