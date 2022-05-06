/* WAP to work on PreOrder */
#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* InsertTree(int data)
{
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}
void PreOrder(struct node *root)
{
  if (root == NULL)
  return;
  else
  {
    printf("%d\t",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
  }
}
int main()
{
  struct node *p = InsertTree(7);
  struct node *p1 = InsertTree(2);
  struct node *p2 = InsertTree(3);
  struct node *p3 = InsertTree(1);
  struct node *p4 = InsertTree(9);
  struct node *p5 = InsertTree(4);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p2->right = p4;
  p3->left = p5;
  printf("\n\tPreOrder Treversal\n");
  PreOrder(p);
  printf("\n");
  /*
   printf("Enter No. of Elements in Tree : ");
  scnaf("%d",&n);

  printf("\n\tPlease Enter %d Elements\n");
  for( int i=0; i<n; i++)
  InsertTree(scanf("%d",&ele)); */

  return 0;
}