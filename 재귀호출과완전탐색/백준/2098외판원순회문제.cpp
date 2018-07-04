#include<iostream>
#include<vector>
using namespace std;
vector<int> value;
int sum = 0;
int **W;
int min = 1000000;
int find_min(int a, int b) {
	if (a < b) return a;
	return b;
}
void change(vector<int>& vec, int a, int b) {
	int temp = vec[a];
	vec[a] = vec[b];
	vec[b] = temp;
}
void permutation(vector<int> v, int depth, int depth_end) {
	if (depth == depth_end) {
		sum = 0;
		for (int l = 0; l < v.size()-1;l++) {
			sum += value[(v[l] - 1) * depth_end + (v[l + 1] - 1)];
		}
		sum += value[(v[v.size()-1] - 1)*depth + (v[0] - 1)];
		min = find_min(min, sum);
		return;
	}
	for (int j = depth; j < depth_end; j++) {
		change(v, depth, j);
		permutation(v, depth + 1, depth_end);
	}
}
int main() {
	int N;
	cin >> N;
	W = new int *[N];
	for (int i = 0; i < N; i++) {
		W[i] = new int[N];
	}
	vector<int> order;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
			value.push_back(W[i][j]);
		}
	}
	for (int k = 0; k < N; k++) {
		order.push_back(k + 1);
	}
	permutation(order, 0, N);
	cout << min;
	return 0;
}