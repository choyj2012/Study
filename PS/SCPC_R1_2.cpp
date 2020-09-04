#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 3010


int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n, k;
		cin >> n >> k;

		vector<int> X(n + 1);
		vector<int> Y(n + 1);
		vector<int> dX(n + 1, -1);
		vector<int> dY(n + 1, -1);
		int cnt1 = 0, cnt2 = 0;

		for (int i = 1; i <= n; i++) {
			cin >> X[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> Y[i];
		}

		//cnt1 ¹«Á¶°ÇÀÌ±è
		//cnt2 ¹«Á¶°ÇÁü
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {

				bool flagY = true;
				bool flagX = true;
				if (i == 0 && j == 0) {
					cnt1++;
					continue;
				}

				if (dY[i] == -1 && dX[j] == -1) {
					cnt2++;
					dY[i] = 0;
					dX[j] = 0;
					continue;
				}
				
				if (dY[i] >= 0) {
					if (dY[i] + X[j] <= k) {
						cnt1++;
						dY[i] += X[j];
						if (dX[j] >= 0)
							dX[j] += Y[i];
						continue;
					}
					else 
						flagY = false;
				}
				else
					flagY = false;

				if (dX[j] >= 0) {
					if (dX[j] + Y[i] <= k) {
						cnt1++;
						dX[j] += Y[i];
						if (dY[i] >= 0)
							dY[i] += X[j];
						continue;
					}
					else flagX = false;
				}
				else
					flagX = false;

				if (!flagX && !flagY) {
					cnt2++;
					dY[i] = 0;
					dX[j] = 0;
				}
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << cnt1 << " " << cnt2 << endl;
	}

	return 0;
}