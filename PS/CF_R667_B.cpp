#include <cstdio>


int main() {
	
	freopen("input.txt", "r", stdin);
	int T;
	long long a, b, x, y, n;
	scanf("%d", &T);

	while (T--) {
		scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &n);

		long long a1 = a - x;
		long long b1 = b - y;
		long long n1 = n;
		if (a1 < n1) {
			n1 -= a1;
			a1 = 0;
		}
		else {
			a1 -= n1;
			n1 = 0;
		}

		if (n1 > 0) {
			if (b1 < n1) {
				b1 = 0;
			}
			else
				b1 -= n1;
		}
		a1 += x;
		b1 += y;
		long long a2 = a - x;
		long long b2 = b - y;
		long long n2 = n;
		if (b2 < n2) {
			n2 -= b2;
			b2 = 0;
		}
		else {
			b2 -= n2;
			n2 = 0;
		}
		if (n2 > 0) {
			if (a2 < n2)
				a2 = 0;
			else
				a2 -= n2;
		}
		a2 += x;
		b2 += y;

		long long answer = (a1*b1) > (a2*b2) ? a2 * b2 : a1 * b1;
		printf("%lld\n", answer);
	}
	return 0;
}