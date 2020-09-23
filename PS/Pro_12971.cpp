#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
	int answer = 0;
	int s = sticker.size();
	if (s == 1) return sticker[0];

	vector<int> dp1(s, 0);
	vector<int> dp2(s, 0);

	dp1[1] = sticker.front();
	dp2[1] = sticker.back();

	for (int i = 2; i < s; i++) {
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i - 1]);
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[s - i]);
	}

	return answer = max(dp1.back(), dp2.back());
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> st(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &st[i]);
	}
	printf("%d", solution(st));
}