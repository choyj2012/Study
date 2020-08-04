#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000
int n_node, n_edge;
int S, T;
vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> pr;

struct his {
	int node;
	int d;
	int prev;
};

struct compare {
	bool operator()(his i, his j) {
		return i.d > j.d;
	}
};

void dijstra() {
	dist[S] = 0;
	priority_queue<his, vector<his>, compare> pq;
	pq.push({ S, 0, -1});
	pr[S] = -1;

	while (!pq.empty()) {

		int now = pq.top().node;
		int d = pq.top().d;
		int p = pq.top().prev;
		pq.pop();
		
		if(pr[now] == 0)
			pr[now] = p;

		for (auto& k : adj[now]) {
			if (pr[k.first] == 0 && dist[k.first] > d + k.second) {
				dist[k.first] = d + k.second;
				pq.push({ k.first, d + k.second, now });
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n_node, &n_edge);
	adj.resize(n_node + 1);
	dist.resize(n_node + 1, INF);
	pr.resize(n_node + 1);

	int s, e, w;
	for (int i = 1; i <= n_edge; i++) {
		scanf("%d %d %d", &s, &e, &w);
		adj[s].push_back({ e, w });
	}
	scanf("%d %d", &S, &T);

	dijstra();

	vector<int> answer;
	int k = T;
	int cnt = 0;
	while (k != -1) {
		answer.push_back(k);
		cnt++;
		k = pr[k];
	}
	printf("%d\n", dist[T]);
	printf("%d\n", cnt);
	for (int i = answer.size() - 1; i >= 0; i--) {
		printf("%d ", answer[i]);
	}
	return 0;
}