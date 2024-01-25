#include "sort.h"

/**
 * swap_ints - Swap two int in array.
 * @a: The first int to swap.
 * @b: The sec int to swap.
 */

void swap_ints(int *a, int *b)
{

int tmp = *a;
*a = *b;
*b = tmp;

}


/**
 * selection_sort - Sort array of ints in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of ints.
 * @size: The size of array.
 *
 * Description: Prints array after each swap.
 */

void selection_sort(int *array, size_t size)
{

int *min, size_t i, j;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
min = array + i;
for (j = i + 1; j < size; j++)
min = (array[j] < *min) ? (array + j) : min;

if ((array + i) != min)
{
swap_ints(array + i, min);
print_array(array, size);
}
}
}
