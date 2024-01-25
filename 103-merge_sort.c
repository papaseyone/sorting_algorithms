#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort subarray of ints.
 * @subarr: A subarray of array of ints to sort.
 * @buff: A buff to store the sorted subarray.
 * @front: The front index of array.
 * @mid: The middle index of array.
 * @back: The back index of array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
size_t i;
size_t j;
size_t k = 0;


printf("Merging...\n[left]: ");
print_array(subarr + front, mid - front);

printf("[right]: ");
print_array(subarr + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
for (; i < mid; i++)
buff[k++] = subarr[i];
for (; j < back; j++)
buff[k++] = subarr[j];
for (i = front, k = 0; i < back; i++)
subarr[i] = buff[k++];

printf("[Done]: ");
print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algo via recursion.
 * @subarr: A subarray of an array of ints to sort.
 * @buff: A buff to store the sorted result.
 * @front: The front index of subarray.
 * @back: The back index of subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(subarr, buff, front, mid);
merge_sort_recursive(subarr, buff, mid, back);
merge_subarr(subarr, buff, front, mid, back);
}
}

/**
 * merge_sort - Sort array of ints in ascending
 *              order using the merge sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Implements top-down merge sort algo.
 */
void merge_sort(int *array, size_t size)
{
int *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

merge_sort_recursive(array, buff, 0, size);

free(buff);
}
