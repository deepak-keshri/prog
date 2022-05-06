/*Example of bubble Short*/
#include<stdio.h>
#include<stdlib.h>
void PrintArray(int *arr, int len)
{
  printf("\n\n");
  for (int i=0; i<len; i++)
    printf("%d\n",arr[i]);
}
void BubbleShort(int *arr, int len)
{
  for (int i=0; i<len-1; i++)
  {
    printf("Sorted Array\n");
    int issort = 1;
    for (int j=0; j<(len-1-i); j++){
      if (arr[j] > arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        issort = 0;
      }
    }
    if (issort == 1)
      return;
  }
}

int main()
{
  //int arr[5] = {12,3,45,8,4};
  //int arr[5] = {1,2,3,4,5};
  int arr[5] = {1,2,3,5,4};
  PrintArray(arr,5);
  BubbleShort(arr,5);
  PrintArray(arr,5);  
  return 0;
}