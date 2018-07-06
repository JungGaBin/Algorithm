#include<iostream>
using namespace std;
int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}

int fastSum(int n) {
	if (n == 1) return 1;
	else if(n % 2 == 0) return 2 * fastSum(n / 2) + (n / 2)*(n / 2);
	else return fastSum(n - 1) + n;
}

int main() {
	int N;
	cin >> N;

	//1) 재귀함수로 1+2+3+...+n을 계산한다면?
	cout << recursiveSum(N)<<endl;

	//2) Divide Conquer 방법을 이용하여 1+2+3+...+n을 계산한다면?
	cout << fastSum(N);
}