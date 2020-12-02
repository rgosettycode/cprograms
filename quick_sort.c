#include <stdio.h>
#include <stdlib.h>

void quick_sort(unsigned int *arr, int lower, int upper)
{
	int begin, end; // index position
	unsigned int pivot, temp;

	if (lower < upper) {
		pivot = arr[lower];
		begin = lower;
		end = upper;
		while(begin < end) {
			while(pivot >= arr[begin] && begin <= upper) {
				begin++;
			}
			while(pivot < arr[end] && end >= lower) {
				end--;
			}
			if (begin < end) {
				temp = arr[begin];
				arr[begin] = arr[end];
				arr[end] = temp;
			}
		}
		arr[lower] = arr[end];
		arr[end] = pivot;
		quick_sort(arr, lower, end - 1);
		quick_sort(arr, end + 1, upper);
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
