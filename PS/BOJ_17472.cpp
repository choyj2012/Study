#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define Max 100

struct _edge {
	int s, e, w;
};
int N, M, t;
int n_island;
int answer;
bool isconnect;
vector<vector<int>> map;
vector<vector<int>> dist;
vector<int> uni;
vector<_edge> edge;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void print_map();
void init();
void div_island();
void bfs(int y, int x, int num);
void check_dis();
void add_edge();
int mst();

int main() {

	freopen("input.txt", "r", stdin);
	
	init();
	div_island();

//	print_map();
	dist.resize(n_island + 1, vector<int>(n_island + 1, Max));
	check_dis();


	uni.resize(n_island + 1);
	for (int i = 1; i <= n_island; i++) uni[i] = i;

	add_edge();
	
	if (mst() == n_island - 1)
		printf("%d\n", answer);
	else
		printf("-1\n");
	return 0;
}

bool comp(const _edge A, const _edge B) {
	return A.w < B.w;
}
void init() {
	scanf("%d %d", &N, &M);
	map.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &t);
			if (t == 1) t = -1;
			map[i].push_back(t);
		}
	}
}
void div_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				bfs(i, j, ++n_island);
			}
		}
	}
}
void bfs(int y, int x, int num) {

	vector<vector<bool>> check(N, vector<bool>(M, false));
	deque<pair<int, int>> Q;
	Q.push_front({ y, x });
	map[y][x] = num;

	while (!Q.empty()) {
		
		int y = Q.back().first;
		int x = Q.back().second;
		Q.pop_back();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == -1) {
				Q.push_front({ ny, nx });
				map[ny][nx] = num;
			}
		}
	}
}
void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void check_dis() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (map[i][j] > 0) {

				for (int k = 0; k < 4; k++) {
					int ny = i, nx = j;
					int d = 0;
					while (1) {
						ny += dy[k];
						nx += dx[k];
						d++;
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || map[i][j] == map[ny][nx])
							break;

						if (map[ny][nx] != 0) {
							if (d >= 3) {
								dist[map[i][j]][map[ny][nx]] = min(dist[map[i][j]][map[ny][nx]], d - 1);
								dist[map[ny][nx]][map[i][j]] = dist[map[i][j]][map[ny][nx]];
							}

							break;
						}
					}
				}
			}
		}
	}
}
void add_edge() {
	for (int i = 1; i <= n_island; i++) {
		for (int j = i + 1; j <= n_island; j++) {

			if (dist[i][j] != Max) {
				edge.push_back({ i, j, dist[i][j] });
			}
		}
	}

	sort(edge.begin(), edge.end(), comp);
}
int union_find(int island) {
	if (uni[island] == island)
		return island;
	else
		return uni[island] = union_find(uni[island]);
}
int mst() {

	int n_brige = 0;
	for (int i = 0; i < edge.size(); i++) {

		int u1 = union_find(edge[i].s);
		int u2 = union_find(edge[i].e);
		
		if (u1 == u2) continue;

		uni[u1] = uni[u2];
		answer += edge[i].w;
		n_brige++;
	}
	return n_brige;
}