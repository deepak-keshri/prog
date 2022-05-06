#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root = NULL;

int NewElement()
{
  int ele;
  printf("Enter any Elements : ");
  scanf("%d", &ele);
  return ele;
}
struct node *SetNodePosition(struct node *tmp, int n)
{
  if ((tmp->left == NULL && tmp->right == NULL) || (tmp->left == NULL && tmp->data > n) || (tmp->right == NULL && tmp->data < n))
    return tmp;
  else if (tmp->data > n)
    return SetNodePosition(tmp->left, n);
  else
    return SetNodePosition(tmp->right, n);
}

int SearchNode(struct node *temp, int n)
{
  if (temp == NULL)
    return 0;
  else if (temp->data == n)
    return 1;
  else if (temp->data > n)
    return SearchNode(temp->left, n);
  else
    return SearchNode(temp->right, n);
}

void CreateNode(struct node *temp)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = NewElement();
  newnode->left = newnode->right = NULL;

  if (SearchNode(temp, newnode->data))
  {
    printf("\n\t\t%d already inserted. Please enter anather elements\n", newnode->data);
    return;
  }

  if (root == NULL)
  {
    root = newnode;
    printf("node => %d\n", newnode->data);
    printf("root => %d\n", root->data);
    return;
  }
  else
  {
    temp = SetNodePosition(temp, newnode->data);
    if (temp->data > newnode->data)
      temp->left = newnode;
    else
      temp->right = newnode;
  }
}
int i = 0;
void DeleteNode(struct node *temp, int ele)
{
  static struct node *DelNode = NULL;
  if (temp->data == ele)
  {
    if (i == 1)
    {
      DelNode->left = NULL;
    }
    else
    {
      DelNode->right = NULL;
    }
    free(temp);
  }
  else if (temp->data > ele)
  {
    DelNode = temp;
    i = 1;
    return DeleteNode(temp->left, ele);
  }
  else
  {
    DelNode = temp;
    i = 1;
    return DeleteNode(temp->right, ele);
  }
}

void DisplayData(struct node *temp)
{
  if (temp == NULL)
    return;
  else
  {
    DisplayData(temp->left);
    printf("%d\t", temp->data);
    DisplayData(temp->right);
  }
}

int main()
{
  int ch, n;
  while (1)
  {
    printf("\n\t1. Insertion of BST\n");
    printf("\t2. Seaching of BST\n");
    printf("\t3. Delete of BST\n");
    printf("\t4. Display BST\n");
    printf("\t5. Exit\n\n\n");

    printf("Please Enter the Choice .... ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      CreateNode(root);
      break;

    case 2:
      n = NewElement();
      if (SearchNode(root, n))
        printf("\n\t\t%d is Searched\n\n", n);
      else
        printf("\n\t\tNo matched %d Data\n", n);
      break;

    case 3:
      n = NewElement();
      DeleteNode(root, n);
      break;

    case 4:
      DisplayData(root);
      break;

    case 5:
      exit(0);

    default:
      printf("\n\t\tPlease Enter Correct Choice\n");
      printf("\t--------------------------------------------\n\n");
    }
  }
  return 0;
}