#include <cstdio>

//피사노 주기 M = 15 * MOD / 10
#define M 1500000
#define MOD 1000000

int a[1500000];

int main() {
	long long N;
	scanf("%lld", &N);
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < M; i++) a[i] = (a[i - 1] + a[i - 2]) % MOD;
	printf("%d", a[N%M]);
}