#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define X first
#define H second

typedef long long ll;
typedef pair<ll, ll> pll;

ll n;
vector<pll> input() {
	ll x, h;
	vector<pll> t1;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &h);
		t1.push_back({ x, h });
	}
	vector<pll> t2;
	for (int i = 0; i < n; i++) {
		if (t2.empty()) t2.push_back(t1[i]);
		else {
			while (!t2.empty() && t2.back().H - t2.back().X <= t1[i].H - t1[i].X) {
				t2.pop_back();
			}
			t2.push_back(t1[i]);
		}
	}
	t1.clear();
	for (int i = t2.size() - 1; i >= 0; i--) {
		if (t1.empty()) t1.push_back(t2[i]);
		else {
			while (!t1.empty() && t1.back().X + t1.back().H <= t2[i].X + t2[i].H) {
				t1.pop_back();
			}
			t1.push_back(t2[i]);
		}
	}

	return t1;
}

void sol() {
	
	vector<pll> D = input();
	/*
	TODO:
	Convex Hull Trick
	*/
	return;
}

int main() {

	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}