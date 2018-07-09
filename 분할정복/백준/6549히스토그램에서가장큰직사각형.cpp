#include <iostream>
#include <stack>
using namespace std;
int a[100000];
int main() {
	int n;
	cin >> n;
	for (;;) {
		if (n == 0) break;
		for (int i = 0; i<n; i++) {
			cin >> a[i];
		}
		stack<int> s;
		while (!s.empty()) s.pop();
		int ans = 0;

		for (int i = 0; i<n; i++) {
			while (!s.empty() && a[s.top()] > a[i]) {
				int height = a[s.top()];
				s.pop();
				int width = i;
				if (!s.empty()) {
					width = (i - s.top() - 1);
				}
				if (ans < width*height) {
					ans = width*height;
				}
			}
			s.push(i);
		}
		while (!s.empty()) {
			int height = a[s.top()];
			s.pop();
			int width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < width*height) {
				ans = width*height;
			}
		}
		cout << ans <<endl;

		cin >> n;
	}
	return 0;
}