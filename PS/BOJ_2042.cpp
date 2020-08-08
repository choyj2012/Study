#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

int N, Q1, Q2;
vector<ll> seg(2 << 21, 0);

void change();
void sum();

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &N, &Q1, &Q2);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &seg[(2 << 20) + i]);
	}
	for (int i = (2 << 20) - 1; i > 0; i--) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

	int q;
	for (int i = 0; i < Q1 + Q1; i++) {
		scanf("%d", &q);
		if (q == 1)
			change();
		if (q == 2)
			sum();
	}
}

void change() {
	int tar;
	ll n;
	scanf("%d %lld", &tar, &n);
	int idx = (2 << 20) + tar - 1;
	seg[idx] = n;
	idx /= 2;
	while (idx != 0) {
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
		idx /= 2;
	}
}
void sum() {
	int L, R;
	ll answer = 0;
	scanf("%d %d", &L, &R);

	L += (2 << 20) - 1;
	R += (2 << 20) - 1;
	while(L < R) {

		if (L % 2 == 1) answer += seg[L++];
		if (R % 2 == 0) answer += seg[R--];
		L /= 2;
		R /= 2;
	}
	if (L == R) answer += seg[L];

	printf("%lld\n", answer);
}