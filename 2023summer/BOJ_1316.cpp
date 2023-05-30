#include <iostream>
#include <string>
using namespace std;

int N;
string str;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		bool check[26] = { false, };
		cin >> str;
		bool flag = true;
		check[str[0] - 'a'] = true;

		for (int i = 1; i < str.size(); i++) {
			if (str[i] == str[i - 1]) continue;
			
			if (check[str[i] - 'a']) {
				flag = false;
				break;
			}
			check[str[i] - 'a'] = true;
		}
		
		if (flag) ans++;
	}

	cout << ans << "\n";
	return 0;
}