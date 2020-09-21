#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comp {
	bool operator()(pair<int, int> A, pair<int, int> B) {
		if (A.second == B.second)
			return A.first > B.second;
		else
			return A.second > B.second;
	}
};

int solution(vector<vector<int>> jobs) {    //jobs = (요청시간, 소요시간)
	int answer = 0;

	sort(jobs.begin(), jobs.end());
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	int k = 0;
	int now_time = 0;
	while (1) {

		for (; k < jobs.size() && jobs[k][0] <= now_time; k++) {
			pq.push({ jobs[k][0], jobs[k][1] });
		}

		if (pq.empty()) {
			if (k < jobs.size()) {
				now_time = jobs[k][0];
				continue;
			}
			else
				break;
		}

		answer += now_time - pq.top().first + pq.top().second;
		now_time += pq.top().second;
		pq.pop();
	}

	return answer / jobs.size();
}

int main() {

	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<vector<int>> j(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &j[i][0], &j[i][1]);
	}
	printf("%d", solution(j));
}