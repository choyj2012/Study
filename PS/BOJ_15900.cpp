#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int cnt;
bool visit[500001];
vector<vector<int> > v;

void dfs(int start, int height) {
	bool isLeaf = true;
	visit[start] = true;
	for (auto i = v[start].cbegin(); i != v[start].cend(); i++) {
		if (!visit[*i]) {
			isLeaf = false;
			dfs(*i, height + 1);
		}
	}
	if (isLeaf) cnt += height;
}

int main(void) {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, a, b;
	cin >> N;

	v.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cout << (cnt % 2 == 1 ? "Yes" : "No");

	return 0;
}