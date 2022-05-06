#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* CreateNode(int n)
{
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}
void PostOrder(struct node *root)
{
  if (root == NULL)
  return;
  else 
  {
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d\t",root->data);
  }
}
int main()
{
  struct node *p = CreateNode(7);
  struct node *p1 = CreateNode(2);
  struct node *p2 = CreateNode(3);
  struct node *p3 = CreateNode(1);
  struct node *p4 = CreateNode(9);
  struct node *p5 = CreateNode(4);
  struct node *p6 = CreateNode(6);
  struct node *p7 = CreateNode(11);
  struct node *p8 = CreateNode(15);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p2->right = p4;
  p3->left = p5;
  p3->right = p6;
  p4->left = p7;
  p5->right = p8;
  
  PostOrder(p);
  printf("\n");
  return 0;
}