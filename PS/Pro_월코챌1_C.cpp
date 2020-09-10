#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 1000001
#define SIZE ((1<<20)+1)
int seg[SIZE*2];

int query(int L, int R) {

	int ans = MAX;
	L += (1 << 20);
	R += (1 << 20);

	while (L < R) {
		if (L % 2 == 1) {
			ans = ans > seg[L] ? seg[L] : ans;
			L++;
		}
		if (R % 2 == 0) {
			ans = ans > seg[R] ? seg[R] : ans;
			R--;
		}

		L /= 2;
		R /= 2;
	}
	if (L == R) ans = ans > seg[L] ? seg[L] : ans;
	return ans;
}

int solution(vector<int> a) {
	int answer = 0;
	
	int cap = 1 << 20;
	fill(seg, seg + SIZE*2, MAX);
	for (int i = cap; i < cap + a.size(); i++)
		seg[i] = a[i - cap];
	for (int i = cap - 1; i > 0; i--)
		seg[i] = seg[i * 2] < seg[i * 2 + 1] ? seg[i * 2] : seg[i * 2 + 1];

	for (int i = 0; i < a.size(); i++) {
		int l = MAX, r = MAX;
		int num = a[i];

		if (i > 0)
			l = query(0, i - 1);
		if (i < a.size()-1)
			r = query(i + 1, a.size()-1);

		bool flag1, flag2;

		if (l < num) flag1 = false;
		else flag1 = true;

		if (r < num) flag2 = false;
		else flag2 = true;

		if (flag1 || flag2) {
			answer++;
			printf("%d\n", num);
		}
	}
	return answer;
}


int main() {
	freopen("input.txt", "r", stdin);

	int n, t;
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		v.push_back(t);
	}

	cout << solution(v);
	return 0;
}