#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *plink;
  struct node *nlink;
};
struct node *prev = NULL, *next = NULL;

int GenerateData()
{
  int n;
  printf("Enter any Number : ");
  scanf("%d",&n);
  return n;
}
/*  */
void InsertBegin()
{
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = GenerateData();
  newnode->nlink = next;
  newnode->plink = NULL;
  next = newnode;
  
  if (prev == NULL)
  prev = newnode;
  else
  {
    struct node *temp = prev;
    while (temp->plink != NULL)
    temp = temp->plink;

    temp->plink = next;
  }
}

void InsertEnd()
{
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = GenerateData();
  newnode->plink = prev;
  prev = newnode;
  newnode->nlink = NULL;
  if (next == NULL)
  next = newnode;
  else 
  {
    struct node *temp = next;
    while (temp->nlink != NULL)
    temp = temp->nlink;

    temp->nlink = prev;
  }
}

void InsertSpecifiec()
{
  int pos;
  printf("Enter Position : ");
  scanf("%d",&pos);
  struct node *newnode = (struct node*)malloc(sizeof(struct node));

  struct node *temp = next;
  if (pos <= 0 )
  {
    printf("\n\t\tPlease Enter Vailid Position\n");
    return;
  }
  else if ( pos == 1 )
  {
    InsertBegin();
  }
  else
  {
    for (int i = 1; i < pos-1; i++ )
    {
      temp = temp->nlink;
      if (temp == NULL)
      {
        printf("Please give vailid Position\n");
        return;
      }
    }
    newnode->plink = temp;
    newnode->data = GenerateData();
    newnode->nlink = temp->nlink;
    struct node *temp1 = temp->nlink;
    temp->nlink = newnode;
    temp1->plink = newnode;
  }
}

void DeleteBegin()
{
  struct node *temp = next;
  struct node *temp1 = temp->nlink;
  next = next->nlink;
  temp1->plink = NULL;
  printf("\n\t%d is Deleted\n",temp->data);
  free(temp);
}

void DeleteEnd()
{
  struct node *temp = prev;
  struct node *temp1 = temp->plink;
  prev = prev->plink;
  temp1->nlink = NULL;
  printf("\n\t%d is Deleted Succesfully\n",temp->data);
  free(temp);
}

// Incomplete
void DeleteSpecifiec()
{
  int pos;
  printf("Enter the Position No. : ");
  scanf("%d",&pos);
  struct node *temp = next;
  if (pos > 1)
  {
    for (int i=0; i < pos-1; i++)
    {
      temp = temp->nlink;
      if (temp == NULL)
      {
        printf("Please Enter Valid Position");
        return;
      }
    }
  }
  else if (pos == 1)
  DeleteBegin();
  else 
  {
    printf("Please Enter vailid Position\n");
    return;
  }
}

void SearchingData()
{
  int ele, flag = 0;
  printf("Enter the Searching Elements : ");
  scanf("%d",&ele);

  struct node *temp = next;
  while (temp != NULL)
  {
    if (temp->data == ele)
    {
      flag = 1;
      break;
    }
    temp = temp->nlink;
  }
  if (flag == 1)
  printf("\n\t%d Elemtns is Available\n",ele);
  else 
  printf("\n\tNo Match %d Elelmetns ",ele);
}

void Display()
{
  struct node *temp = next;
  while(temp!=NULL)
  {
    printf("%d   ",temp->data);
    temp = temp->nlink;
  }
}

void DisplayReverseOrder()
{
  struct node *temp = prev;
  while(temp!=NULL)
  {
    printf("%d   ",temp->data);
    temp = temp->plink;
  }
}

int main()
{
  int n, ch, pos;
  while (1)
  {
    printf("\n\n1). Insert at a Begining\n");
    printf("2). Insert at a End\n");
    printf("3). Insert at a Speciec Posiont\n");
    printf("4). Delete at a First\n");
    printf("5). Delete at a End\n");
    printf("6). Delete Specifiec Position\n");
    printf("7). Searching Data\n");
    printf("8). Display \n");
    printf("9). Display Reverse Order\n");
    printf("10). Adjent Swap\n");
    printf("11). Exit\n");
    printf("\n\tEnter Choice : ");
    scanf("%d", &ch);
    
    switch (ch)
    {
    case 1:
      InsertBegin();
      break;

    case 2:
      InsertEnd();
      break;

    case 3:
      InsertSpecifiec();
      break;

    case 4:
      DeleteBegin();
      break;

    case 5:
      DeleteEnd();
      break;

    case 6:
      DeleteSpecifiec();
      break;

    case 7:
      SearchingData();      
      break;

    case 8:
      Display();
      break;

    case 9:
      DisplayReverseOrder();
      break;

    case 10:
      
      break;

    case 11:
      exit(0);

    default:
      printf("Enter only valid input");
    }
  }
  return 0;
}