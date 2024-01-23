#include "sort.h"

/**
 * swap - Swap the positions of two elements in an array.
 * @array: Array.
 * @item1: Array element.
 * @item2: Array element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
    int tmp;

    tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * hoare_partition - Hoare partition sorting scheme implementation.
 * @array: Array.
 * @first: First array element.
 * @last: Last array element.
 * @size: Array size.
 * Return: Return the position of the last element sorted.
 */
int hoare_partition(int *array, int first, int last, int size)
{
    int current = first - 1, finder = last + 1;
    int pivot = array[last];

    while (1)
    {
        do {
            current++;
        } while (array[current] < pivot);
        do {
            finder--;
        } while (array[finder] > pivot);

        if (current >= finder)
            return current;

        swap(array, current, finder);
        print_array(array, size);
    }
}

/**
 * qs - Quicksort algorithm implementation.
 * @array: Array.
 * @first: First array element.
 * @last: Last array element.
 * @size: Array size.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
    ssize_t position = 0;

    if (first < last)
    {
        position = hoare_partition(array, first, last, size);
        qs(array, first, position - 1, size);
        qs(array, position, last, size);
    }
}

/**
 * quick_sort_hoare - Prepare the terrain for the quicksort algorithm (Hoare's partition).
 * @array: Array.
 * @size: Array size.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    qs(array, 0, size - 1, size);
}

