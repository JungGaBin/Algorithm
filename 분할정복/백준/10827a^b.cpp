//�Ǽ� a�� ���� b�� �־����� ��, a�� b������ ��Ȯ�ϰ� ����ϴ� ���α׷�
#include <iostream>
#include <limits>
using namespace std;

typedef std::numeric_limits< double > dbl;
double powfunction(double a, int b) {
	double half;
	if (b == 1) return a;
	else if (b % 2 == 0) { // b�� ¦���϶�
		half = powfunction(a, b / 2);
		return half * half;
	}
	else { //b�� Ȧ���϶�
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