#include <iostream>
using namespace std;
int A[7];
int tmp[7];
int N;
// 쪼개고, 정렬하고, 합치고

void ArrayMerge(int start, int end, int arr[]) {
	int mid;
	mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			tmp[k] = arr[i];
			i++;
		}
		else {
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}
	int t;
	if (i > mid)
		t = j;
	else
		t = i;

	for (k; k <= end; k++, t++) {
		tmp[k] = arr[t];
	}
	for (k = 0; k <= end; k++) {
		arr[k] = tmp[k];
	}

}
void MergeSort(int start, int end, int arr[]) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2; // 중간인덱스 구하고
		MergeSort(start, mid, arr);// 잘라라
		MergeSort(mid + 1, end, arr);
		ArrayMerge(start, end, arr);
	}
}

int main() {
	// 38 27 43 9 3 82 10 [7개]
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	MergeSort(0, N - 1, A);

	// MergeSort 정렬 후
	for (int i = 0; i < N; i++) {
		cout << A[i]<< " ";
	}
	return 0;

}