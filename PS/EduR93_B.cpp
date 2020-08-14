#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int T, n;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		vector<int> v;
		int cnt = 0;
		string str;
		cin >> str;
		for(auto k : str){
			if (k == '1') {
				cnt++;
			}
			else {
				if(cnt > 0)
					v.push_back(cnt);
				cnt = 0;
			}
		}
		if (cnt > 0) v.push_back(cnt);

		sort(v.begin(), v.end(), compare);
		int answer = 0;
		for (int i = 0; i < v.size(); i += 2) {
			answer += v[i];
		}
		printf("%d\n", answer);
	}
	return 0;
}