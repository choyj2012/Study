/*
*	2020UCPC ¿¹¼± G
*/

#include <stdio.h>
#include <vector>
#include <deque>
using namespace std;

#define N 200010
vector<int> adj[N];
vector<int> answer(N, -100);
int cnt[N];
bool visited[N];
deque<pair<int, int>> Queue;

int n, m, t;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		while (1) {
			scanf("%d", &t);
			if (t == 0) break;
			adj[i].push_back(t);
		}
		cnt[i] = (adj[i].size() + 1) / 2;
	}

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &t);
		Queue.push_back({ t, 0 });
		visited[t] = true;
		answer[t] = 0;
	}

	
	int now_node;
	int now_time;

	while (!Queue.empty()) {

		now_node = Queue.front().first;
		now_time = Queue.front().second;
		Queue.pop_front();

		for (auto i = adj[now_node].begin(); i != adj[now_node].end(); i++) {
			if (visited[*i] == false) {
				cnt[*i]--;
				if (cnt[*i] == 0) {
					Queue.push_back({ *i, now_time + 1 });
					visited[*i] = true;
					answer[*i] = now_time + 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (answer[i] == -100) printf("-1 ");
		else printf("%d ", answer[i]);
	}
}