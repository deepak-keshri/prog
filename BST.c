#include <stdlib.h>
#include <stdio.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root = NULL;

struct node *setNodePosition(struct node *temp, int d)
{
  if ((temp->left == NULL && temp->right == NULL) || (temp->left == NULL && temp->data > d) || (temp->right == NULL && temp->data < d))
    return temp;
  else if (temp->data > d)
    return setNodePosition(temp->left, d);
  else
    return setNodePosition(temp->right, d);
}
int newElement()
{
  int ele;
  printf("Enter element : ");
  scanf("%d", &ele);
  return ele;
}

void Insert(struct node *temp)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = newElement();
  newnode->left = newnode->right = NULL;

  if (root == NULL)
  {
    root = newnode;
    printf("node %d\n", newnode->data);
    printf("root %d\n", root->data);
  }
  else
  {
    temp = setNodePosition(temp, newnode->data);
    if (temp->data < newnode->data)
      temp->right = newnode;
    else
      temp->left = newnode;
  }
}

void changeMe(struct node *temp, int pd, int nd)
{
  if (temp->data == pd)
    temp->data = nd;
  else if (temp == NULL)
    return;
  else if (temp->data < pd)
    changeMe(temp->right, pd, nd);
  else
    changeMe(temp->left, pd, nd);
}

int isExit(struct node *temp, int pd)
{
  if (temp->data == pd)
    return 1;
  else if (temp == NULL)
    return 0;
  else if (temp->data < pd)
    return isExit(temp->right, pd);
  else
    return isExit(temp->left, pd);
}

void Update(struct node *temp)
{
  int pd, nd; // pd=previous data, nd=new data.
  printf("Entet the Previouse Element : ");
  scanf("%d", &pd);

  printf("Entet the new Element : ");
  scanf("%d", &nd);

  if (isExit(temp, pd))
    changeMe(temp, pd, nd);
  else
    printf("%d Element is not Exit\n", pd);
}


void Delete() 
{
  int del_ele;
  printf("Enter the Delete Element: ");
  scanf("%d",&del_ele);
  if(isExit(del_ele))
  {

  }
  else
  {
    printf("Your given Element are not matched\n");
  }
}

void PreOrder(struct node *temp)
{
  if (temp == NULL)
    return;
  else
  {
    printf("%d ", temp->data);
    PreOrder(temp->left);
    PreOrder(temp->right);
  }
}

void InOrder(struct node *temp)
{
  if (temp == NULL)
    return;
  else
  {
    InOrder(temp->left);
    printf("%d ", temp->data);
    InOrder(temp->right);
  }
}

void PostOrder(struct node *temp)
{
  if (temp == NULL)
    return;
  else
  {
    PostOrder(temp->left);
    PostOrder(temp->right);
    printf("%d ", temp->data);
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
  int ch, f = 0;
  while (1)
  {
    printf("\n\t1. Insert");
    printf("\n\t2. Update");
    printf("\n\t3. Delete");
    printf("\n\t4. PreOrder");
    printf("\n\t5. InOrder");
    printf("\n\t6. PostOrder");
    printf("\n\t7. Exit\n");

    printf("Enter The Correct Choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      Insert(root);
      break;

    case 2:
      Update(root);
      break;

    case 3:
      Delete();
      break;

    case 4:
      PreOrder(root);
      break;

    case 5:
      InOrder(root);
      break;

    case 6:
      PostOrder(root);
      break;

    case 7:
      f = 1;
      break;

    default:
      printf("\n\t\tEnter the Correct Choice ..");
      printf("\n\t---------------------------------------------------\n");
      break;
    }
    if (f == 1)
      break;
  }
}