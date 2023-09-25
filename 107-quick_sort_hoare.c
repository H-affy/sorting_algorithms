#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - function that swap two integer
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - function that order subset of an array of integers
 * @array: Array of integer
 * @size: Size of an array
 * @left: Starting index
 * @right: Ending index
 *
 * Desc: uses the last element of the partition as the pivot
 * Return: Final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);
		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - function that implement the quicksort algo through recursion
 * @array: array of an integer
 * @size: size of an array
 * @left: starting index
 * @right: Ending index
 *
 * Desc: uses the hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - function that sort array of integer
 * @array: Array of integer
 * @size: size of an array
 * Desc: uses the hoare partition scheme
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
