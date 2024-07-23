#include <stdio.h>

void QuickSort(int* arr, int start, int end);
int startLeft(int* arr, int start, int end, int pivot);
int startRight(int* arr, int start, int end, int pivot);
void swap(int* a, int* b);

int Partition(int* arr, int start, int end);

int main()
{
	int arr[] = { 7,2,8,3,5,9,6 };

	printf("Before Sorting\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	printf("After Sorting\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);

	printf("\n\n");
	return 0;

}

int startLeft(int* arr, int start, int end, int pivot) {

	for (int i = start; i <= end; i++)
	{
		if (arr[pivot] < arr[i])
			return i;
	}
}
int startRight(int* arr, int start, int end, int pivot) {

	for (int i = end; i >= start; i--)
	{
		if (arr[pivot] > arr[i])
			return i;
	}
}

int Partition(int* arr, int start, int end)
{
	int left, right;
	int pivot = end;
	if (start < end)/**/
	{
		do {
			left = startLeft(arr, start, end - 1, pivot);
			right = startRight(arr, start, end - 1, pivot);
			if (left < right) // left, right가 교차되었을 때는 swap이 되면 안 된다.
				swap(&arr[left], &arr[right]);
		} while (left < right);
		swap(&arr[pivot], &arr[left]);
		return left;
	}
	return start; // start와 end가 같은 경우

}

void QuickSort(int* arr, int start, int end) {

	if (start < end)/**/
	{
		int pivot = Partition(arr, start, end);
		QuickSort(arr, start, pivot - 1);
		QuickSort(arr, pivot + 1, end);

	}

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}