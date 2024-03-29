#include "sort.h"
#include <stdio.h>

/**
 * swap - Change two values in ascending or descending order.
 * @arr: Array.
 * @item1: Index of the first item.
 * @item2: Index of the second item.
 * @order: 1: Ascending order, 0: Descending order.
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
 * merge - Sort bitonic sequences recursively in both orders.
 * @arr: Array.
 * @low: First element.
 * @nelemnt: Number of elements.
 * @order: 1: Ascending order, 0: Descending order.
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - Bitonic sort algorithm implementation.
 * @arr: Array.
 * @low: First element.
 * @nelemnt: Number of elements.
 * @order: 1: Ascending order, 0: Descending order.
 * @size: Array length.
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
		else
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);

		print_array(&arr[low], nelemnt);

		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);

		if (order <= 0)
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
		if (order >= 1)
			printf("Result [%i/%i] (UP):\n", nelemnt, size);

		print_array(&arr[low], nelemnt);
	}
}

/**
 * bitonic_sort - Prepare the terrain for the bitonic sort algorithm.
 * @array: Array.
 * @size: Array length.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;

	bitonicsort(array, 0, size, order, size);
}

