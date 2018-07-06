// ��Ȥ ���ٰ� 2.35, 4.778 �̷� ������ �Է��� �־����� ��찡 �ֽ��ϴ�. 
// �̷� �ͺ��� �츮�� ���� �Ҽ��� ����̶�� �ؿ�. 
// �׷��� ��ǻ�ʹ� ���� ������ �־�����, ���̰�����, ������ ����� �˴ϴ�. 
// �׷��� ������ ��Ȯ�� ���� �䱸�ϴ� ��쿡, double���̳� float ������ ó���ϸ� Ʋ���� �˴ϴ�.
// �� ���, �츮�� ���� ���� �Ҽ����� �м��� �ٲ���� �մϴ�.

#include <iostream>
#include <sstream>
#include <string.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
char silsu[100];
char* integer; 
char* decimal;
int bunja,bunmo;
int sum_bunja,sum_bunmo;
int point;
int b;
int calc_loc(char *sosu) {
	const char *rr;
	if ((rr = strchr(sosu, '.')) != NULL)
		return rr - sosu;
	return -1;
}
void makeInteger(char *s, int start, int end) {
	integer=new char[point];
	for (int i = start; i <= end; i++) {
		integer[i] = s[i];
	} 
}
void makeDecimal(char *s, int start, int end) {
	decimal = new char[b-1];
	for (int i = start; i <= end; i++) {
		//cout << s[i] << " ";
		decimal[i - point-1] = s[i];
		//cout << i - point - 1;
	}
}
int int_width(int num)
{
	int ret;
	if (num < 0) num = -num;
	for (ret = 0; num > 0; num /= 10, ret++) /* NULL */;
	return ret;
}
int main() {
	int length = 0;
	for (int i = 0; i < 100; i++) {
		silsu[i]=cin.get();
		if (silsu[i] == '\n') {
			length = i - 1;
			break;
		}
	}
	point = calc_loc(silsu);
	if (point == -1) {
		bunja = atoi(silsu);
		cout << bunja;
		return 0;
	}
	b = length - point; // 10�� b�� ���ϱ�
	//cout << point <<" "<< length<<  endl;  // .��ġ �ľ� 
	
	// .�� �������� ���� ����, �޺κ��� �Ҽ��κ��� �ȴ�
	makeInteger(silsu,0,point-1); // �����κ�(point)
	makeDecimal(silsu,point+1,length); // �Ҽ��κ�(b)
	// atoi ���� �ȵ� 0.00������
	bunja = atoi(integer);
	//cout << endl << "�����κ�: " << bunja << endl;

	bunmo = atoi(decimal);
	//cout << endl << "�Ҽ��κ�: "<< bunmo << endl;
	// �� ���ǥ���ǳ�?
	sum_bunja = bunja*pow(10.0, (double)b) + bunmo;
	sum_bunmo = pow(10.0, (double)b);
	int width;
	//cout << bunja*pow(10.0,(double)b) + bunmo;
	if (sum_bunja >= sum_bunmo) {
		if (sum_bunmo == 1.0) {
			cout << sum_bunja << endl;
		}
		else {
			width = int_width(sum_bunja);
			//cout << b << " " << width << endl;
			cout << sum_bunja / sum_bunmo+ bunmo*pow(10.0, (double)(-1.0)*b);
			//cout<< sum_bunja%sum_bunmo;
		}
	}
	else {
		width = int_width(sum_bunja);
		//cout << b << " "<< width << endl;
		//cout << sum_bunja << endl;
		cout << sum_bunja/sum_bunmo;
		cout << ".";
		for (int i = 0; i < b - width; i++) {
			cout << "0";
		}
		cout << sum_bunja%sum_bunmo ;
	}

	//cout << bunja << "." << bunmo << endl;
	
}