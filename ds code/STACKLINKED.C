//EXPERIMENT NO.1.2
//STACK USING LINKED LIST

#include<stdio.h>
#include<conio.h>
void push();
void pop();
void display();
struct node
{
   int val;
   struct node *next;
};
struct node *head;
void main()
{
  int ch=0;
  clrscr();
  while(ch!=4)
  {
     printf("\n--------------------------Menu--------------------------------");
     printf("\n1.Push \t 2.Pop \t 3.Display \t 4.Exit");
     printf("\n--------------------------------------------------------------");
     printf("\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:push();
	      break;
       case 2:pop();
	      break;
       case 3:display();
	      break;
       case 4:exit(0);
	      break;
       default:printf("Enter valid choice...");
     }
  }
}
void push()
{
   int val;
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
      printf("Unable to push the element..");
   }
   else
   {
      printf("Enter the value:");
      scanf("%d",&val);
      if(head==NULL)
      {
	  ptr->val=val;
	  ptr->next=NULL;
	  head=ptr;
      }
      else
      {
	  ptr->val=val;
	  ptr->next=head;
	  head=ptr;
      }
      printf("Item pushed successfully..");
   }
}
void pop()
{
   int item;
   struct node *ptr;
   if(head==NULL)
   {
      printf("Underflow..");
   }
   else
   {
      item=head->val;
      ptr=head;
      head=head->next;
      free(ptr);
      printf("Item poped..");
   }
}
void display()
{
   int i;
   struct node *ptr;
   ptr=head;
   if(ptr==NULL)
   {
      printf("Stack is empty..");
   }
   else
   {
      printf("Elements in stack are:\n");
      while(ptr!=NULL)
      {
	 printf("%d\t",ptr->val);
	 ptr=ptr->next;
      }
   }
}

