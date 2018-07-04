#include<iostream>
#include<vector>
using namespace std;
int* A;
int max_number = 0;
int max(int a, int b) {
	if(a > b) return a;
	return b;
}
void change(vector<int>& v, int a, int b) {
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void permutation(vector<int> v, int depth, int depth_end) {
	if (depth == depth_end) {
		int interval = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			interval += abs(v[i]-v[i+1]);
		}
		max_number = max(max_number, interval);
		return;
	}
	for (int i = depth; i < depth_end; i++) {
		change(v, depth, i);
		permutation(v, depth + 1, depth_end);
	}
}
int main() {
	int N;
	cin >> N;
	A = new int[N];
	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		v.push_back(A[i]);
	}
	permutation(v, 0, N);
	cout << max_number << endl;
}