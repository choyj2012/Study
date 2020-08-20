#include <vector>
#include <cstdio>
#include <deque>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, L, t;
	scanf("%d %d", &N, &L);
	vector<int> num;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}

	deque<int> Q;

	int now = 0;
	while (now < N) {

		while (!Q.empty() && Q.front() < now - L + 1) Q.pop_front();

		while (!Q.empty() && num[Q.back()] > num[now]) Q.pop_back();

		Q.push_back(now);
		now++;
		printf("%d ", num[Q.front()]);
	}
}