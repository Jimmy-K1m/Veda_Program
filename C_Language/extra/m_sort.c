#include <stdio.h>
#include <stdlib.h>

void mergeArray(int* arr, int left, int right);
void mergeSort(int * arr, int left, int right);

int main() {
	
	//int* arr = (int*)malloc(sizeof(int)*8);
	int arr[8] = { 7,2,8,3,5,9,6, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	//arr = { 7,2,8,3,5,9,6 };
	mergeSort(arr, 0, 7);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void mergeSort(int* arr, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		mergeArray(arr, left, right);
	}
}

void mergeArray(int* arr, int left, int right)
{

	
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;

	int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (arr[j] > arr[i]) {
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;

		}// 
		k++;
	}
	
	
	
	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}
	

	for (int l = left, m = 0; l <= right; l++, m++) {
		arr[l] = temp[m];
	}



	free(temp);
}

