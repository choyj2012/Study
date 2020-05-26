#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;


vector<int> v;
int n, i;

void Push(int x) {
	v.push_back(x);
}

int Pop() {
	if (v.size() == 0) return -1;

	int t = v.back();
	v.pop_back();
	return t;
}

int Size() {
	return v.size();
}

int Empty() {
	if (v.size() == 0)return 1;
	else return 0;
}

int Top() {
	if (v.size() == 0) return -1;
	else return v.back();
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		char cm[10];
		int x;
		scanf("%s %d", cm, &x);
		if (!strcmp(cm, "push"))
			Push(x);
		if (!strcmp(cm, "pop"))
			printf("%d\n", Pop());
		if (!strcmp(cm, "size"))
			printf("%d\n", Size());
		if (!strcmp(cm, "empty"))
			printf("%d\n", Empty());
		if (!strcmp(cm, "top"))
			printf("%d\n", Top());
	}
	return 0;
}