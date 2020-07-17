#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c;
int t, t1, t2;
int answer = 0;
vector<vector<int>> map;	//인접리스트
vector<vector<int>> mst;	//세그먼트 트리
vector<pair<int, int>> Data; //idx=처음노드번호 first=색 second=order
vector<bool> visited;	//dfs ordering 방문체크
vector<int> L;	//쿼리에 줄때 살펴봐야하는 범위(L[idx] ~ R[idx])
vector<int> R;

int idx = 1;

void input();
int dfs(int node);
void buildtree();
int query(int l, int r, int color);
int bs(vector<int> d, int color);

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	input();
	return 0;
}

void input() {
	scanf("%d %d %d", &n, &m, &c);
	map.resize(n + 1);
	Data.resize(n + 1);
	visited.resize(n + 1);
	L.resize(n + 1);
	R.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		Data[i].first = t;
	}

	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &t1, &t2);
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}

	dfs(1);	//dfs-ordering
	buildtree();	//merge sort tree

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &t1, &t2);
		answer += query(L[t1], R[t1], t2);
		answer %= 1000000007;
	}

	printf("%d", answer);
	return;
}

int dfs(int node) {
	visited[node] = true;
	Data[node].second = idx++;
	int cnt = 1;

	for (auto i = map[node].begin(); i != map[node].end(); i++) {
		if (visited[*i] == false)
			cnt += dfs(*i);
	}

	L[node] = Data[node].second;
	R[node] = L[node] + cnt - 1;
	return cnt;
}

int cap;
void buildtree() {
	for (cap = 1; cap < n; cap *= 2);
	mst.resize(2 * cap);
	for (int i = 1; i <= n; i++) {
		mst[Data[i].second + cap - 1].push_back(Data[i].first);
	}

	for (int i = cap - 1; i > 0; i--) {
		mst[i].resize(mst[i * 2].size() + mst[i * 2 + 1].size());
		merge(mst[i * 2].begin(), mst[i * 2].end(), mst[i * 2 + 1].begin(), mst[i * 2 + 1].end(), mst[i].begin());
	}
}

int query(int L, int R, int color) {
	L += cap - 1;
	R += cap - 1;
	int cnt = 0;
	while (L < R) {
		if (L % 2 == 1) {
			cnt += distance(mst[L].begin(), upper_bound(mst[L].begin(), mst[L].end(), color));
			L++;
		}
		if (R % 2 == 0) {
			cnt += distance(mst[R].begin(), upper_bound(mst[R].begin(), mst[R].end(), color));
			R--;
		}
		L /= 2;
		R /= 2;
	}
	if (L == R) cnt += distance(mst[L].begin(), upper_bound(mst[L].begin(), mst[L].end(), color));

	return cnt;
}

//upper-bound 직접구현했을땐 시간초과나더니 distance쓰니까 AC뜨네
/*
int bs(vector<int> d, int color)
{
	int mid, start, end;
	start = 0, end = d.size();

	while (end > start)
	{
		mid = (start + end) / 2;
		if (d[mid] > color) 
			end = mid;
		else start = mid + 1;
	}
	return end;
}
*/


//첫 시도 메모리초과
/*
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c;
vector<vector<int>> mst;
vector<vector<int>> map;
vector<int> visited;

void dfs(int node);
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &m, &c);
	mst.resize(n + 1);
	visited.resize(n + 1);

	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		mst[i].push_back(t);
	}

	int t1, t2;
	map.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &t1, &t2);
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}

	dfs(1);
	int answer = 0;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &t1, &t2);
		sort(mst[t1].begin(), mst[t1].end());
		vector<int>::iterator it;
		int cnt = 0;
		for (it = mst[t1].begin(); it != mst[t1].end(); it++) {
			if (*it <= t2) cnt++;
			else break;
		}
		answer += cnt;
		if (answer > 1000000007) answer %= 1000000007;
	}

	printf("%d", answer);
}

void dfs(int node) {
	visited[node] = 1;
	vector<int>::iterator it;
	for (it = map[node].begin(); it != map[node].end(); it++) {
		if (visited[*it] == 0) {
			dfs(*it);
			mst[node].insert(mst[node].end(), mst[*it].begin(), mst[*it].end());
		}
	}
	
	return;
}
*/