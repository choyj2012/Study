#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 510;

int buildingCnt;
vector<int> buildTime(MAX);
int prevB;
vector<vector<int>> Tech(MAX, vector<int>());
vector<int> prevCond(MAX, 0);
queue<int> buildQ;
vector<int> answer(MAX, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);

	cin >> buildingCnt;	//건물 개수

	for (int i = 1; i <= buildingCnt; i++) {
		cin >> buildTime[i];	//건물 짓는 시간
		while (1) {
			cin >> prevB;
			if (prevB == -1) break;
			Tech[prevB].push_back(i);	//prevB -> i
			prevCond[i]++;
		}
	}

	for (int i = 1; i <= buildingCnt; i++)
		if (prevCond[i] == 0) buildQ.push(i);

	while (!buildQ.empty()) {
		int buildNum = buildQ.front();
		answer[buildNum] += buildTime[buildNum];

		buildQ.pop();

		for (int next : Tech[buildNum])
		{
			answer[next] = max(answer[next], answer[buildNum]);
			if (--prevCond[next] == 0) {
				buildQ.push(next);
			}
		}
	}

	for (int i = 1; i <= buildingCnt; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}