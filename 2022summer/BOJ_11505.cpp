#include <cstdio>
#include <vector>
using namespace std;

#define MOD 1000000007
#define MAX_DATA 1000001
typedef long long ll;

vector<int> seg(4 * MAX_DATA, 1);
vector<int> num;
int N, M, K;

void init(int n, int l, int r) {

	if (l == r) {
		seg[n] = num[l];
		return;
	}

	int mid = (l + r) / 2;
	init(n * 2, l, mid);
	init(n * 2 + 1, mid + 1, r);
	seg[n] = ((ll)seg[n * 2] * seg[n * 2 + 1]) % MOD;
}

void update(int n, int l, int r, int u, int v) {

	if (l == r) {
		seg[n] = v;
		return;
	}

	int mid = (l + r) / 2;
	if (u <= mid) {
		update(n * 2, l, mid, u, v);
	}
	else
		update(n * 2 + 1, mid + 1, r, u, v);

	seg[n] = ((ll)seg[n * 2] * seg[n * 2 + 1]) % MOD;
}

ll mul(int n, int l, int r, int u, int v) {

	if (u <= l && r <= v) return (ll)seg[n];

	if (r < u || v < l) return 1LL;

	int mid = (l + r) / 2;
	return (mul(n * 2, l, mid, u, v)
		* mul(n * 2 + 1, mid + 1, r, u, v)) % MOD;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}

	init(1, 0, N - 1);

	int t1, t2, t3;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);

		if (t1 == 1) {
			update(1, 0, N - 1, t2-1, t3);
		}

		if (t1 == 2) {
			printf("%lld\n", mul(1, 0, N - 1, t2-1, t3-1) % MOD);
		}
	}
	return 0;
}