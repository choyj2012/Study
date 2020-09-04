#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2000000001
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		int N, K;
		cin >> N >> K;
		vector<int> A;
		vector<int> B;
		int t;
		for (int i = 0; i < N; i++) {
			cin >> t;
			A.push_back(t);
		}
		for (int i = 0; i < N; i++) {
			cin >> t;
			B.push_back(t);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		for (int i = 0; i < K; i++) {
			if (Answer < A[i] + B[K - i - 1])
				Answer = A[i] + B[K - i - 1];
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}