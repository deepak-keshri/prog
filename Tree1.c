struct node
{
  int data;
  struct node *prev;
  struct node *next;
};
struct node *head = NULL;
next = prev = head;

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