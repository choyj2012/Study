#include <cstdio>
#include <vector>
using namespace std;

#define MAX_D 1000001
typedef long long ll;

int N, M, K;
vector<ll> seg(MAX_D * 4);
vector<ll> lazy(MAX_D * 4);
vector<ll> num;

void init(int node, int l, int r) {

	if (l == r) {
		seg[node] = num[l - 1];
		return;
	}

	int mid = (l + r) / 2;
	init(node * 2, l, mid);
	init(node * 2 + 1, mid + 1, r);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void propa(int node, int l, int r) {
	if (lazy[node] != 0) {
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		seg[node] += lazy[node] * (r - l + 1);
		lazy[node] = 0;
	}
}

void update(int node, int tl, int tr, int l, int r, ll num) {

	propa(node, l, r);

	if (r < tl || tr < l) return;
	if (tl <= l && r <= tr) {
		lazy[node] += num;
		propa(node, l, r);
		return;
	}

	int mid = (l + r) / 2;
	update(node * 2, tl, tr, l, mid, num);
	update(node * 2 + 1, tl, tr, mid + 1, r, num);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int tl, int tr, int l, int r) {

	propa(node, l, r);
	if (r < tl || tr < l) return 0;
	if (tl <= l && r <= tr) return seg[node];

	int mid = (l + r) / 2;
	ll q1 = query(node * 2, tl, tr, l, mid);
	ll q2 = query(node * 2 + 1, tl, tr, mid + 1, r);
	return q1 + q2;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);
	ll t;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t);
		num.push_back(t);
	}

	init(1, 1, N);

	int t1, t2, t3;
	ll t4;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);

		if (t1 == 1) {
			scanf("%lld", &t4);
			update(1, t2, t3, 1, N, t4);
		}

		if (t1 == 2) {
			printf("%lld\n", query(1, t2, t3, 1, N));
		}
	}

	return 0;
}