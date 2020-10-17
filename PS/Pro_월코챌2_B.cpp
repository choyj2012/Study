#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
int cnt[2];
vector<vector<int>> arr;

void q(int sy, int ey, int sx, int ex) {

	bool flag = true;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (arr[sy][sx] != arr[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag == true) {
		cnt[arr[sy][sx]]++;
		return;
	}

	q(sy, (sy + ey) / 2, sx, (sx+ex) / 2);//1
	q(sy, (sy + ey) / 2, (sx + ex)/2 + 1, ex);//2
	q((sy+ey)/2+1, ey, sx, (sx + ex)/2);//3
	q((sy+ey)/2+1, ey, (sx + ex)/2+1, ex);
}

vector<int> solution(vector<vector<int>> a) {
	vector<int> answer;
	arr = a;


	q(0, a.size() - 1, 0, a.size() - 1);
	return answer = { cnt[0], cnt[1] };
}

int main() {

	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	auto k = solution(arr);
	printf("%d %d", k[0], k[1]);
	return 0;
}