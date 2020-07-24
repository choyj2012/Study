#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;
deque<pair<int, int>> Queue;
vector<bool> visited;

int node;
int s, e, w;

int bfs(int node);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &node);
	adj.resize(node + 1);
	dist.resize(node + 1);
	visited.resize(node + 1);

	for (int i = 1; i <= node; i++) {
		scanf("%d", &s);
		while (1) {
			scanf("%d", &e);
			if (e == -1) break;
			scanf("%d", &w);

			adj[s].push_back({ e, w });
		}
	}

	int StartNode = bfs(1);

	dist.clear();
	dist.resize(node + 1, 0);
	visited.clear();
	visited.resize(node + 1, false);
	int answer = bfs(StartNode);

	printf("%d", dist[answer]);
	return 0;
}

int bfs(int node) {
	Queue.push_back({ node, 0 });
	int mdistidx = 0;

	while (!Queue.empty()) {
		int now = Queue.front().first;
		int d = Queue.front().second;
		Queue.pop_front();
		visited[now] = true;

		for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
			if (visited[(*i).first] == false) {
				Queue.push_back({ (*i).first, (*i).second });
				dist[(*i).first] = dist[now] + (*i).second;
				
				if (dist[mdistidx] < dist[(*i).first])
					mdistidx = (*i).first;
			}
		}
	}

	return mdistidx;
}