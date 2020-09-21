#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct comp {
	bool operator()(pair<int, int> A, pair<int, int> B) {
		return A.second < B.second;
	}
};

int main() {

	freopen("input.txt", "r", stdin);
	
	vector<pair<int, int>> gas;
	int N, a, b;
	int L, P;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		gas.push_back({ a, b });
	}
	scanf("%d %d", &L, &P);
	sort(gas.begin(), gas.end());

	int k = 0;
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	while (P < L) {

		for (; k < gas.size() && gas[k].first <= P; k++) {
			pq.push(gas[k]);
		}

		if (pq.empty()) {
			printf("-1");
			return 0;
		}

		P += pq.top().second;
		pq.pop();
		answer++;
	}

	printf("%d", answer);
}