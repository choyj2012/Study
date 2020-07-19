#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

class compare {
public:
	bool operator() (const pair<int, int> &i, const pair<int, int> &j) {
		return i.second > j.second;
	}
};

int node, edge, start;
int s, e, w;
vector<int> dist;
vector<vector<pair<int, int>>> adj;	//first=end, second=weight
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
vector<bool> visited;

void sol(int start);


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &node, &edge, &start);
	adj.resize(node + 1);
	dist.resize(node + 1, INF);
	visited.resize(node + 1);

	for (int i = 1; i <= edge; i++) {
		scanf("%d %d %d", &s, &e, &w);
		adj[s].push_back({ e, w });
	}

	sol(start);
	for (int i = 1; i <= node; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}

void sol(int start) {

	pq.push({ start, 0 });
	dist[start] = 0;
	int now;

	while (!pq.empty()) {
		now = pq.top().first;
		pq.pop();

		if (visited[now]) continue;
		visited[now] = true;

		for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
			if (dist[(*i).first] > dist[now] + (*i).second) {
				dist[(*i).first] = dist[now] + (*i).second;
				pq.push({ (*i).first, dist[now] + (*i).second });
			}
		}
	}
}