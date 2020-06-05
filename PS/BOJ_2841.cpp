#include <stdio.h>
#include <vector>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<vector<int>> Line;
	int n, p, line, num, i, cnt = 0;
	for (i = 1; i <= 6; i++) {
		vector<int> temp;
		Line.push_back(temp);
	}

	scanf("%d %d", &n, &p);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &line, &num);

		if (Line[line - 1].empty()) {
			Line[line - 1].push_back(num);
			cnt++;
		}
		else {
			while (!Line[line-1].empty() && Line[line - 1].back() > num) {
				Line[line - 1].pop_back();
				cnt++;
			}
			if (Line[line-1].empty() || Line[line - 1].back() != num) {
				Line[line - 1].push_back(num);
				cnt++;
			}
		}
	}

	printf("%d", cnt);
	return 0;
}