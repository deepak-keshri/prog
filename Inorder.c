/* Inorder program in c */
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
  struct node *ele = (struct node*)malloc(sizeof(struct node));
  ele->data = n;
  ele->left = NULL;
  ele->right = NULL;
  return ele;
}
void InOrder(struct node *root)
{
  if (root == NULL) 
  return;
  else
  {
    InOrder(root->left);
    printf("%d\t",root->data);
    InOrder(root->right);
  }
}
int main()
{
  struct node *p = CreateNode(5);
  struct node *p1 = CreateNode(3);
  struct node *p2 = CreateNode(6);
  struct node *p3 = CreateNode(1);
  struct node *p4 = CreateNode(11);
  struct node *p5 = CreateNode(9);
  struct node *p6 = CreateNode(8);
  struct node *p7 = CreateNode(4);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->left = p5;
  p2->right = p6;
  p3->left = p7;

  InOrder(p);
  
  return 0;
}