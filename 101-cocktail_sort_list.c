#include "custom_sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 *
 * @node: The base node to be swapped.
 * @list: The head of the doubly linked list.
 *
 * Return: No Return
 */
void swap_nodes(listint_t **node, listint_t **list)
{
    listint_t *temp = *node, *temp2, *temp3;

    if (!temp->prev)
        *list = temp->next;

    temp = temp3 = *node;
    temp2 = temp->next;

    temp->next = temp2->next;
    temp3 = temp->prev;
    temp->prev = temp2;
    temp2->next = temp;
    temp2->prev = temp3;

    if (temp2->prev)
        temp2->prev->next = temp2;

    if (temp->next)
        temp->next->prev = temp;

    *node = temp2;
}

/**
 * cocktail_shaker_sort - Sorts a doubly linked list in ascending order using
 *                         the Cocktail Shaker Sort algorithm.
 *
 * @list: Head of the list to be sorted (Doubly Linked List).
 *
 * Return: No Return
 */
void cocktail_shaker_sort(listint_t **list)
{
    listint_t *head, *aux;
    int forward = 0, backward = -1, max = -1;

    if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
        return;

    head = *list;
    while (max >= backward)
    {
        backward++;
        while (head->next && forward != max)
        {
            if (head->n > head->next->n)
            {
                aux = head;
                swap_nodes(&aux, list);
                print_list(*list);
                head = aux;
            }

            forward++;
            head = head->next;
        }

        if (backward == 0)
            max = forward;

        max--;
        while (head->prev && forward >= backward)
        {
            if (head->n < head->prev->n)
            {
                aux = head->prev;
                swap_nodes(&aux, list);
                print_list(*list);
                head = aux->next;
            }
            forward--;
            head = head->prev;
        }
    }
}

