#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
vector<int> LIS;
vector<int> d;
vector<int> answer;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		d.push_back(t);
		if (LIS.empty() || LIS.back() < t) {
			LIS.push_back(t);
			answer.push_back(LIS.size()-1);
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), t);
			*it = t;
			answer.push_back(it - LIS.begin());
		}
	}
	
	printf("%d\n", LIS.size());
	int idx = LIS.size()-1;
	vector<int> ans;
	for (int i = answer.size()-1; i >=0; i--) {
		if (answer[i] == idx) {
			ans.push_back(d[i]);
			idx--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	return 0;
}