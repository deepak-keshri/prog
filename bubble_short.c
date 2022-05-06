/* WAP to solve the bubble sort algorithm */
/* | 5 | 2 | 4 | 3 | 8 | */
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int ele, i, j, arr[10], temp;
  printf("Enter the Number of elements : ");
  scanf("%d", &ele);

  printf("Enter the %d elements\n", ele);
  for (i = 0; i < ele; i++)
    scanf("%d", &arr[i]);

  /* Bubble Short */
  for (i = 0; i < ele - 1; i++)
  {
    for (j = 0; j < ele - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    printf("\n");
    for (j = 0; j < ele; j++)
      printf("%d  ", arr[j]);
  }
  printf("\n");

  for (i = 0; i < ele; i++)
    printf("%d  ", arr[i]);

  return 0;
}