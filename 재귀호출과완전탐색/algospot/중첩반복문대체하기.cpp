// n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
#include <iostream>
#include <vector>
using namespace std;

void recursive(int N,vector<int>& picked, int topick) {
	if (topick == 0) {
		for (int i = 0; i < picked.size(); ++i) {
			cout << picked[i] << " ";
		}
		cout << endl;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int j = smallest; j < N; j++) {
		picked.push_back(j);
		recursive(N, picked, topick - 1);
		picked.pop_back();
	}
}

int main() {
	int N,M;
	cin >> N >> M; 
	vector<int> v;
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
	recursive(N, v, M);
	return 0;
}
