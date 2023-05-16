#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_DATA 100001
#define INF 1987654321 //수열 최대값 10억... INF 987654321 (x)
vector<int> seg(4 * MAX_DATA);
vector<int> num;
int N, M;
int inf_idx;

void init(int n, int l, int r) {

	if (l == r) {
		seg[n] = l;
		return;
	}

	int mid = (l + r) / 2;
	init(n * 2, l, mid);
	init(n * 2 + 1, mid + 1, r);
	
	seg[n] = (num[seg[n * 2]] <= num[seg[n * 2 + 1]]) ?
		seg[n * 2] : seg[n * 2 + 1];
}

void update(int n, int l, int r, int idx) {

	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	if (idx <= mid) update(n * 2, l, mid, idx);
	else update(n * 2 + 1, mid + 1, r, idx);

	seg[n] = (num[seg[n * 2]] <= num[seg[n * 2 + 1]]) ?
		seg[n * 2] : seg[n * 2 + 1];
}

int query(int n, int l, int r, int u, int v) {

	if (u <= l && r <= v) return seg[n];
	if (r < u || v < l) return inf_idx;

	int mid = (l + r) / 2;

	int ql = query(n * 2, l, mid, u, v);
	int qr = query(n * 2 + 1, mid + 1, r, u, v);
	return (num[ql] <= num[qr]) ? ql : qr;
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	inf_idx = N;
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}
	num.push_back(INF);
	init(1, 0, N - 1);

	scanf("%d", &M);
	int t1, t2, t3;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);

		if (t1 == 1) {
			num[t2 - 1] = t3;
			update(1, 0, N - 1, t2 - 1);
		}

		if (t1 == 2) {
			printf("%d\n", query(1, 0, N - 1, t2 - 1, t3 - 1) + 1);
		}
	}
}