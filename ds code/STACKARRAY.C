//EXPERIMENT NO  1.1
//stack using array

#include<stdio.h>
#include<conio.h>
#define max 5
int top=-1,stack[max];
void push();
void pop();
void display();
void main()
{
   int ch;
   clrscr();
   while(1)
   {
     printf("\n------------------------Menu------------------------------");
     printf("\n1.Push \t 2.Pop \t 3.Display\t4.Exit");
     printf("\n----------------------------------------------------------");
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
	default:
	  printf("Enter valid choice....");
     }
   }
}
void push()
{
  int val;
  if(top==max-1)
      printf("Stack is full...");
  else
  {
     printf("Enter element to push:");
     scanf("%d",&val);
     top=top+1;
     stack[top]=val;
     printf("Element inserted successfully...");
  }
}
void pop()
{
   if(top==-1)
     printf("Stack is empty...");
   else
   {
     top=top-1;
     printf("Element deleted successfully...");
   }
}
void display()
{
  int i;
  if(top==-1)
     printf("Stack is empty...");
  else
  {
     printf("Elements in stack are:\n");
     for(i=0;i<=top;i++)
	printf("%d\t",stack[i]);
  }
}
