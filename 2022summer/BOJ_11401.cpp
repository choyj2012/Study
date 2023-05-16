#include <cstdio>

#define MOD 1000000007
typedef long long ll;

int N, K;

ll fact(int n) {
	ll ret = 1;
	for (int i = 1; i <= n; i++) ret = (ret*i) % MOD;
	return ret % MOD;
}

ll po(ll n, int p) {
	if (p == 1) return n;
	else
	{
		ll t = po(n, p / 2) % MOD;
		if (p % 2 == 1)
			return ((t*t) % MOD) * n % MOD;
		else return (t * t) % MOD;
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	
	ll np = fact(N);
	ll d = fact(K) * fact(N - K) % MOD;
	printf("%lld", np * po(d, MOD - 2) % MOD);

	return 0;
}