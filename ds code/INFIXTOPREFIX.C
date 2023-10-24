//EXPERIMENT NO 5.1
//Write a program to evaluate infix expression to prefix expression. 


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item)
{
   if(top>=SIZE-1)
   {
      printf("\nStack Overflow.");
   }
   else
   {
      top=top+1;
      stack[top]=item;
   }
}
char pop()
{
   char item;
   if(top<0)
   {
      printf("stack under flow: invalid infix expression");
      getchar();
      exit(1);
   }
   else
   {
      item=stack[top];
      top=top-1;
      return(item);
   }
}
int is_operator(char symbol)
{
   if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int precedence(char symbol)
{
   if(symbol=='^')
   {
      return(3);
   }
   else if(symbol=='*'||symbol=='/')
   {
      return(2);
   }
   else if(symbol=='+'||symbol=='-')
   {
      return(1);
   }
   else
   {
      return(0);
   }
}
void InfixToPrefix(char infix_exp[], char prefix_exp[])
{
   int i,j;
   char item,x;
   push('(');
   strcat(infix_exp,")");
   i=0;
   j=0;
   item=infix_exp[i];
   while(item!='\0')
   {
      if(item=='(')
      {
	 push(item);
      }
      else if(isdigit(item)||isalpha(item))
      {
	 prefix_exp[j]=item;
	 j++;
      }
      else if(is_operator(item)==1)
      {
	 x=pop();
	 while(is_operator(x)==1&&precedence(x)>=precedence(item))
	 {
	    prefix_exp[j]=x;
	    j++;
	    x=pop();
	 }
	 push(x);
	 push(item);
      }
      else if(item==')')
      {
	 x=pop();
	 while(x!='(')
	 {
	    prefix_exp[j]=x;
	    j++;
	    x=pop();
	 }
      }
      else
      {
	 printf("\nInvalid infix Expression");
	 getchar();
	 exit(1);
      }
      i++;
      item=infix_exp[i];
   }
   if(top>0)
   {
      printf("\nInvalid infix Expression");
      getchar();
      exit(1);
   }
   if(top>0)
   {
      printf("\nInvalid infix Expression");
      getchar();
      exit(1);
   }
   prefix_exp[j]='\0';
}
int main()
{
   char infix[SIZE],prefix[SIZE];
   clrscr();
   printf("Enter Infix expression: ");
   gets(infix);
   strrev(infix);
   InfixToPrefix(infix,prefix);
   printf("Prefix Expression:");
   strrev(prefix);
   puts(prefix);
   getch();
   return 0;
}

