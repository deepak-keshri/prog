#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root = NULL;
struct node *CreateNode(int ele)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = ele;
  return newnode;
}

void Display(struct node *temp)
{
  if (temp == NULL) {
    printf("-> Y <-");

    return;
  } else {
    printf("-> N <-");
    Display(temp->left);
    Display(temp->right);
    printf("%d\t",temp->data);

  }
}
/*  */
int main()
{
  struct node *p = CreateNode(50);
  struct node *p1 = CreateNode(10);
  struct node *p2 = CreateNode(25);
  struct node *p3 = CreateNode(30);
  struct node *p4 = CreateNode(5);

  p->left = p1;
  p->right = p2;
  p2->right = p3;
  p1->left = p4;
  Display(p);
  printf("\nHello\n");

  return 0;
}