#include<iostream>
#include<vector> 
using namespace std;
void change(vector<int>& v, int a, int b) {
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void permutation(vector<int> pick, int depth, int depth_end) {
	if (depth==depth_end) {
		for (auto it : pick) { // �ð����̴� ��� 1) auto ����ϱ�
			cout << it << " ";
		}
		puts(""); // �ð����̴� ��� 2 cout���ٴ� puts�� 
		return;

	}
	for (int j = depth; j < depth_end; j++) {
		change(pick, depth, j);
		permutation(pick, depth + 1, depth_end);
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		v.push_back(i + 1);
	}
	permutation(v, 0, N);
	return 0;
}