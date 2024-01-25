#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two ints in an array.
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
 * hoare_partition - Order subset of array of ints
 *                   in accordance to hoare partition scheme.
 * @array: The array of ints.
 * @size: The size of array.
 * @left: The starting index of subset to order.
 * @right: The ending index of subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Apply last ele of partition as pivot.
 * Prints array after each swap of two ele.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
int pivot, above, below;

pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
swap_ints(array + above, array + below);
print_array(array, size);
}
}

return (above);
}

/**
 * hoare_sort - Implement quicksort algo through recursion.
 * @array: An array of ints to sort.
 * @size: The size of array.
 * @left: The starting index of array partition to order.
 * @right: The ending index of array partition to order.
 *
 * Description: Apply Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, part - 1);
hoare_sort(array, size, part, right);
}
}

/**
 * quick_sort_hoare - Sort array ints in ascending
 *                    order using quicksort algo.
 * @array: An array of ints.
 * @size: The size of array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * array after each swap of two ele.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}

