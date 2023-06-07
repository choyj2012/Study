#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define MAX 2020

int cityCnt, cap, orderCnt;
vector<vector<array<int, 2>>> order;	//order[from] = [... { to, weight }]
int truck[MAX];

struct compare {
	bool operator()(const array<int, 2> i, const array<int, 2> j) {
		return i[0] > j[0];
	}
};
int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> cityCnt >> cap;
	cin >> orderCnt;
	order.resize(cityCnt + 1, vector<array<int, 2>>());

	int s, e, w;
	for (int i = 0; i < orderCnt; i++) {
		cin >> s >> e >> w;
		order[s].push_back({ e, w });
	}

	for (int i = 1; i <= cityCnt; i++) {
		sort(order[i].begin(), order[i].end(), [](array<int, 2> i, array<int, 2> j) {
			if (i[0] == j[0]) return i[1] < j[1];
			else return i[0] < j[0];
		});
	}

	priority_queue<array<int, 2>, vector<array<int, 2>>, compare> pq;
	
	int answer = 0;

	for (int from = 1; from <= cityCnt; from++) {
		priority_queue<array<int, 2>, vector<array<int, 2>>, compare> pq2;
		while (!pq.empty() && pq.top()[0] == from) {
			answer += pq.top()[1];
			pq.pop();
		}

		for (auto o : order[from]) {
			pq.push(o);
		}

		int nowW = 0;
		while (!pq.empty() && nowW < cap) {
			int w = pq.top()[1];
			if (w < cap - nowW) {
				pq2.push(pq.top());
				nowW += w;
			}
			else {
				pq2.push({ pq.top()[0], cap - nowW });
				nowW += cap - nowW;
			}
			pq.pop();
		}

		pq = pq2;
	}

	cout << answer << "\n";
	return 0;
}