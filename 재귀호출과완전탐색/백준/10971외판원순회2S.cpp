#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int N, W[10][10];

int tsp(vector<int> path, vector<bool> visited, int cost) {
	if (path.size() == N) return cost + W[path.back()][0];
	int ret = 100000000;

	for (int i = 1; i < N; i++) {
		if (visited[i]) continue;
		int loc = path.back();
		if (W[loc][i] == 0) continue;
		path.push_back(i);
		visited[i] = true;
		ret = min(ret, tsp(path, visited, cost + W[loc][i]));
		visited[i] = false;
		path.pop_back();
	}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}

	vector<int> path(1, 0);//0으로 초기화된 원소가 1개인 vector 생성
	vector<bool> visited(N, false); // false로 초기화된 원소 N개인 vector 생성
	visited[0] = true;
	printf("%d", tsp(path, visited, 0));
	return 0;
}