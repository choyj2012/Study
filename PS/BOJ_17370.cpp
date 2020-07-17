#include <stdio.h>
#include <vector>
using namespace std;

int n;
int answer;

void serch(int x, int y, int px, int py, int cnt, vector<vector<int>> check);

int main() {

	scanf("%d", &n);
	vector<vector<int>> check(60);
	check[0 + 30].push_back(0);

	serch(0, 1, 0, 0, 0, check);

	printf("%d", answer);
}

void serch(int x, int y, int px, int py, int cnt, vector<vector<int>> check) {

	printf("%d %d\n", x, y);
	if (cnt == n) return;
	//방문했던곳인 경우
	if (find(check[x + 30].begin(), check[x + 30].end(), y) != check[x+30].end()){
		if(cnt == n)
			answer++;
		return;
	}
	
	check[x + 30].push_back(y);

	if (px != x + 1 || px != y)
		serch(x + 1, y, cnt + 1, x, y, check);
	
	if (px != x - 1 || px != y)
		serch(x - 1, y, cnt + 1, x, y, check);

	if((x%2==0 && y%2==0) || (x%2==1 && y%2==1) && (px != x || px != y + 1))
		serch(x, y + 1, cnt + 1, x, y, check);
	else {
		if(px != x || px != y-1)
			serch(x, y - 1, cnt + 1, x, y, check);
	}
}