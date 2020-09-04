#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		string num;
		int di;
		cin >> num >> di;

		int digsum = 0;
		vector<int> numv;
		for (auto a = num.rbegin(); a != num.rend(); a++) {
			digsum += (*a - '0');
			numv.push_back(*a - '0');
		}
		numv.push_back(0);
		vector<int> answer;
		int idx = 0;
		while (digsum > di) {

			if (numv[idx] > 9) {
				numv[idx] -= 10;
				digsum -= 9;
				numv[idx + 1]++;
			}
			if (numv[idx] == 0) {
				answer.push_back(0);
				idx++;
				continue;
			}

			digsum = digsum - numv[idx] + 1;
			answer.push_back(10 - numv[idx]);
			numv[idx] = 0;
			numv[idx + 1]++;

			idx++;
		}

		if (answer.empty()) printf("0\n");
		else {
			bool flag = false;
			for (auto i = answer.rbegin(); i != answer.rend(); i++) {
				if (*i == 0 && flag == true) printf("%d", *i);
				if (*i != 0){
					printf("%d", *i);
					flag = true;
				}
			}
			printf("\n");
		}
	}
}