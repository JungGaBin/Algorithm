// ��ȣ: ���δٸ� L���� ���ĺ� �ҹ���,
// �ּ� �Ѱ��� ����+ �ּ� �ΰ��� ����
// ���ĺ��� �����ϴ� ��������,,
// ��ȣ�� ������� ���� ������ ���� C����
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<int> integer;
vector<char> word;
vector<int> order;
int ja, mo;
int L, C;
int validate = 0;
void combination(vector<int> v, int N, int topick) {
	if (topick == 0) {
		ja = 0;
		mo = 0;
		for (int t = 0; t < v.size(); t++) {
			if (word[v[t]] == 'a')
				mo += 1;
			else if (word[v[t]] == 'e')
				mo += 1;
			else if (word[v[t]] == 'i')
				mo += 1;
			else if (word[v[t]] == 'o')
				mo += 1;
			else if (word[v[t]] == 'u')
				mo += 1;
			else
				ja += 1;
			
		}
		//cout << " ���� " << mo << " ���� " << ja << endl;
		//validate.push_back(pair<int, int>(mo, ja));
		for (int t = 0; t < v.size(); t++) {
			if (mo < 1 || ja < 2) {
				validate = 1;
				continue;
			}
			cout << word[v[t]];
		}
		if (validate == 1) {
			validate = 0;
		}
		else {

			cout << endl;
		}
		//cout << endl;
	}
	int smallest = v.empty() ? 0 : v.back() + 1;
	for (int j = smallest; j < N; j++) {
		v.push_back(j);
		combination(v, N, topick - 1);
		v.pop_back();
	}
}
int main() {
	char t;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> t;
		integer.push_back(t);
	}
	sort(integer.begin(), integer.end());
	for (auto it : integer) {
		word.push_back(it);
	}
	combination(order,C,L);
}
// int a= 'A';
// cout << a << endl; (�ƽ�Ű�ڵ尪 Ȯ���ϴ¹�)
// char b=65; (65�� ���ڷ� ǥ��)
// cout << b << endl;