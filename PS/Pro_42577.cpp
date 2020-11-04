#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++) {
		
		string now = phone_book[i];
		string next = phone_book[i + 1].substr(0, now.size());

		if (now == next) return answer = false;
	}

	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	int N;
	vector<string> pb;
	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pb.push_back(tmp);
	}

	cout << solution(pb);

	return 0;
}