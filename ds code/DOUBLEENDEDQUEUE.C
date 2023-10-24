//EXPERIMENT NO 3.1
//Write a program to implement double ended queue (dequeuer) using arrays. 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int deque[size];
int f=-1,r=-1;
void insert_front(int x)
{
   if((f==0&&r==size-1)||(f==r+1))
   {
      printf("Overflow..");
   }
   else if((f==-1)&&(r==-1))
   {
      f=r=0;
      deque[f]=x;
      printf("Element inserted successfully..");
   }
   else if(f==0)
   {
      f=size-1;
      deque[f]=x;
      printf("Element inserted successfully..");
   }
   else
   {
      f=f-1;
      deque[f]=x;
      printf("Element inserted successfully..");
   }
}
void insert_rear(int x)
{
   if((f==0&&r==size-1)||(f==r+1))
   {
      printf("Overflow..");
   }
   else if((f==-1)&&(r==-1))
   {
      r=0;
      deque[r]=x;
      printf("Element inserted successfully..");
   }
   else if(r==size-1)
   {
      r=0;
      deque[r]=x;
      printf("Element inserted successfully..");
   }
   else
   {
      r++;
      deque[r]=x;
      printf("Element inserted successfully..");
   }
}
void display()
{
   int i=f;
   printf("Elements in dequeue are:\n");
   while(i!=r)
   {
      printf("%d\t",deque[i]);
      i=(i+1)%size;
   }
   printf("%d",deque[r]);
}
void getfront()
{
   if((f==-1)&&(r==-1))
   {
      printf("Deque is empty..");
   }
   else
   {
      printf("The element at front is: %d ",deque[f]);
   }
}
void getrear()
{
   if((f==-1)&&(r==-1))
   {
      printf("Deque is empty..");
   }
   else
   {
      printf("The element at rear is %d ", deque[r]);
   }
}
void delete_front()
{
   if((f==-1)&&(r==-1))
   {
      printf("Deque is empty..");
   }
   else if(f==r)
   {
      printf("The deleted element is %d ", deque[f]);
      f=-1;
      r=-1;
   }
   else if(f==(size-1))
   {
      printf("The deleted element is %d ", deque[f]);
      f=0;
   }
   else
   {
      printf("The deleted element is %d ", deque[f]);
      f=f+1;
   }
}
void delete_rear()
{
   if((f==-1)&&(r==-1))
   {
      printf("Deque is empty..");
   }
   else if(f==r)
   {
      printf("The deleted element is %d ", deque[r]);
      f=-1;
      r=-1;
   }
   else if(r==0)
   {
      printf("The deleted element is %d ", deque[r]);
      r=size-1;
   }
   else
   {
      printf("The deleted element is %d ", deque[r]);
      r=r-1;
   }
}
void main()
{
   int ch,x;
   clrscr();
   while(1)
   {
      printf("\n-------------------------------Menu-----------------------------------");
      printf("\n1.Insert from front \t2.Insert from rear \t3.Delete from front");
      printf("\n4.Delete from rear \t5.Get rear \t6.Get front \t7.Display");
      printf("\n8.Exit");
      printf("\n----------------------------------------------------------------------");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("Enter number:");
		scanf("%d",&x);
		insert_front(x);
		break;
	 case 2:printf("Enter number:");
		scanf("%d",&x);
		insert_rear(x);
		break;
	 case 3:delete_front();
		break;
	 case 4:delete_rear();
		break;
	 case 5:getrear();
		break;
	 case 6:getfront();
		break;
	 case 7:display();
		break;
	 case 8:exit(0);
	 default: printf("Invalid choice..");
      }
   }
}


 
 

 



