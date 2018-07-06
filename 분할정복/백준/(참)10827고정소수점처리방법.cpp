// 간혹 가다가 2.35, 4.778 이런 식으로 입력이 주어지는 경우가 있습니다. 
// 이런 것보고 우리는 고정 소수점 방식이라고 해요. 
// 그런데 컴퓨터는 저런 식으로 주어지면, 배우셨겠지만, 오차가 생기게 됩니다. 
// 그렇기 때문에 정확한 값을 요구하는 경우에, double형이나 float 형으로 처리하면 틀리게 됩니다.
// 그 경우, 우리는 먼저 고정 소수점을 분수로 바꿔줘야 합니다.

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
	b = length - point; // 10의 b승 곱하기
	//cout << point <<" "<< length<<  endl;  // .위치 파악 
	
	// .을 기준으로 앞은 정수, 뒷부분은 소수부분이 된다
	makeInteger(silsu,0,point-1); // 정수부분(point)
	makeDecimal(silsu,point+1,length); // 소수부분(b)
	// atoi 쓰면 안됨 0.00못구함
	bunja = atoi(integer);
	//cout << endl << "정수부분: " << bunja << endl;

	bunmo = atoi(decimal);
	//cout << endl << "소수부분: "<< bunmo << endl;
	// 총 어떻게표현되냐?
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