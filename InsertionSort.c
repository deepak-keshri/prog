//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
void PrintArray(int *a, int lenth)
{
  printf("\n\n");
  for (int  i = 0; i < lenth; i++)
  {
    printf("%d\t",a[i]);   
  }
}

void InsertionSort(int *a, int lenth)
{
  printf("\n\n\t\tSorted Array\n");
  for (int i = 0; i < lenth-1; i++)
  {
    printf("Sorted Array is ..\n");
    for (int j=i; j>=0; j--)
    {
      if (a[j] > a[j+1])
      {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
      else
      break;
    }
  }
  printf("\n");
}
int main()
{
  //int arr[6] = {5,2,6,7,1,3};
  int arr[6] = {1,2,3,4,5,6};
  PrintArray(arr, 6);
  InsertionSort(arr, 6);
  PrintArray(arr, 6);
  return 0;
}
/* 
1-> 5,|,2,6,7,1,3
2-> 2,5,|,6,7,1,3
3-> 2,5,6,|,7,1,3
4-> 2,5,6,7,|,1,3
5-> 
    2,5,6,1,|7,3
    2,5,1,6,|7,3
    2,1,5,6,|7,3
    1,2,5,6,|7,3
    
6->
    1,2,5,6,7,|3
    1,2,5,6,3,|7
    1,2,5,3,6,|7
    1,2,3,5,6,|7

    Sorted Array is :->
    1,2,3,5,6,7
 */