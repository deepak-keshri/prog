// All operation of linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node *link;
  int data;
};
struct node *head = NULL;
void Insertion(int n)
{
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = n;
  newnode->link = head;
  head = newnode;
}
void Insertion_end(int n)
{
  if (head == NULL)
  {
    Insertion(n);
  }
  else
  {
    struct node *newnode;
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    while (temp->link != NULL)
    {
      // p = temp;
      temp = temp->link;
    }
    temp->link = newnode;
    newnode->data = n;
    newnode->link = NULL;
  }
}

void Insert_Specifiec(int n, int pos)
{
  struct node *newnode, *temp = head;
  newnode = (struct node *)malloc(sizeof(struct node));
  if (pos > 0)
  {
    if (pos == 1)
    {
      newnode->link = head;
      head = newnode;
      newnode->data = n;
    }
    else if (pos == 2)
    {
      newnode->link = head->link;
      head->link = newnode;
      newnode->data = n;
    }
    else if (pos >= 3)
    {
      for (int i = 1; i < pos - 1; i++)
      {
        temp = temp->link;
        if (temp == NULL)
        {
          printf("Input is out of Range\n");
          return;
        }
      }

      newnode->link = temp->link;
      temp->link = newnode;
      newnode->data = n;
    }
  }
  else
  {
    printf("Please Enter vailid Input\n");
  }
}

void Delete_first()
{
  struct node *temp;
  if (head != NULL)
  {
    temp = head;
    head = head->link;
    printf("\n\t%d Elemetns is Deleted\n", temp->data);
    free(temp);
  }
  else
  {
    printf("Linked List is Empty\n");
  }
}

void Delete_end()
{
  struct node *temp, *p;
  temp = head;
  if (head == NULL)
  {
    printf("Linked List is Empty\n");
  }
  else if (head->link == NULL)
  {
    head = NULL;
    printf("%d Elements is Deleted Successfully\n", temp->data);
    free(temp);
  }
  else if (head != NULL)
  {
    while (temp->link != NULL)
    {
      p = temp;
      temp = temp->link;
    }
    p->link = NULL;
    printf("%d Elements is Deleted Successfully\n", temp->data);
    free(temp);
  }
}

void Delete_Specifiec(int pos)
{
  struct node *p, *temp = head;
  if (head == NULL)
  {
    printf("Linked list is Empty\n");
    return;
  }
  else if (pos == 1)
  {
    head = head->link;
    printf("%d Data Delete\n", temp->data);
    free(temp);
  }
  else if (pos > 1)
  {
    while (pos >= 2)
    {
      p = temp;
      temp = temp->link;
      pos--;
      if (temp == NULL)
      {
        printf("The Position No. is out of range\n");
        return;
      }
    }
    printf("%d Data Deleted\n", temp->data);
    p->link = temp->link;
    free(temp);
  }
  else
  {
    printf("Please Enter Valid Input\n");
    printf("=========================\n");
  }
}

void Searching(int n)
{
  struct node *temp = head;
  int f = 0;
  while (temp != NULL)
  {
    if (temp->data == n)
    {
      f = 1;
      break;
    }
    temp = temp->link;
  }
  if (f)
    printf("%d is Available in List\n", n);
  else
    printf("No match any Data\n");
}

void Display()
{
  if (head == NULL)
  {
    printf("\n---------> Link List is Empty <---------------\n");
    return;
  }
  struct node *temp = head;
  printf("\n-----------------------------------------------\n");
  printf("\t\tDisplayed Data\n");
  printf("-----------------------------------------------\n");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->link;
  }
  printf("\n\n");
}

void Adjecent_swap()
{
  struct node *p1, *p2, *x, *y;
  p1 = head;
  p2 = head->link;

  int i=0;
  while (y != NULL)
  {
    i++;
    y = p2->link;
    if (i%2 == 0)
    {
      struct node *temp = p1->link;
      p1->link = p2->link;
      p2->link = temp;
      
      p1 = p1->link;
    }
    p2 = y;
  }
}

void Reverse()
{
  struct node *p1, *p2, *x, *y;
  p1 = head;
  y = p2 = head->link;
  
  while (y != NULL)
  {
    x = y;
    y = p2->link;
    p2->link = p1;
    p1 = x;
    p2 = y; 
  }
  head->link = NULL;
  head = x;
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
    printf("8). Display The Data\n");
    printf("9). Reverse Data\n");
    printf("10). Adjent Swap\n");
    printf("11). Exit\n");
    printf("\n\tEnter Choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the Elemets : ");
      scanf("%d", &n);
      Insertion(n);
      break;

    case 2:
      printf("Enter the Elemtns : ");
      scanf("%d", &n);
      Insertion_end(n);
      break;

    case 3:
      printf("Enter the Position : ");
      scanf("%d", &pos);
      printf("Enter the Element : ");
      scanf("%d", &n);
      Insert_Specifiec(n, pos);
      break;

    case 4:
      Delete_first();
      break;

    case 5:
      Delete_end();
      break;

    case 6:
      printf("Enter the Position No. : ");
      scanf("%d", &pos);
      Delete_Specifiec(pos);
      break;

    case 7:
      printf("Enter any Number : ");
      scanf("%d", &n);
      Searching(n);
      break;

    case 8:
      Display();
      break;

    case 9:
      Reverse();
      break;

    case 10:
      Adjecent_swap();
      break;

    case 11:
      exit(0);

    default:
      printf("Enter only valid input");
    }
  }
  return 0;
}