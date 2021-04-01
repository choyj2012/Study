#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1000000000

int main() {

	freopen("input.txt", "r", stdin);

	int N, M;
	pair<int, int> Cpos[2];
	scanf("%d %d", &M, &N);
	vector<vector<int>> map(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> check(N + 1, vector<int>(M + 1, MAX));

	char t;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &t);

			if (t == '.') continue;

			if (t == '*') map[i][j] = -1;
			else {
				Cpos[idx++] = { i, j };
				map[i][j] = -2;
			}
		}
	}

	vector<pair<int, int>> list = { { Cpos[0].first, Cpos[0].second } };
	vector<pair<int, int>> prelist;

	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	int cnt = 0;
	while (1) {

		prelist = list;
		list.clear();

		for (int i = 0; i < prelist.size(); i++) {
			

			for (int j = 0; j < 4; j++) {

				int ny = prelist[i].first;
				int nx = prelist[i].second;

				while (1) {

					ny += dy[j];
					nx += dx[j];

					if (ny > N || ny < 1 || nx > M || nx < 1 ||
						map[ny][nx] == -1 || cnt > check[ny][nx])
						break;

					check[ny][nx] = cnt;
					list.push_back({ ny, nx });

					if (Cpos[1].first == ny && Cpos[1].second == nx) {
						printf("%d", check[ny][nx]);
						return 0;
					}
				}

			}

		}
		cnt++;

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (check[i][j] == MAX) printf("%2d ", -1);
				else printf("%2d ", check[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
}