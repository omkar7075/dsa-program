//EXPERIMENT NO 2.1
//Write a program to implement circular queue using arrays.


#include<stdio.h>
#include<conio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();
void main()
{
   int ch;
   clrscr();
   while(ch!=4)
   {
       printf("\n------------------------------Menu-------------------------------");
       printf("\n1.Enqueue \t 2.Dequeue \t 3.Display \t 4.Exit");
       printf("\n-----------------------------------------------------------------");
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
	 default:printf("Invalid choice..");
      }
   }
}
void enqueue()
{
  int item;
  if((rear+1)%max==front)
  {
     printf("Overflow..");
  }
  printf("Enter element:");
  scanf("%d",&item);
  if(front==-1 && rear==-1)
  {
     front=0;
     rear=0;
     queue[rear]=item;
     printf("Element inserted successfully..");
  }
  else
  {
     rear=(rear+1)%max;
     queue[rear]=item;
     printf("Element inserted successfully..");
  }
}
void dequeue()
{
   if(front==-1 && rear==-1)
   {
      printf("Underflow..");
   }
   else if(front==rear)
   {
      front=-1;
      rear=-1;
      printf("Element deleted successfully..");
   }
   else
   {
      front=(front+1)%max;
      printf("Element deleted successfully..");
   }
}
void display()
{
  int i=front;
  if(front==-1 && rear==-1)
	printf("Underflow..");
  else
  {
      printf("Elements in queue are:\n");
      while(i<=rear)
      {
	 printf("%d\t",queue[i]);
	 i=(i+1)%max;
      }
  }
}
