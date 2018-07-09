#include <cstdio>
#include <stack>
using namespace std;
int a[100000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = i;
		while (!s.empty() && a[s.top()] > a[i]) {
			int height = a[s.top()];
			s.pop();
			int width = i;
			if (!s.empty()) {
				width = (i - s.top() - 1);
			}
			if (ans < width*height)
				ans = width*height;
		}
		s.push(i);
	}
	while (!s.empty()){
		int height = a[s.top()];
		s.pop();
		int width = n;
		if (!s.empty()) {
			width = n - s.top() - 1;
		}
		if (ans < width*height)
			ans = width*height;
	}
	printf("%d\n", ans);
	return 0;
}