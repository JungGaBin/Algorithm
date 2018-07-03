#include <iostream>
using namespace std;

// 1부터 n까지의 합을 계산하는 반복함수와 재귀함수
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
	cout << "반복함수" << sum(N) << endl;
	cout << "재귀함수" << recursivesum(N) << endl;
}