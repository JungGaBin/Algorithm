// n���� ���� ��(0~n-1) 4���� ���� ��� ��츦 ����ϴ� ����� ��
#include <iostream>
using namespace std;

int recursive(int N,int count, int smallest) {
	// N������ 4���� ���ϼ���
	if (count == 1) { // 4���� �� �̾Ҵ�
		
		return recursive(N - 1, 4, smallest);
	}
	else { // 4�� ���� �Ȼ̾Ҵ�.
		// �ּҰ� ���ϱ�
		cout << smallest; // smallest���� ū�� ������ ��
		return recursive(N-1, count- 1, smallest);
	}
}

int main() {
	int N;
	cin >> N; 
	//(1) ��ø �ݺ������� �ϴ� ���
	// N�� 5��� 0123 0124 0134 0234 1234
	// N�� 6�̶�� 0123 0124 0125 0134 0135 0145
	//             0234 0235 0345 1234 1235 2345
	// 0,1,2,3,4,5
	/*
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				for (int l = k + 1; l < N; l++) {
					cout << "[ " << i << " " << j << " " << k << " " << l << "]" << endl;
				}
			}
		}
	}
	*/
	// (2) ����Լ� ȣ���ϱ�
	cout << recursive(N,4,0);

}