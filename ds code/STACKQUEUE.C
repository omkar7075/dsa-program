//EXPERIMENT NO 6.1
//Write a program to implement a stack using two queues.


#include<stdio.h>
#include<conio.h>
#define n 20
int queue1[n],queue2[n];
int f1=-1,r1=-1;
int f2=-1,r2=-1;
int count=0;
void enqueue1(int x);
int dequeue1();
void enqueue2(int x);
int dequeue2();
void push(int x);
int pop();
void display();
void main()
{
   int ch,num;
   clrscr();
   while(ch!=4)
   {
      printf("\n-------------------------Menu--------------------------");
      printf("\n1.Push \t2.Pop \t3.Display \t4.Exit");
      printf("\n-------------------------------------------------------");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("Enter element:");
		scanf("%d",&num);
		push(num);
		break;
	 case 2:printf("Element deleted is %d",pop());
		break;
	 case 3:display();
		break;
	 case 4:exit(0);
		break;
	 default:printf("Invalid choice..");
      }
   }
}
void enqueue1(int x)
{
   if(r1==n-1)
   {
      printf("Overflow..");
   }
   else
   {
      if(f1==-1)
      {
	 f1=0;
      }
      r1=r1+1;
      queue1[r1]=x;
   }
}
int dequeue1()
{
   int temp;
   if(f1==-1||f1>r1)
   {
      printf("Underflow..");
   }
   else
   {
      temp=queue1[f1];
      f1++;
   }
   return(temp);
}
void enqueue2(int x)
{
   if(r2==n-1)
   {
      printf("Overflow..");
   }
   else
   {
      if(f2==-1)
      {
	 f2=0;
      }
      r2=r2+1;
      queue2[r2]=x;
   }
}
int dequeue2()
{
   int temp;
   if(f2==-1||f2>r2)
   {
      printf("Underflow..");
   }
   else
   {
      temp=queue2[f2];
      f2++;
   }
   return(temp);
}
void push(int x)
{
  int i;
  enqueue1(x);
  for(i=0;i<count;i++)
  {
     enqueue1(dequeue2());
  }
  count++;
  for(i=0;i<count;i++)
  {
     enqueue2(dequeue1());
  }
}
int pop()
{
   count--;
   return dequeue2();
}
void display()
{
   int i;
   printf("Elements in stack are:");
   for(i=f2;i<=r2;i++)
   {
      printf("%d\t",queue2[i]);
   }
}

