/* Non Recursive Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node *left;
  struct node *right;
  int data;
};
struct node *root = NULL;

struct node *stack[10];
int top = -1;
int MAX = 10;
void push(struct node *ptr)
{
  if (top + 1 == MAX)
  {
    printf("Stact is Overflow");
    return;
  }
  top++;
  stack[top] = ptr;
}
struct node *pop()
{
  if (top == -1)
  {
    printf("stack is Empty");
    return 0;
  }
  struct node *temp = stack[top];
  top--;
  return temp;
}
int stack_empty()
{
  if (top == -1)
    return 0;
  else
    return 1;
}

void Insert(int n)
{
  printf("\n%d", n);

  if (root == NULL)
  {
    printf("\n%d", n);

    root->left = root->right = NULL;
    root->data = n;
    printf("\n%d", n);
  }
  else
  {
    printf("\n%d yes",n);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->data = n;
    if (root->data >= n)
      root->left = newnode;
    else
      root->right = newnode;
  }
}

void preOrder()
{
}
void inOrder()
{
}
void postOrder()
{
}
int main()
{
  int ch, data, flag = 0;
  while (1)
  {
    printf("1. Insert Data\n");
    printf("2. PreOrder\n");
    printf("3. InOrder\n");
    printf("4. PostOrder\n\n");
    printf("\tEnter the Choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the elements : ");
      scanf("%d", &data);
      Insert(data);
      break;

    case 2:
      preOrder();
      break;

    case 3:
      inOrder();
      break;

    case 4:
      postOrder();
      break;

    case 5:
      flag = 1;
      break;

    default:
      printf("Pleae Enter correct Choice");
      break;
    }
    if (flag)
      break;
  }

  return 0;
}