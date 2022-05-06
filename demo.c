#include <stdio.h>
int fun(int n)
{
  if (n == 1)
    return 0;
  else
  { 
    return 1 + fun(n / 2);
  }
}
int main()
{
  printf("%d\n", fun(8));
  return 0;
}