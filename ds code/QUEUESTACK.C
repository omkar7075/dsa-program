//EXPERIMENT NO 7.1
//Write a program to implement a queue using two stacks.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 10
int s1[n],s2[n];
int top1=-1;
int top2=-1;
int count=0;
void enqueue(int x);
void deque();
void push1(int x);
void push2(int x);
int pop1();
int pop2();
void display();
void main()
{
   int ch,x;
   clrscr();
   while(ch!=4)
   {
      printf("\n----------------------------Menu-------------------------");
      printf("\n1.Enqueue \t2.Dequeue \t3.Display \t4.Exit");
      printf("\n---------------------------------------------------------");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("Enter element:");
		scanf("%d",&x);
		enqueue(x);
		break;
	 case 2:deque();
		break;
	 case 3:display();
		break;
	 case 4:exit(0);
	 default:printf("Invalid choice..");
      }
   }
}
void enqueue(int x)
{
  push1(x);
  count++;
}
void push1(int x)
{
  if(top1==n-1)
  {
     printf("Stack is full..");
  }
  else
  {
     top1++;
     s1[top1]=x;
  }
}
void push2(int x)
{
   if(top2==n-1)
   {
      printf("Stack is full..");
   }
   else
   {
      top2++;
      s2[top2]=x;
   }
}
int pop1()
{
   return(s1[top1--]);
}
int pop2()
{
   return(s2[top2--]);
}
void deque()
{
   int i,a,b;
   if(top1==-1&&top2==-1)
   {
      printf("Stack is empty..");
   }
   else
   {
      for(i=0;i<count;i++)
      {
	 a=pop1();
	 push2(a);
      }
      b=pop2();
      printf("Deleted element is %d",b);
      count--;
      for(i=0;i<count;i++)
      {
	 a=pop2();
	 push1(a);
      }
   }
}
void display()
{
   int i;
   printf("Elements in queue are:\n");
   for(i=0;i<=top1;i++)
   {
      printf("%d\t",s1[i]);
   }
}
