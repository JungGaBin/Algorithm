
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	int N,M,K;
	scanf("%d %d %d", &N, &M, &K);
	vector<long long> a(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	init(a, tree, 1, 0, N - 1);
	//M += K;
	for (int i = 0; i < M + K; i++) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			b = b - 1;
			long long diff = c - a[b];
			a[b] = c;
			// b번째수를 c로 바꾼다.
			update(tree,1,0,N-1,b,diff);
		}
		else if (t1 == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(tree, 1, 0, N - 1, b - 1, c - 1));
		}

	}
}