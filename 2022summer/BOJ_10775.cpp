#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<int> pre;

/* 첫번째 방법
bool union_find(int n) {
	if (n == pre[n]) {
		if (n == 0) return false;
		pre[n]--;
		return true;
	}
	bool ret = union_find(pre[n]);
	pre[n] = pre[pre[n]];
	return ret;
}
*/

int union_find(int n) {
	if (n == pre[n]) {
		if (n == 0) return 0;
		return --pre[n] + 1;
	}
	return pre[n] = union_find(pre[n]);
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	pre.resize(N + 1);
	for (int i = 0; i <= N; i++) pre[i] = i;

	int t;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d", &t);
		
		if(union_find(t) != 0) ans++;
		else break;
	}

	printf("%d", ans);
	return 0;
}