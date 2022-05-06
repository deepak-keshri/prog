/* WAP to run all the insertion sort operatoin */
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d  ", arr[i]);
  printf("\n\n");
}
void InsertionSort(int *arr, int n)
{
  int i, j, temp, ele;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i; j >= 0; j--)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      else
        break;
    }
    for (j = 0; j < n; j++)
      printf("%d ", arr[j]);
    printf("\n");
  }
}

int main()
{
  int arr[10], n, i;
  printf("Enter the Number of elements : ");
  scanf("%d", &n);

  printf("Enter the %d of Elements\n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printArray(arr, n);
  InsertionSort(arr, n);
  printArray(arr, n);

  return 0;
}