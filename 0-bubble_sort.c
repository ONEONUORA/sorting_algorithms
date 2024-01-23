#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_elements(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order using Bubble Sort.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap operation.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swapped = 0;

	if (array == NULL || size < 2)
		return;

	while (swapped == 0)
	{
		swapped = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_elements(array + i, array + i + 1);
				print_array(array, size);
				swapped = 0;
			}
		}
		len--;
	}
}

