#include "custom_sort.h"
#include <stdio.h>

/**
 * swap_elements - Swap two elements in an array.
 * @arr: The array in which elements are swapped.
 * @index1: The index of the first element.
 * @index2: The index of the second element.
 * Return: Nothing.
 */
void swap_elements(int *arr, int index1, int index2)
{
	int temp;

	if (arr[index1] != arr[index2])
	{
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * custom_shell_sort - Sorts an array using the custom shell sort algorithm.
 * @arr: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void custom_shell_sort(int *arr, size_t size)
{
	size_t gap = 0, i, j;

	if (size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap)
				swap_elements(arr, j, j - gap);

		gap /= 3;
		print_custom_array(arr, size);  // Assuming you have a custom print function.
	}
}

