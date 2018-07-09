#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<pair<long long,long>> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node].first = a[start];
	}
	else {
		return tree[node].first = max(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}
long long initS(vector<long long> &a, vector<pair<long long, long>> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node].second = a[start];
	}
	else {
		return tree[node].second = min(initS(a, tree, node * 2, start, (start + end) / 2), initS(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}
long long  find_max(vector<pair<long long, long>> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return -1;
	}
	if (left <= start && end <= right) {
		return tree[node].first;
	}
	return max(find_max(tree, node * 2, start, (start + end) / 2, left, right), find_max(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
long long  find_min(vector<pair<long long, long>> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 98798765432;
	}
	if (left <= start && end <= right) {
		return tree[node].second;
	}
	return min(find_min(tree, node * 2, start, (start + end) / 2, left, right), find_min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<long long> a(N);
	int h = (int)ceil(log2(N));
	int tree_number = (1 << (h + 1));
	vector<pair<long long, long>> tree(tree_number);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, N - 1);
	initS(a, tree, 1, 0, N - 1);
	long long t1, t2;
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld", &t1, &t2);
		printf("%lld %lld\n", find_min(tree, 1, 0, N - 1, t1 - 1, t2 - 1), find_max(tree, 1, 0, N - 1, t1 - 1, t2 - 1));
	}
}