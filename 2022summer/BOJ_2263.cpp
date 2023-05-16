#include <cstdio>
#include <vector>
using namespace std;

vector<int> in;
vector<int> post;
vector<int> pos;
vector<pair<int, int>> tree;
int N;
int idx;

int q(int L, int R) {

	if (L > R) return -1;

	int rn = post[idx--];
	tree[rn].second = q(pos[rn] + 1, R);
	tree[rn].first = q(L, pos[rn] - 1);

	return rn;
}

void pre_order(int n) {
	if (n == -1) return;
	printf("%d ", n);
	pre_order(tree[n].first);
	pre_order(tree[n].second);
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	pos.resize(N + 1);
	tree.resize(N + 1, pair<int,int>(-1, -1));
	int t;
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		in.push_back(t);
		pos[t] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		post.push_back(t);
	}

	idx = N - 1;
	int root = post[idx];
	q(0, N - 1);

	pre_order(root);
	return 0;
}