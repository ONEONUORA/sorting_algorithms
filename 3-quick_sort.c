#include "sort.h"

void swap_elements(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_quick_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_elements - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elements(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Partition a subset of an array of integers
 *                    using the Lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_elements(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_elements(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_quick_sort - Implement the quicksort algorithm using
 *                     the Lomuto partition scheme recursively.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 */
void lomuto_quick_sort(int *array, size_t size, int left, int right)
{
    int partition;

    if (right - left > 0)
    {
        partition = lomuto_partition(array, size, left, right);
        lomuto_quick_sort(array, size, left, partition - 1);
        lomuto_quick_sort(array, size, partition + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 *              Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_quick_sort(array, size, 0, size - 1);
}

