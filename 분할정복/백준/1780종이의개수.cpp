#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N; 
int Paper[2200][2200];
int cnt[3] = { 0,0,0 };
void solve(int x, int y, int size) {
	if (size == 1) {
		int num = Paper[y][x] + 1;
		cnt[num]++;
		return;
	}
	bool same = true;
	int first = Paper[y][x];
	for (int sy = y; sy < y + size; sy++) {
		if (!same) break;
		for (int sx = x; sx < x + size; sx++) {
			if (first != Paper[sy][sx]) {
				same = false;
				break;
			}
		}
	}
	if (same) {
		int num = Paper[y][x] + 1;
		cnt[num]++;
		return;
	}
	int newsize = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + newsize*i, y + newsize*j, newsize);
		}
	}

}
int main() {
	//freopen("a.txt", "r", stdin);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Paper[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i]<< endl;
	}
	return 0;
}