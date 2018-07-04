#include<iostream>
#include<vector>
using namespace std;
//N�� �־����� ��, 1���� N������ ���� �̷���� ������ ���������� ����ϴ� ���α׷�
//break, continue ���̴� break�� ���� �ɸ��� for�� Ż��, continue�� ���� �ɸ��� �״��� ������
//boolean �迭�� ��ó�� �ʱ�ȭ 0���� �Ǵϱ� false�� ��ȯ�Ѵ�.

void permutation(vector<int>& pick,int N,bool* b) {
	if (pick.size() == N) {
		for (int i = 0; i < pick.size(); i++) {
			cout << pick[i] << " ";
		}
		cout << endl;
	}
	for (int j = 1; j <= N; j++) {
		if (b[j]) continue;
		b[j] = true;
		pick.push_back(j);
		permutation(pick, N, b);
		pick.pop_back();
		b[j] = false;
	}
}
int main() {
	int N;
	vector<int> v;
	cin >> N;
	bool *b = new bool[N + 1]();
	// �����Ҵ� new���� �޸� 0���� �ʱ�ȭ�Ϸ��� �ڿ� ()�ٿ���� ��
	permutation(v,N,b);
}