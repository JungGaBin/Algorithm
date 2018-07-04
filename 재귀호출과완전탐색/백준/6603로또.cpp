#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vi;
vector<int> c;
void combination(vector<int> v, int n, int count) {
	if (count == 0) {
		for (int j = 0; j < v.size(); j++) {
			cout << vi[v[j]] << " ";
		}
		cout << endl;
	}
	int smallest = v.empty() ? 0 : v.back()+1;
	for (int j = smallest; j < n; j++) {
		v.push_back(j);
		combination(v, n, count - 1);
		v.pop_back();
	}
}
int main() {
	int k;
	int t;
	while (true) {
		cin >> k;
		vi.clear();
		c.clear();
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> t;
			vi.push_back(t);
		}
		combination(c, k, 6);
		cout << endl;
	}
}