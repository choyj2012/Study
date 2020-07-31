#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 205
vector<int> adj[MAX_SIZE];
vector<int> check_cow(MAX_SIZE);
vector<int> check_cage(MAX_SIZE);
vector<bool> visited(MAX_SIZE);


int n_cow, n_cage;
int t, nn;

bool dfs(int node);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n_cow, &n_cage);
	
	for (int i = 1; i <= n_cow; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			scanf("%d", &nn);
			adj[i].push_back(nn);
		}
	}
	fill(check_cage.begin(), check_cage.end(), -1);
	fill(check_cow.begin(), check_cow.end(), -1);
	int cnt = 0;
	for (int i = 1; i <= n_cow; i++) {
		if (check_cow[i] == -1) {
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

bool dfs(int node) {
	visited[node] = 1;

	for (int k = 0; k < adj[node].size(); k++) {
		int tmp = adj[node][k];

		
		if (check_cage[tmp] == -1 || (!visited[check_cage[tmp]] && dfs(check_cage[tmp]))) {
			check_cow[node] = tmp;
			check_cage[tmp] = node;
			return true;
		}
	}
	return false;
}