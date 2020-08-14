#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length())
		if (a < b)
			return true;
	return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> rwords = words;
	for (int i = 0; i < words.size(); i++) {
		reverse(rwords[i].begin(), rwords[i].end());
	}

	sort(words.begin(), words.end(), compare);
	sort(rwords.begin(), rwords.end(), compare);

	int idx, lo, hi;
	for (int i = 0; i < queries.size(); i++) {
		if (queries[i].front() == '?') {
			reverse(queries[i].begin(), queries[i].end());
			idx = queries[i].find_first_of('?');
			
			for (int j = idx; j < queries[i].length(); j++) queries[i][j] = 'a';
			lo = lower_bound(rwords.begin(), rwords.end(), queries[i], compare) - rwords.begin();
			for (int j = idx; j < queries[i].length(); j++) queries[i][j] = 'z';
			hi = upper_bound(rwords.begin(), rwords.end(), queries[i], compare) - rwords.begin();
		}
		if (queries[i].back() == '?') {
			idx = queries[i].find_first_of('?');

			for (int j = idx; j < queries[i].length(); j++)queries[i][j] = 'a';
			lo = lower_bound(words.begin(), words.end(), queries[i], compare) - words.begin();
			for (int j = idx; j < queries[i].length(); j++) queries[i][j] = 'z';
			hi = upper_bound(words.begin(), words.end(), queries[i], compare) - words.begin();
		}

		answer.push_back(hi - lo);
	}

	
	return answer;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int nword, nquery;
	cin >> nword >> nquery;
	vector<string> Words;
	vector<string> Query;
	string str;
	for (int i = 0; i < nword; i++) {
		cin >> str;
		Words.push_back(str);
	}
	for (int i = 0; i < nquery; i++) {
		cin >> str;
		Query.push_back(str);
	}

	for (int k : solution(Words, Query)) {
		cout << k << "\n";
	}
	return 0;
}