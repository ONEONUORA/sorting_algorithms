#include "sort.h"

/**
 * check_tree - Adjusts the heap rooted at index i.
 *
 * @array: Pointer to array.
 * @size_init: Original size of the array.
 * @size: Current size of the heap.
 * @i: Index as the root of the tree.
 */
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
    int n, branch1, branch2;
    size_t br1, br2;

    br1 = i * 2 + 1;
    br2 = br1 + 1;
    branch1 = (br1 < size) ? array[br1] : INT_MIN;
    branch2 = (br2 < size) ? array[br2] : INT_MIN;

    if ((branch1 >= branch2 && branch1 > array[i]) ||
        (br1 == size - 1 && branch1 > array[i]))
    {
        n = array[i];
        array[i] = branch1;
        array[br1] = n;
        print_array(array, size_init);
    }
    else if (branch2 > branch1 && branch2 > array[i])
    {
        n = array[i];
        array[i] = branch2;
        array[br2] = n;
        print_array(array, size_init);
    }

    if (br1 < size - 1)
        check_tree(array, size_init, size, br1);
    if (br2 < size - 1)
        check_tree(array, size_init, size, br2);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 *
 * @array: Pointer to array.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t i, size_init = size;
    int n;

    if (!array || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2; i > 0; i--)
    {
        check_tree(array, size_init, size, i - 1);
    }

    /* Extract elements from the heap */
    for (i = 0; i < size_init - 1; i++)
    {
        n = array[0];
        array[0] = array[size - 1 - i];
        array[size - 1 - i] = n;
        print_array(array, size_init);
        check_tree(array, size_init, size - i - 1, 0);
    }
}

