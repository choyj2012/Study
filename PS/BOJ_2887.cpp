#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


struct pos {
	int x, y, z;
	int idx;
};

struct edge {
	int s, e;
	int w;
};

vector<int> uni;

bool compx(const pos A, const pos B) {
	return A.x < B.x;
}
bool compy(const pos A, const pos B) {
	return A.y < B.y;
}
bool compz(const pos A, const pos B) {
	return A.z < B.z;
}
bool compw(const edge A, const edge B) {
	return A.w < B.w;
}

int union_find(int node) {
	if (uni[node] == node)
		return node;
	else
		return uni[node] = union_find(uni[node]);
}

int main(){
	
	freopen("input.txt", "r", stdin);
	
	int N;
	scanf("%d", &N);
	vector<pos> planet(N);
	vector<edge> adj;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &planet[i].x, &planet[i].y, &planet[i].z);
		planet[i].idx = i;
	}

	sort(planet.begin(), planet.end(), compx);
	for (int i = 0; i < N - 1; i++) {
		adj.push_back({ planet[i].idx, planet[i + 1].idx, planet[i + 1].x - planet[i].x });
	}

	sort(planet.begin(), planet.end(), compy);
	for (int i = 0; i < N - 1; i++) {
		adj.push_back({ planet[i].idx, planet[i + 1].idx, planet[i + 1].y - planet[i].y });
	}

	sort(planet.begin(), planet.end(), compz);
	for (int i = 0; i < N - 1; i++) {
		adj.push_back({ planet[i].idx, planet[i + 1].idx, planet[i + 1].z - planet[i].z });
	}

	sort(adj.begin(), adj.end(), compw);
	
	long long answer = 0;
	uni.resize(N);
	
	for (int i = 0; i < N; i++) uni[i] = i;
	
	for (int i = 0; i < adj.size(); i++) {

		int u1 = union_find(adj[i].s);
		int u2 = union_find(adj[i].e);

		if (u1 == u2) continue;
		
		uni[u1] = u2;
		answer += adj[i].w;
	}
	printf("%ld", answer);
	return 0;
}