#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

int NewElement()
{
  int ele;
  printf("Enter any Elements : ");
  scanf("%d",&ele);
  return ele;
}

struct node* SetNodePosition(struct node *tmp,int n)
{
  if ((tmp->left == NULL && tmp->data > n) || (tmp->right == NULL && tmp->data < n))
  return tmp;
  else if (tmp->data > n)
  return SetNodePosition(tmp->left, n);
  else 
  return SetNodePosition(tmp->right, n);
}

void InsertNode()
{

}

int main()
{
  struct node *root = NULL;
  int ch, ele, n;
  while (1)
  {
    printf("\n\t1. Insertion of BST\n");
    printf("\t2. Seaching of BST\n");
    printf("\t3. Delete of BST\n");
    printf("\t4. Display BST\n");
    printf("\t5. Exit\n\n\n");

    printf("Please Enter the Choice .... ");
    scanf("%d",&ch);

    switch (ch)
    {
      case 1:
      CreateNode(root);
      break;

      case 2:
      n = NewElement();
      SearchNode(root,n);
      break;

      case 3:
      //DeleteNode();
      break;

      case 4:
      DisplayData(root);
      break;

      case 5:
      exit(0);
    }

  return 0;
}