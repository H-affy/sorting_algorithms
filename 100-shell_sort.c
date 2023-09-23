#include "sort.h"

/**
 * swap_ints - Function that swap two integer
 * @a: The fist integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - Function that sorts an array of integer using the
 * knuth sequence
 * @array: The array of integers
 * @size: The size of array
 *
 * Description: uses the knuth sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t tap, i, j;

	if (array == NULL || size < 2)
		return;
	for (tap = 1; tap < (size / 3);)
		tap = tap * 3 + 1;
	for (; tap >= 1; tap /= 3)
	{
		for (i = tap; i < size; i++)
		{
			j = i;
			while (j >= tap && array[j - tap] > array[j])
			{
				swap_ints(array + j, array + (j - tap));
				j -= tap;
			}
		}
		print_array(array, size);
	}
}
