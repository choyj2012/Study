//프로그래머스 월간 코드 챌린지 9월 3번
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000001
#define CAPACITY (1 << 20)
vector<int> seg(CAPACITY*2, MAX);

int check(int l, int r) {

	int mm = MAX;
	l += CAPACITY;
	r += CAPACITY;

	while (l <= r) {

		if (l % 2 == 1) mm = min(mm, seg[l++]);
		if (r % 2 == 0) mm = min(mm, seg[r--]);

		l /= 2;
		r /= 2;
	}
	return mm;
}

int solution(vector<int> a) {
	int answer = 2;
	
	for (int i = 0; i < a.size(); i++) {
		seg[CAPACITY + i] = a[i];
	}
	for (int i = CAPACITY - 1; i > 0; i--) {
		seg[i] = seg[i * 2] > seg[i * 2 + 1] ? seg[i * 2 + 1] : seg[i * 2];
	}

	
	for (int i = 1; i < a.size() - 1; i++) {
		int L = check(0, i - 1);
		int R = check(i + 1, a.size() - 1);

		bool flag1 = false, flag2 = false;

		if (a[i] < L) flag1 = true;
		if (a[i] < R) flag2 = true;

		if (flag1 || flag2) answer++;
	}
	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	vector<int> a;
	int N, t;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		a.push_back(t);
	}

	printf("%d", solution(a));
	return 0;
}
/* 다른 풀이
#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(vector<int> a) {
	int answer = a.size();
	stack<int> stack;
	for (int comp : a) {
		while (!stack.empty() && comp < stack.top()) {
			stack.pop();
			if (!stack.empty())
				answer--;
		}
		stack.push(comp);
	}
	return answer;
}
*/