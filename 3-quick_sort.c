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
 * lomuto_partition - Order a subset of array of ints according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of ints.
 * @size: The size of the array.
 * @left: The starting index of subset to order.
 * @right: The ending index of subset to order.
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
swap_ints(array + below, array + above);
print_array(array, size);
}
above++;
}
}

if (array[above] > *pivot)
{
swap_ints(array + above, pivot);
print_array(array, size);
}

return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm via recursion.
 * @array: An array of ints to sort.
 * @size: The size of array.
 * @left: The starting index of array partition to order.
 * @right: The ending index of array partition to order.
 *
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, part - 1);
lomuto_sort(array, size, part + 1, right);
}
}

/**
 * quick_sort - Sort array ints in ascending
 *              order using the quicksort algorithm.
 * @array: An array of ints.
 * @size: The size of array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
