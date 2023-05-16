#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> line;
int N;

bool cmp(const pair<int, int> i, const pair<int, int> j) {
	return i.first< j.first;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	line.assign(N, pair<int, int>());
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &line[i].first, &line[i].second);
	}

	sort(line.begin(), line.end(), cmp);
	vector<int> lcs;
	vector<int> pos(N, 0);

	for (int i = 0; i < N; i++) {
		int now = line[i].second;

		if (lcs.empty() || lcs.back() < now) {
			lcs.push_back(now);
			pos[i] = lcs.end() - lcs.begin();
		}
		else {
			auto p = lower_bound(lcs.begin(), lcs.end(), now);
			*p = now;
			pos[i] = p - lcs.begin() + 1;
		}
	}

	vector<pair<int, int>> ans;
	int idx = lcs.size();
	for (int i = N-1; i >= 0; i--) {
		if (pos[i] == idx) idx--;
		else ans.push_back(line[i]);
	}

	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (auto t : ans) {
		printf("%d\n", t.first);
	}
	return 0;	
}