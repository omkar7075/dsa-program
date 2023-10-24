//EXPERIMENT NO 1.3
//QUEUE USIG ARRAY

#include<stdio.h>
#include<conio.h>
#define max 5
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1;
int queue[max];
void main()
{
    int ch;
    clrscr();
    while(ch!=4)
    {
	printf("\n----------------------Menu-----------------------------");
	printf("\n1.Enqueue \t2.Dequeue \t3.Display \t4.Exit");
	printf("\n-------------------------------------------------------");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{

	    case 1:
	    enqueue();
	    break;
	    case 2:
	    dequeue();
	    break;
	    case 3:
	    display();
	    break;
	    case 4:
	    exit(0);
	    break;
	    default:
	    printf("Enter valid choice...");
	}
    }
}
void enqueue()
{
    int item;
    if(rear==max-1)
	printf("Overflow...");
    else
    {
       printf("Enter element:");
       scanf("%d",&item);
       if(front==-1 && rear==-1)
       {
	  front=0;
	  rear=0;
       }
       else
	  rear=rear+1;
       queue[rear]=item;
       printf("Value inserted successfully...");
    }
}
void dequeue()
{
   int item;
   if(front==-1 || front>rear)
      printf("Underflow...");
   else
   {
      item=queue[front];
      if(front==rear)
      {
	 front=-1;
	 rear=-1;
      }
      else
      {
	 front=front+1;
      }
      printf("Value deleted successfully...");
   }
}
void display()
{
   int i;
   if(rear==-1)
      printf("Underflow...");
   else
   {
      printf("Elements of queue are:\n");
      for(i=front;i<=rear;i++)
	 printf("%d\t",queue[i]);
   }
}
