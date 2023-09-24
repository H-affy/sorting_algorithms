#include "sort.h"

/**
 * get_max - Function that get maximum value in an array
 * @array: Array of integers
 * @size: Size of an array
 *
 * Return: The maximum integer in an array
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Function that sort an array of integers
 * @array: Array of integer
 * @size: The size of an array
 *
 * Description: prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, i;

	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i + 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];
	free(sort);
	free(count);
}
