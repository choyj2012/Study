#include <cstdio>
#include <vector>
using namespace std;

#define INF 2087654321
int N;
vector<int> cap;
vector<int> money;
vector<int> a0;
vector<int> a1;
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	int t1, t2;
	cap.push_back(0);
	money.push_back(0);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		cap.push_back(t1);
		money.push_back(t2);
	}

	a0.resize(N + 1);
	a1.resize(N + 1);

	a0[1] = money[1];
	a1[1] = 0;
	for (int i = 2; i <= N; i++) {

		if (a0[i - 1] <= cap[i]) {
			a0[i] = a0[i - 1] + money[i];
		}
		else a0[i] = INF;

		if (a1[i - 1] <= cap[i]) {
			a1[i] = a1[i - 1] + money[i];
		}
		else a1[i] = INF;

		if (a0[i - 1] < a1[i]) a1[i] = a0[i - 1];
	}

	if (a0[N] != INF || a1[N] != INF) printf("Kkeo-eok\n");
	else printf("Zzz");

	return 0;
}