#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<int> dist;

int bfs(int n, int start, bool b);
int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	adj.resize(n + 1);
	dist.resize(n + 1);
	for (auto t : edges) {
		adj[t[0]].push_back(t[1]);
		adj[t[1]].push_back(t[0]);
	}
	
	int long1, long2;
	long1 = bfs(n, 1, 0);
	long2 = bfs(n, long1, 1);
	int len = dist[long2];
	bfs(n, long2, 1);
	dist[long1] = 0;
	dist[long2] = 0;
	sort(dist.rbegin(), dist.rend());


	return answer = (len + dist[0])/3;
}

int bfs(int n, int start, bool b) {

	deque<int> Q;
	vector<int> check(n + 1, 0);
	Q.push_back(start);
	check[start] = true;
	int di = 0;
	int now;
	while (!Q.empty()) {
		di++;
		now = Q.front();
		Q.pop_front();

		for (int k : adj[now]) {
			if (check[k] == 0) {
				Q.push_back(k);
				check[k] = 1;
				if(b) dist[k] += di;
			}
		}
	}

	return now;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n, a, b;
	scanf("%d", &n);
	vector<vector<int>> k(n-1);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		k[i].push_back(a);
		k[i].push_back(b);
	}
	printf("%d", solution(n, k));
}