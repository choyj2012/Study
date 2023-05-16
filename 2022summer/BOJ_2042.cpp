#include <cstdio>
#include <vector>
using namespace std;

#define MAX_DATA 1000001
typedef long long ll;
int N, M, K;
vector<ll> num;
vector<ll> seg(4 * MAX_DATA);

void init(int n, int l, int r);
void update(int n, int l, int r, ll u, ll v);
ll sum(int n, int l, int r, ll u, ll v);

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);
	ll t;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t);
		num.push_back(t);
	}

	init(1, 0, N - 1);

	ll u, v;
	for (int i = 0; i < M + K; i++) {
		scanf("%lld %lld %lld", &t, &u, &v);

		if (t == 1) {
			update(1, 0, N - 1, u - 1, v);
		}

		if (t == 2) {
			printf("%lld\n", sum(1, 0, N - 1, u - 1, v - 1));
		}
	}
	return 0;
}

void init(int n, int l, int r) {

	if (l == r) {
		seg[n] = num[l];
		return;
	}

	int mid = (l + r) / 2;
	init(n * 2, l, mid);
	init(n * 2 + 1, mid + 1, r);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int n, int l, int r, ll u, ll v) {

	if (l == r) {
		seg[n] = v;
		return;
	}

	int mid = (l + r) / 2;
	if (u <= mid) {
		update(n * 2, l, mid, u, v);
	}
	else if (u > mid) {
		update(n * 2 + 1, mid + 1, r, u, v);
	}

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll sum(int n, int l, int r, ll u, ll v) {

	if (u <= l && r <= v) return seg[n];

	if (v < l || r < u) return 0;

	int mid = (l + r) / 2;

	return sum(n * 2, l, mid, u, v)
		+ sum(n * 2 + 1, mid + 1, r, u, v);
}