/**
*	39Á¡ (n<=1000)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, k, m;
		string str;
		cin >> n >> k >> m;
		cin >> str;
		int len = str.size();
		Answer = 0;
		int idx = -1;
		while (idx < len) {
			string t = str;
			if (idx >= 0) {
				if (t[idx] == '1') {
					idx++;
					continue;
				}
				else t[idx] = '1';
			}
			vector<int> num;
			for (int i = 0; i < n - k + 1; i++) {
				num.push_back(atoi(t.substr(i, k).c_str()));
			}
			sort(num.begin(), num.end());
			for (auto a = num.begin(); a != num.end(); a++) {
				auto b = upper_bound(a + 1, num.end(), *a + m);
				Answer = max(Answer, (int)distance(a, b));
			}

			idx++;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}