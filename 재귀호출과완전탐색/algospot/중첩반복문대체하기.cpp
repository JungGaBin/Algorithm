// n개의 원소 중(0~n-1) 4개를 고르는 모든 경우를 출력하는 경우의 수
#include <iostream>
using namespace std;

int recursive(int N,int count, int smallest) {
	// N개에서 4개를 구하세요
	if (count == 1) { // 4개를 다 뽑았다
		
		return recursive(N - 1, 4, smallest);
	}
	else { // 4개 아직 안뽑았다.
		// 최소값 구하기
		cout << smallest; // smallest보다 큰걸 뽑으면 됨
		return recursive(N-1, count- 1, smallest);
	}
}

int main() {
	int N;
	cin >> N; 
	//(1) 중첩 반복문으로 하는 방법
	// N이 5라면 0123 0124 0134 0234 1234
	// N이 6이라면 0123 0124 0125 0134 0135 0145
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
	// (2) 재귀함수 호출하기
	cout << recursive(N,4,0);

}