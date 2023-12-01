#include <stdio.h>
#include <stdlib.h>

void quick_sort (int *arr, int l, int h) {
	int pivot, i, j, temp;

	if (l < h) {
		pivot = arr[l]; // pivot swap
		i = l; j = h;
		while(i < j) {
			while(pivot >= arr[i]) i++;
			while(pivot < arr[j]) j--;
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		arr[l] = arr[j]; // pivot swap
		arr[j] = pivot;  // pivot swap
		quick_sort(arr, l, j - 1);
		quick_sort(arr, j + 1, h);
	}
}

int main()
{
	unsigned int i, n;
	unsigned int *arr = NULL;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	arr = (unsigned int *) malloc(n * sizeof(unsigned int));
	if (arr == NULL) {
		printf("malloc failed, you could not enter elements\n");
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n - 1);
	printf("sorted order: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
