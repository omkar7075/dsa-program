//EXPERIMENT NO 1.4
//QUEUE USING LINKED LIST

#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *next;
};
struct node *front,*rear;
void enqueue();
void dequeue();
void display();
void main()
{
   int ch;
   clrscr();
   while(ch!=4)
   {
       printf("\n-------------------------Menu--------------------------------");
       printf("\n1.Enqueue \t 2.Dequeue \t 3.Display \t 4.Exit");
       printf("\n-------------------------------------------------------------");
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:enqueue();
		 break;
	  case 2:dequeue();
		 break;
	  case 3:display();
		 break;
	  case 4:exit(0);
		 break;
	  default:printf("Invalid choice...");
       }
   }
}
void enqueue()
{
   struct node *ptr;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
       printf("Overflow...");
   }
   else
   {
       printf("Enter element:");
       scanf("%d",&item);
       ptr->data=item;
       if(front==NULL)
       {
	  front=ptr;
	  rear=ptr;
	  front->next=NULL;
	  rear->next=NULL;
	   printf("Element insert successfully..");
       }
       else
       {
	  rear->next=ptr;
	  rear=ptr;
	  rear->next=NULL;
	  printf("Element insert successfully..");
       }
   }
}
void dequeue()
{
   struct node *ptr;
   if(front==NULL)
   {
      printf("Underflow...");
   }
   else
   {
      ptr=front;
      front=front->next;
      free(ptr);
      printf("Element deleted successfully...");
   }
}
void display()
{
   struct node *ptr;
   ptr=front;
   if(front==NULL)
   {
      printf("Queue is empty..");
   }
   else
   {
      printf("Elements in queue are:\n");
      while(ptr!=NULL)
      {
	 printf("%d\t",ptr->data);
	 ptr=ptr->next;
      }
   }
}
