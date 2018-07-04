#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int sum = 0;
vector<int> vt;
vector<int> c;
void combination(vector<int> v, int n, int topick) {
	if (topick == 0) {
		sum = 0;
		for (int j = 0; j < v.size(); j++) {
			sum += vt[v[j]];
		}
		if (sum == 100) {
			for (auto it : v) {
				cout << vt[it] << endl;
			}
		}
	}
	int smallest = v.empty() ? 0 : v.back() + 1;
	for (int k = smallest; k < n; k++) {
		v.push_back(k);
		combination(v, n, topick - 1);
		v.pop_back();
	}
}
int main() {
	int t;
	for (int i = 0; i < 9; i++) {
		cin >> t;
		vt.push_back(t);
	}
	sort(vt.begin(), vt.end());
	combination(c, 9, 7);
}
