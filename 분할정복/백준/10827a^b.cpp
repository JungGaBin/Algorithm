//실수 a와 정수 b가 주어졌을 때, a의 b제곱을 정확하게 계산하는 프로그램
#include <iostream>
#include <limits>
using namespace std;

typedef std::numeric_limits< double > dbl;
double powfunction(double a, int b) {
	double half;
	if (b == 1) return a;
	else if (b % 2 == 0) { // b가 짝수일때
		half = powfunction(a, b / 2);
		return half * half;
	}
	else { //b가 홀수일때
		return powfunction(a, b - 1)*a;
	}

}
int main() {
	double a;
	int b;
	cin >> a >> b;
	//cout.precision(20);
	cout.precision(dbl::max_digits10);
	cout << fixed << powfunction(a, b) << endl;
	cout << powfunction(a, b);
	//printf("%20.18f\n", powfunction(a, b));
}