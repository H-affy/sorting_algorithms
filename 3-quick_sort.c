#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int first, int last);
void lomuto_sort(int *array, size_t size, int first, int last);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integer in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Function that order subset of array of integers
 * according to the lomuto partition scheme
 * @array: The array of integer
 * @size: Size of an array
 * @first: Starting index
 * @last: Ending index
 *
 * Return: Final partition index
 */
int lomuto_partition(int *array, size_t size, int first, int last)
{
	int *pivot, above, below;

	pivot = array + last;
	for (above = below = first; below < last; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - FUnction that implement the quicksort algorithm
 * through recursion
 * @array: Array of integer
 * @size: Size of an array
 * @first: Starting index
 * @last: Last index
 *
 * Description: uses the lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int first, int last)
{
	int pat;

	if (last - first > 0)
	{
		pat = lomuto_partition(array, size, first, last);
		lomuto_sort(array, size, first, pat - 1);
		lomuto_sort(array, size, pat + 1, last);
	}
}

/**
 * quick_sort - Function that sorts an array of integers.
 * @array: Array of integer
 * @size: Size of an array
 *
 * Description: Uses lomuto partition scheme.
 * prints array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
