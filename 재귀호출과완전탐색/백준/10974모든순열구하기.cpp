#include<iostream>
#include<vector>
using namespace std;
//N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램
//break, continue 차이는 break는 조건 걸리면 for문 탈출, continue는 조건 걸리면 그다음 순서로
//boolean 배열은 맨처음 초기화 0으로 되니깐 false를 반환한다.

void permutation(vector<int>& pick,int N,bool* b) {
	if (pick.size() == N) {
		for (int i = 0; i < pick.size(); i++) {
			cout << pick[i] << " ";
		}
		cout << endl;
	}
	for (int j = 1; j <= N; j++) {
		if (b[j]) continue;
		b[j] = true;
		pick.push_back(j);
		permutation(pick, N, b);
		pick.pop_back();
		b[j] = false;
	}
}
int main() {
	int N;
	vector<int> v;
	cin >> N;
	bool *b = new bool[N + 1]();
	// 동적할당 new에서 메모리 0으로 초기화하려면 뒤에 ()붙여줘야 함
	permutation(v,N,b);
}