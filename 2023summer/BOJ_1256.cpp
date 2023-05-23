#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000000000;

int A, Z, K;
int dp[101][101];

int wordCnt(int a, int z) {

	if (a == 0 || z == 0) return dp[a][z] = 1;
	if (dp[a][z] != -1) return dp[a][z];

	dp[a][z] = wordCnt(a - 1, z) + wordCnt(a, z - 1);
	if (dp[a][z] > MAX) dp[a][z] = MAX + 1;

	return dp[a][z];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> A >> Z >> K;
	fill(&dp[0][0], &dp[101 - 1][101], -1);

	if (K > wordCnt(A, Z)) {
		cout << -1 << "\n";
		return 0;
	}
	
	string answer = "";

	while (1) {

		if (A == 0) {
			while (Z--) answer += "z";
			break;
		}

		if (Z == 0) {
			while (A--) answer += "a";
			break;
		}
		
		int num = wordCnt(A - 1, Z);
		if (K <= num) {
			answer += "a";
			A--;
		}
		else {
			answer += "z";
			Z--;
			K -= num;
		}
	}

	cout << answer << "\n";
	return 0;
}