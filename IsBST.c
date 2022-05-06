/* BST program in c */
/* If in Order of Binary Tree is Ascending order,so it must be BST. */
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

int isBST(struct node *root)
{
  static struct node *prev = NULL;
  if (root!=NULL)
  {
    if (!isBST(root->left))
    return 0;
    
    if (prev != NULL && prev->data >= root->data)
    return 0;

    prev = root;
    return isBST(prev->right);
  }
  else
  return 1;
}

int main()
{
  /* 
       11
      /  \
    9     15
   / \    / \
  5   10 13  20
 / 
4
  .BST.
   */
  struct node *p = CreateNode(11);
  struct node *p1 = CreateNode(9);
  struct node *p2 = CreateNode(15);
  struct node *p3 = CreateNode(5);
  struct node *p4 = CreatteNode(10);
  struct node *p5 = CreateNode(13);
  struct node *p6 = CreateNode(20);
  struct node *p7 = CreateNode(4);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->left = p5;
  p2->right = p6;
  p3->left = p7;

  if (isBST(p))
  {
    printf("\nTree is BST\n");
    InOrder(p);
  }
  else
  printf("Tree is not BST\n");
  
  return 0;
}