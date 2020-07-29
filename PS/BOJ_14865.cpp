#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000001
int n;
int px, py, x, y;
vector<int> xpos;
vector<pair<int, int>> opos;
vector<pair<int, int>> pos;
vector<pair<int, int>> v;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	opos.resize(n);
	pos.resize(n);
	int start;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &opos[i].first, &opos[i].second);
		if (opos[i].second < 0) start = i;
	}
	
	//시작점을 x축 아래로 설정하기위해서
	for (int i = 0; i < n; i++) {
		pos[i] = opos[(i + start) % n];
	}


	for (int i = 1; i <= n; i++) {

		//x축을 통과하는경우 판별
		if (pos[i%n].first == pos[i - 1].first &&
			((pos[i%n].second > 0 && pos[i - 1].second < 0) ||
			(pos[i%n].second < 0 && pos[i - 1].second > 0))) {

			//x축을 지나는 x좌표 저장
			xpos.push_back(pos[i - 1].first);

			//저장된 x좌표가 2개 -> ( )로 표현가능
			if (xpos.size() == 2) {
				//x좌표가 작은것을 (로, 큰것을 )로 표현
				if (xpos[0] > xpos[1]) swap(xpos[0], xpos[1]);
				v.push_back({ xpos[0], 1 });
				v.push_back({ xpos[1], 0 });
				xpos.clear();
			}
		}
	}

	//x좌표 기준으로 정렬
	sort(v.begin(), v.end());
	//1 -> ( , 0 -> )
	//( ( ) ( ) )

	int answer1 = 0, answer2 = 0;	//1 큰거 2작은거
	vector<int> stack;
	for (int i = 0; i < v.size(); i++) {

		//answer2 -> '('다음에 바로 ')'나오면 카운팅
		if (v[i].second == 1 && v[i + 1].second == 0) answer2++;

		//answer1 -> 스택이 비면 카운팅
		//스택이 비었다는것은 지금까지 나온 괄호의 쌍이 맞춰진것 -> 큰 괄호에 포함
		if (stack.empty()) answer1++;
		
		if (v[i].second == 1)
			stack.push_back(1);
		if (v[i].second == 0)
			stack.pop_back();
	}

	printf("%d %d", answer1, answer2);
	return 0;
}