#include <iostream>
using namespace std;

// 1���� n������ ���� ����ϴ� �ݺ��Լ��� ����Լ�
int sum(int N) {
	int s=0;
	for (int i = 1; i <= N; i++) {
		s += i;
	}
	return s;
}
int rs = 0;
/*
int recursiveSum(int n){
	if(n==1) return 1;
	return n+recursiveSum(n-1);
}
*/
int recursivesum(int N) {
	if (N == 0) {
		return rs;
	}
	else {
		rs += N;
		N--;
		recursivesum(N);
	}
}
int main() {
	int N;
	cin >> N;
	cout << "�ݺ��Լ�" << sum(N) << endl;
	cout << "����Լ�" << recursivesum(N) << endl;
}