#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<pair<pair<int, int>, int>> edge;
vector<int> root;

bool cmp(const pair<pair<int, int>, int> &i, const pair<pair<int, int>, int> &j) {
	return i.second < j.second;
}

int union_find(int n) {
	if (root[n] == n) return n;
	return root[n] = union_find(root[n]);
}

int main() {

	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);
	root.resize(N + 1);
	for (int i = 1; i <= N; i++) root[i] = i;

	int t1, t2, t3;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		edge.push_back({ { t1, t2 }, t3 });
	}

	sort(edge.begin(), edge.end(), cmp);
	int vcnt = N;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int n1 = edge[i].first.first;
		int n2 = edge[i].first.second;
		int w = edge[i].second;

		int p1 = union_find(n1);
		int p2 = union_find(n2);

		if (p1 != p2) {
			root[p1] = root[p2];
			ans += w;
			vcnt--;
		}

		if (vcnt == 2) break;
	}

	printf("%d", ans);
	return 0;
}