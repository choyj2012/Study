#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int childNum;
vector<int> line;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> childNum;
	int tmp;
	for (int i = 0; i < childNum; i++) {
		cin >> tmp;
		line.emplace_back(tmp);
	}

	vector<int> LIS;
	for (int childIdx : line) {
		
		if (LIS.empty() || LIS.back() < childIdx) {
			LIS.emplace_back(childIdx);
			continue;
		}

		int pos = lower_bound(LIS.begin(), LIS.end(), childIdx) - LIS.begin();
		LIS[pos] = childIdx;
	}

	cout << childNum - LIS.size() << "\n";
	return 0;
}