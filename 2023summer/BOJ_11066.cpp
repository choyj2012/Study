#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 987654321;
int T;
int fileCnt;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> fileCnt;
		vector<int> fileSize(fileCnt + 1);
		vector<vector<int>> DP(fileCnt + 1, vector<int>(fileCnt + 1, 0));
		vector<int> sum(fileCnt + 1, 0);
		for (int i = 1; i <= fileCnt; i++) {
			cin >> fileSize[i];
			sum[i] = sum[i - 1] + fileSize[i];
		}

		for (int i = 1; i < fileCnt; i++) {
			for (int from = 1; from + i <= fileCnt; from++) {

				int minV = MAX;
				for (int mid = from; mid < from + i; mid++) {
					int cost = DP[from][mid] + DP[mid + 1][from + i];
					cost += (sum[mid] - sum[from - 1]);
					cost += (sum[from + i] - sum[mid + 1 - 1]);

					minV = min(minV, cost);
				}
				DP[from][from + i] = minV;
			}
		}
		cout << DP[1][fileCnt] << "\n";
	}
	return 0;
}