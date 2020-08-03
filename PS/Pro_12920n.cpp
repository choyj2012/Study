/*
*	선입 선출 스케줄링
*	https://programmers.co.kr/learn/courses/30/lessons/12920
*	효율성 테스트 통과못했음.
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n_work, n_core;
int work_num;
vector<int> core;

struct job {
	int s_time;
	int e_time;
	int core_num;
	int job_num;
};

struct compare {
	bool operator()(job &i, job &j) {
		if (i.e_time == j.e_time)
			return i.core_num > j.core_num;
		return i.e_time > j.e_time;
	}
};

priority_queue<job, vector<job>, compare> pq;

int solution(int n, vector<int> cores);

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n_work, &n_core);
	int t;
	for (int i = 1; i <= n_core; i++) {
		scanf("%d", &t);
		core.push_back(t);
	}
	

	printf("%d", solution(n_work, core));
	return 0;
}

int solution(int n, vector<int> cores){
	int answer = 0;

	work_num = 0;
	while (1) {
		work_num++;
		if (work_num <= n_core) {
			job j = { 0, cores[work_num - 1], work_num, work_num };
			pq.push(j);
		}
		else {

			job task = pq.top();
			job next;

			next.s_time = task.e_time;
			next.e_time = next.s_time + cores[task.core_num - 1];
			next.core_num = task.core_num;
			next.job_num = work_num;
			pq.pop();
			pq.push(next);

			if (work_num == n_work) {
				answer = next.core_num;
				break;
			}
		}
	}

	return answer;
}