#include <stdio.h>
#include <stdlib.h>

void merge_op(unsigned int *arr, int lower, int mid, int upper)
{
	unsigned int b[upper - lower + 1];
	int i, j, k;

	i = lower;
	j = mid + 1;
	k = 0;
	while(i <= mid && j <= upper) {
		if (arr[i] <= arr[j]) {
			b[k] = arr[i];
			i++;
		} else {
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		b[k] = arr[i];
		i++; k++;
	}
	while(j <= upper) {
		b[k] = arr[j];
		j++; k++;
	}
	for (i = lower; i <= upper; i++) {
		arr[i] = b[i];
	}
}

void merge_sort(unsigned int *arr, int lower, int upper)
{
	int mid;

	if (lower < upper) {
		mid = (lower + upper) / 2;
		merge_sort(arr, lower, mid);
		merge_sort(arr, mid + 1, upper);
		merge_op(arr, lower, mid, upper);
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
	merge_sort(arr, 0, n - 1);
	printf("sorted order: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
