#include <iostream>
#include <vector>
using namespace std;
//완전탐색으로 풀어야됨
int W[15][15];
vector<int> order; // 가능한 순서구하기
int min = 1000000;
int sum = 0;
//컴파일에러뜨는 코드
int find_min(int a, int b) {
	if (a < b) return a;
	return b;
}
void change(vector<int>& v, int a, int b) {
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void permutation(vector<int> a, int depth, int depth_end) {
	if (depth == depth_end) {
		sum = 0;
		for (int it = 0; it < a.size()-1; it++) {
			sum += W[a[it] - 1][a[it + 1] - 1];
		}
		sum += W[a[a.size() - 1] - 1][a[0]-1];
		min = find_min(min, sum);
	}
	for (int i = depth; i < depth_end; i++) {
		change(a, depth, i);
		permutation(a, depth+1, depth_end);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		order.push_back(i + 1);
	}
	permutation(order,0 ,N );
	cout << min <<endl;
}