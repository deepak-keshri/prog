// Example of Selection Sort
#include<stdio.h>
void PrintArray(int *arr,int len)
{
  for (int i=0; i<len; i++)
  printf("%d\t",arr[i]);
  printf("\n");
}
void SelectionSort(int *arr,int len)
{
  printf("\nAfter Selection Sort\n");
  for (int i=0; i<len-1; i++)
  {
    int key = arr[i];
    int ind = i;
    for (int j=i+1; j<len; j++)
    {
      if (key > arr[j])  
      {
        key = arr[j];
        ind = j;
      }
    }
    if (arr[i] > key)
    {        
      int temp = arr[i];
      arr[i] = arr[ind];
      arr[ind] = temp;
    }
  }
}
int main()
{
  /* 
  1) |8|0|3|2|6|7|
    key=0.
    0,8,3,2,6,7
  
  2) 0,8,3,2,6,7
    key=8.
    key=3,key=2,key=2,key=2
  
  3) 0,2,3,8,6,7
    key=3,key3,key=3,
  
  4) 0,2,3,8,6,7
    key=8,key=6,key=6

  5) 0,2,3,6,8,7
    key=8,key=7

  6) 0,2,3,6,7,8

  Sorted Array is 
                  0,2,3,6,7,8

   */
  //int arr[6] = {8,0,3,2,6,7};
  int arr[6] = {5,3,4,1,6,9};
  PrintArray(arr, 6);
  SelectionSort(arr, 6);
  PrintArray(arr, 6);

  return 0;
}