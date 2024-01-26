#include "sort.h"

/**
 * swap_ints - Swap two int in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_ints(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bubble_sort - Sort array of int in ascending order.
 * @array: An array of int to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
bool bubbly = false;

if (array == NULL || size < 2)
return;

while (bubbly == false)
{
bubbly = true;
for (i = 0; i < len - 1; i++)
{
if (array[i] > array[i + 1])
{
swap_ints(array + i, array + i + 1);
print_array(array, size);
bubbly = false;
}
}
len--;
}
}
