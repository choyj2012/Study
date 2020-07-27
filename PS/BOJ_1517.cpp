#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct D {
	int be_num;
	int be_idx;
	int af_num;
};

vector<D> d_list;
int n, t;
int tree_size;
long long answer;
vector<long long> segt;

bool compare1(D i, D j) {
	return i.be_num < j.be_num;
}

bool compare2(D i, D j) {
	return i.be_idx < j.be_idx;
}

void input(int num, int left, int right);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	d_list.resize(n);	//idx : 0~n-1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		d_list[i].be_num = t;
		d_list[i].be_idx = i;
	}
	sort(d_list.begin(), d_list.end(), compare1);

	d_list[0].af_num = 1;
	for (int i = 1; i < n; i++) {
		if (d_list[i].be_num > d_list[i - 1].be_num)
			d_list[i].af_num = d_list[i - 1].af_num + 1;
		else
			d_list[i].af_num = d_list[i - 1].af_num;
	}
	sort(d_list.begin(), d_list.end(), compare2);

	for (tree_size = 1; tree_size <= n; tree_size *= 2);
	segt.resize(tree_size * 2);

	for (auto i = d_list.rbegin(); i != d_list.rend(); i++) {
		input((*i).af_num, 1, tree_size);
	}

	printf("%lld", answer);
}


void input(int num, int left, int right) {
	int node = 1;
	while (1) {
		segt[node]++;
		if (left == right) break;

		int mid = (left + right) / 2;
		if (num > mid) {
			node = node * 2 + 1;
			answer += segt[node - 1];
			left = mid + 1;
		}
		else if (num <= mid) {
			node = node * 2;
			right = mid;
		}
	}
}