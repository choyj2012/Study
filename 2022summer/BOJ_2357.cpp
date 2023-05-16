#include <cstdio>
#include <vector>
using namespace std;

#define MAX 100001
#define INF 1000000001
int N, M;
pair<int, int> seg[4 * MAX];
vector<int> num;

void init(int node, int L, int R) {
	if (L == R) {
		seg[node] = { num[L - 1], num[L - 1] };
		return;
	}

	int mid = (L + R) / 2;
	init(node * 2, L, mid);
	init(node * 2 + 1, mid + 1, R);

	seg[node].first = seg[node * 2].first > seg[node * 2 + 1].first ?
		seg[node * 2].first : seg[node * 2 + 1].first;
	seg[node].second = seg[node * 2].second < seg[node * 2 + 1].second ?
		seg[node * 2].second : seg[node * 2 + 1].second;
}

pair<int, int> query(int node, int tl, int tr, int l, int r) {

	if (tl <= l && r <= tr) return seg[node];
	if (r < tl || tr < l) return make_pair(-INF, INF);

	int mid = (l + r) / 2;
	auto t1 = query(node * 2, tl, tr, l, mid);
	auto t2 = query(node * 2 + 1, tl, tr, mid + 1, r);

	pair<int, int> t;
	t.first = t1.first > t2.first ? t1.first : t2.first;
	t.second = t1.second > t2.second ? t2.second : t1.second;
	return t;
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}

	fill(seg, seg + (4 * MAX) - 1, make_pair(-INF, INF));
	init(1, 1, N);

	int t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &t1, &t2);
		auto q = query(1, t1, t2, 1, N);
		printf("%d %d\n", q.second, q.first);
	}

	return 0;
}