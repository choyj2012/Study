#include <stdio.h>
#include <vector>
using namespace std;

int n;
int t1, t2;
long long cntD, cntG;
vector<vector<int>> adj;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &t1, &t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}

	for (int node = 1; node <= n; node++) {
		for (auto i = adj[node].begin(); i != adj[node].end(); i++) {
			cntD += ((adj[node].size() - 1) * (adj[*i].size() - 1));
		}
	}
	cntD /= 2;

	for (int node = 1; node <= n; node++) {
		int n_edge = adj[node].size();
		if (n_edge >= 3) {
			cntG += n_edge * (n_edge - 1) * (n_edge - 2) / 6;
		}
	}

	if (cntD > 3 * cntG) printf("D");
	else if (cntD < 3 * cntG) printf("G");
	else if (cntD == 3 * cntG) printf("DUDUDUNGA");

	return 0;
}