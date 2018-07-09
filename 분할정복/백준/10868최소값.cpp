#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = min(init(a, tree, node * 2, start, (start + end) / 2) , init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}
long long  find_min(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 987987654321;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return min(find_min(tree, node * 2, start, (start + end) / 2, left, right) , find_min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
	int N,M;
	scanf("%d %d", &N,&M);

	vector<long long> a(N);
	int h = (int)ceil(log2(N));
	int tree_number = (1 << (h + 1));
	vector<long long> tree(tree_number);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, N - 1);
	long long t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld", &t1, &t2);
		printf("%lld\n", find_min(tree, 1, 0, N - 1, t1 - 1, t2 - 1));
	}
}