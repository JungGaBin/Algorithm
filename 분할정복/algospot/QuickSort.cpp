#include <iostream>
using namespace std;
int A[7];
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quicksort(int left, int right, int arr[]) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (arr[i] < arr[pivot]) {
				j++;
				swap(&arr[j], &arr[i]);
			}
		}
		swap(&arr[left], &arr[j]);
		pivot = j;
		quicksort(left, pivot - 1, arr);
		quicksort(pivot + 1, right, arr);
	}

}
int main() {
	int A[7] = { 38,27,43,9,3,82,10 };
	quicksort(0, 6, A);

	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}