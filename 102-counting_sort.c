#include "sort.h"

/**
 * get_max - Get maximum value in an array of int.
 * @array: An array of int.
 * @size: The size of the array.
 *
 * Return: The maximum int in the array.
 */
int get_max(int *array, int size)
{
int max;
int i;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * counting_sort - Sort an array of ints in ascending order
 *                 using the count'n sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Prints tcount'n array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
int *count;
int *sorted;
int max, i;

if (array == NULL || size < 2)
return;

sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
max = get_max(array, size);
count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
{
free(sorted);
return;
}

for (i = 0; i < (max + 1); i++)
count[i] = 0;
for (i = 0; i < (int)size; i++)
count[array[i]] += 1;
for (i = 0; i < (max + 1); i++)
count[i] += count[i - 1];
print_array(count, max + 1);

for (i = 0; i < (int)size; i++)
{
sorted[count[array[i]] - 1] = array[i];
count[array[i]] -= 1;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted[i];

free(sorted);
free(count);
}
