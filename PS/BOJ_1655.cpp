#include <cstdio>
#include <queue>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int N, t;
	scanf("%d", &N);

	priority_queue<int, vector<int>, greater<int>> Hq; //High Queue
	priority_queue<int, vector<int>, less<int>> Lq;	//Low Queue

	int mid;
	scanf("%d", &mid);
	printf("%d\n", mid);

	for (int i = 1; i < N; i++) {

		scanf("%d", &t);

		if (t >= mid) Hq.push(t);
		else Lq.push(t);


		if (Hq.size() > Lq.size() + 1) {
			Lq.push(mid);
			mid = Hq.top();
			Hq.pop();
		}
		else if (Hq.size() < Lq.size()) {
			Hq.push(mid);
			mid = Lq.top();
			Lq.pop();
		}

		printf("%d\n", mid);
	}

	return 0;
}