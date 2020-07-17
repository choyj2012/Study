#include <stdio.h>
#include <vector>
using namespace std;

int n;
int answer = 0;
void solve(int x, int y, vector<pair<int, int>> v, int type);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<pair<int, int>> visited;
	scanf("%d", &n);

	visited.push_back({ 0, 0 });
	solve(0, 1, visited, 1);

	printf("%d", answer);
	return 0;
}


void solve(int x, int y, vector<pair<int, int>> v, int type) {
	
	if (v.size() == n + 1) {
		for (auto i = v.begin(); i != v.end(); i++) {
			if ((*i).first == x && (*i).second == y) {
				answer++;
				return;
			}
		}
		return;
	}

	for (auto i = v.begin(); i != v.end(); i++) {
		if ((*i).first == x && (*i).second == y) {
			return;
		}
	}

	v.push_back({ x, y });

	if (type == 1 || type == 2) {
		solve(x + 1, y, v, 3);
		solve(x - 1, y, v, 4);
	}

	else if (type == 3) {
		solve(x + 1, y, v, 3);
		if ((x + y) % 2 == 0) solve(x, y + 1, v, 1);
		else solve(x, y - 1, v, 2);
	}

	else if (type == 4) {
		solve(x - 1, y, v, 4);
		if ((x + y) % 2 == 0) solve(x, y + 1, v, 1);
		else solve(x, y - 1, v, 2);
	}
}