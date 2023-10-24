

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


 
 //EXPERIMENT NO 4.1
//Write a program to convert a given infix expression to postfix form using stacks.


#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;  
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}



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


//EXPERIMENT NO 8.1
//Write a program to implement singly linked list.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void beg_insert();
void end_insert();
void ran_insert();
void beg_delete();
void end_delete();
void ran_delete();
void display();
void search();
void main()
{
    int ch=0;
    clrscr();
    while(ch!=9)
    {
	printf("\n-------------------------------Menu-------------------------------------");
	printf("\n1.Begin Insert \t2.Random Insert \t3.End Insert \t4.Begin Delete");
	printf("\n5.Random Delete \t6.End Delete \t7.Display \t8.Search \n9.Exit");
	printf("\n-----------------------------------------------------------------------");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:beg_insert();
		   break;
	    case 2:ran_insert();
		   break;
	    case 3:end_insert();
		   break;
	    case 4:beg_delete();
		   break;
	    case 5:ran_delete();
		   break;
	    case 6:end_delete();
		   break;
	    case 7:display();
		   break;
	    case 8:search();
		   break;
	    case 9:exit(0);
		   break;
	    default:printf("Invalid choice..");
	}
    }
}
void beg_insert()
{
   struct node *ptr;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node *));
   if(ptr==NULL)
   {
       printf("\nOverflow..");
   }
   else
   {
       printf("Enter element:");
       scanf("%d",&item);
       ptr->data=item;
       ptr->next=head;
       head=ptr;
       printf("Node inserted successfully..");
   }
}
void ran_insert()
{
   int i,loc,item;
   struct node *ptr,*temp;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
	printf("Overflow..");
   }
   else
   {
       printf("Enter element:");
       scanf("%d",&item);
       ptr->data=item;
       printf("Enter the location after which you want to insert:");
       scanf("%d",&loc);
       temp=head;
       for(i=0;i<loc;i++)
       {
	  temp=temp->next;
	  if(temp==NULL)
	  {
	      printf("Insertion failed..");
	  }
       }
       ptr->next=temp->next;
       temp->next=ptr;
       printf("Node Inserted successfully..");
   }
}
void end_insert()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
     printf("Overflow..");
   }
   else
   {
      printf("Enter element:");
      scanf("%d",&item);
      ptr->data=item;
      if(head==NULL)
      {
	  ptr->next=NULL;
	  head=ptr;
	  printf("Node inserted successfully..");
      }
      else
      {
	 temp=head;
	 while(temp->next!=NULL)
	 {
	    temp=temp->next;
	 }
	 temp->next=ptr;
	 ptr->next=NULL;
	 printf("Node inserted successfully..");
      }
   }
}
void beg_delete()
{
   struct node *ptr;
   if(head==NULL)
   {
      printf("List is empty..");
   }
   else
   {
      ptr=head;
      head=ptr->next;
      free(ptr);
      printf("Node deleted successfully..");
   }
}
void ran_delete()
{
   struct node *ptr,*ptr1;
   int loc,i;
   printf("Enter location:");
   scanf("%d",&loc);
   ptr=head;
   for(i=0;i<loc;i++)
   {
      ptr1=ptr;
      ptr=ptr->next;
      if(ptr==NULL)
      {
	  printf("Can't delete..");
      }
   }
   ptr1->next=ptr->next;
   free(ptr);
   printf("Node deleted successfully..");
}
void end_delete()
{
   struct node *ptr,*ptr1;
   if(head==NULL)
   {
      printf("List is empty..");
   }
   else if(head->next==NULL)
   {
      head=NULL;
      free(head);
      printf("Node deleted successfully..");
   }
   else
   {
      ptr=head;
      while(ptr->next!=NULL)
      {
	 ptr1=ptr;
	 ptr=ptr->next;
      }
      ptr1->next=NULL;
      free(ptr);
      printf("Node deleted successfully..");
   }
}
void search()
{
   struct node *ptr;
   int item,i=0,flag;
   ptr = head;
   if(ptr == NULL)
   {
      printf("List is empty..");
   }
   else
   {
      printf("Enter element which you want to search:");
      scanf("%d",&item);
      while (ptr!=NULL)
      {
	if(ptr->data == item)
	{
	   printf("Item found at location %d ",i+1);
	   flag=0;
	}
	else
	{
	   flag=1;
	}
	i++;
	ptr = ptr -> next;
      }
      if(flag==1)
      {
	printf("Item not found");
      }
   }
}
void display()
{
   struct node *ptr;
   ptr=head;
   if(ptr==NULL)
   {
      printf("List is empty..");
   }
   else
   {
      printf("Elements in linked list are:\n");
      while(ptr!=NULL)
      {
	  printf("%d\t",ptr->data);
	  ptr=ptr->next;
      }
   }
}


//EXPERIMENT NO 8.2
//Write a program to implement doubly linked list.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct node *head;
void beg_insert();
void end_insert();
void ran_insert();
void beg_delete();
void end_delete();
void ran_delete();
void display();
void search();
void main()
{
   int ch=0;
   clrscr();
   while(ch!=9)
   {
      printf("\n-------------------------------Main Menu-------------------------------------");
      printf("\n1.Beg_Insert \t 2.End_Insert \t 3.Ran_Insert \t 4.Del_Beg");
      printf("\n5.End_Delete \t 6.Ran_Delete \t 7.Display \t 8.Search \t 9.Exit");
      printf("\n----------------------------------------------------------------------------");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:beg_insert();
		break;
	 case 2:end_insert();
		break;
	 case 3:ran_insert();
		break;
	 case 4:beg_delete();
		break;
	 case 5:end_delete();
		break;
	 case 6:ran_delete();
		break;
	 case 7:display();
		break;
	 case 8:search();
		break;
	 case 9:exit(0);
		break;
	 default:printf("Invalid choice...");
      }
   }
}
void beg_insert()
{
  struct node *ptr;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
     printf("Overflow..");
  }
  else
  {
     printf("Enter element:");
     scanf("%d",&item);
     if(head==NULL)
     {
	ptr->next=NULL;
	ptr->prev=NULL;
	ptr->data=item;
	head=ptr;
     }
     else
     {
	ptr->data=item;
	ptr->prev=NULL;
	ptr->next=head;
	head->prev=ptr;
	head=ptr;
     }
     printf("Node inserted successfully..");
  }
}
void end_insert()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
       printf("Overflow..");
   }
   else
   {
       printf("Enter element:");
       scanf("%d",&item);
	ptr->data=item;
       if(head==NULL)
       {
	  ptr->next=NULL;
	  ptr->prev=NULL;
	  head=ptr;
       }
       else
       {
	  temp=head;
	  while(temp->next!=NULL)
	  {
	     temp=temp->next;
	  }
	  temp->next=ptr;
	  ptr->prev=temp;
	  ptr->next=NULL;
       }
   }
   printf("Node inserted successfully..");
}
void ran_insert()
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
       printf("Overflow..");
   }
   else
   {
      temp=head;
      printf("Enter location:");
      scanf("%d",&loc);
      for(i=0;i<loc;i++)
      {
	 temp=temp->next;
	 if(temp==NULL)
	 {
	    printf("Insertion failed");
	 }
      }
      printf("Enter element:");
      scanf("%d",&item);
      ptr->data=item;
      ptr->next=temp->next;
      ptr->prev=temp;
      temp->next=ptr;
      temp->next->prev=ptr;
      printf("Node inserted successfully..");
   }
}
void beg_delete()
{
   struct node *ptr;
   if(head==NULL)
   {
      printf("Underflow..");
   }
   else if(head->next==NULL)
   {
      head=NULL;
      free(head);
      printf("Node deleted successfully..");
   }
   else
   {
      ptr=head;
      head=head->next;
      head->prev=NULL;
      free(ptr);
      printf("Node deleted successfully..");
   }
}
void end_delete()
{
    struct node *ptr;
    if(head==NULL)
    {
      printf("Underflow..");
    }
    else if(head->next==NULL)
    {
       head=NULL;
       free(head);
       printf("Node deleted successfully..");
    }
    else
    {
       ptr=head;
       if(ptr->next!=NULL)
       {
	  ptr=ptr->next;
       }
       ptr->prev->next=NULL;
       free(ptr);
       printf("Node deleted successfully..");
    }
}
void ran_delete()
{
   struct node *ptr,*temp;
   int val;
   printf("Enter element after which the node is to be deleted:");
   scanf("%d",&val);
   ptr=head;
   while(ptr->data!=val)
   ptr=ptr->next;
   if(ptr->next==NULL)
   {
      printf("Can't delete");
   }
   else if(ptr->next->next==NULL)
   {
      ptr->next=NULL;
   }
   else
   {
      temp=ptr->next;
      ptr->next=temp->next;
      temp->next->prev=ptr;
      free(temp);
      printf("Node deleted successfully..");
    }
}

void display()
{
   struct node *ptr;
   printf("Elements in list are:\n");
   ptr=head;
   while(ptr!=NULL)
   {
      printf("%d\t",ptr->data);
      ptr=ptr->next;
   }
}
void search()
{
   struct node *ptr;
   int item,i=0,flag;
   ptr = head;
   if(ptr == NULL)
   {
      printf("List is empty");
   }
   else
   {
      printf("Enter element:");
      scanf("%d",&item);
      while (ptr!=NULL)
      {
	 if(ptr->data==item)
	 {
	    printf("Item found at location %d ",i+1);
	    flag=0;
	    break;
	 }
	 else
	 {
	    flag=1;
	 }
	 i++;
	 ptr=ptr->next;
      }
      if(flag==1)
      {
	 printf("Item not found");
      }
   }
}


//EXPERIMENT NO 9.1
//Write a program to implement circular linked list.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head;
void beg_insert();
void end_insert();
void beg_delete();
void end_delete();
void display();
void search();
void main()
{
   int ch=0;
   clrscr();
   while(ch!=7)
   {
      printf("\n---------------------------Main Menu-----------------------------------");
      printf("\n1.Beg_Insert \t2.End_Insert \t3.Del_Beg \t4.End_Delete");
      printf("\n5.Display \t6.Search \t7.Exit");
      printf("\n---------------------------------------------------------------------");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:beg_insert();
		break;
	 case 2:end_insert();
		break;
	 case 3:beg_delete();
		break;
	 case 4:end_delete();
		break;
	 case 5:display();
		break;
	 case 6:search();
		break;
	 case 7:exit(0);
		break;
	 default:printf("\nPlease enter valid choice...");
      }
   }
}
void beg_insert()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
      printf("Circular Linked List is empty");
   }
   else
   {
      printf("Enter the node data:");
      scanf("%d",&item);
      ptr->data=item;
      if(head==NULL)
      {
	 head=ptr;
	 ptr->next=head;
      }
      else
      {
	 temp=head;
	 while(temp->next!=head)
	    temp=temp->next;
	 ptr->next=head;
	 temp->next=ptr;
	 head=ptr;
      }
      printf("Node inserted Successfully...");
   }
}
void end_insert()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
     printf("Circular Linked List is empty");
   }
   else
   {
      printf("Enter data:");
      scanf("%d",&item);
      ptr->data=item;
      if(head==NULL)
      {
	 head=ptr;
	 ptr->next=head;
      }
      else
      {
	 temp=head;
	 while(temp->next!=head)
	 {
	   temp=temp->next;
	 }
	 temp->next=ptr;
	 ptr->next=head;
      }
      printf("Node inserted Successfully...");
   }
}
void beg_delete()
{
  struct node *ptr;
  if(head==NULL)
  {
     printf("Circular Linked List is empty");
  }
  else if(head->next==head)
  {
     head=NULL;
     free(head);
     printf("Node deleted Successfully...");
  }
  else
  {
     ptr=head;
     while(ptr->next!=head)
	ptr=ptr->next;
     ptr->next=head->next;
     free(head);
     head=ptr->next;
     printf("Node deleted Successfully...");
  }
}
void end_delete()
{
  struct node *ptr,*prev;
  if(head==NULL)
  {
     printf("Circular Linked List is empty");
  }
  else if(head->next==head)
  {
     head=NULL;
     free(head);
     printf("Node deleted Successfully...");
  }
  else
  {
    ptr=head;
    while(ptr->next!=head)
    {
       prev=ptr;
       ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);
    printf("Node deleted Successfully...");
  }
}
void display()
{
   struct node *ptr;
   ptr=head;
   if(ptr==NULL)
   {
     printf("Circular Linked List is empty");
   }
   else
   {
     printf("Elements in list are:\n");
     while(ptr->next!=head)
     {
	printf("%d\t",ptr->data);
	ptr=ptr->next;
     }
     printf("%d",ptr->data);
   }
}
void search()
{
   struct node *ptr;
   int item,i=0,flag=1;
   ptr=head;
   if(head==NULL)
   {
     printf("Circular Linked List is empty");
   }
   else
   {
     printf("Enter item which you want to search:");
     scanf("%d",&item);
     if(head->data==item)
     {
	printf("Item found at location %d",i+1);
	flag=0;
     }
     else
     {
	while(ptr->next!=head)
	{
	   if(ptr->data==item)
	   {
	      printf("Item found at location %d",i+1);
	      flag=0;
	      break;
	   }
	   else
	   {
	      flag=1;
	   }
	   i++;
	   ptr=ptr->next;
	}
     }
     if(flag!=0)
     {
      printf("Item not found");
     }
  }
}




//EXPEROMENT NO 10
//Write a program to create and traverse through Binary Tree.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *left,*right;
};
struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
void main()
{
   struct node *root;
   int ch;
   clrscr();
   while(ch!=5)
   {
      printf("\n----------------------------------Menu---------------------------------------");
  	printf("\n1.Create node \t2.Inorder \t3.Preorder \t4.Postorder \t5.Exit");
      printf("\n-----------------------------------------------------------------------------");
  	printf("\nEnter your choice:");
  	scanf("%d",&ch);
  	switch(ch)
  	{
        	 case 1:root=create();
                    	break;
        	 case 2:inorder(root);
                    	break;
        	 case 3:preorder(root);
                    	break;
        	 case 4:postorder(root);
                    	break;
        	 case 5:exit(0);
        	 default:printf("Invalid choice..");
  	}
   }
}
struct node *create()
{
   struct node *temp;
   int num;
   temp=(struct node *)malloc(sizeof(struct node));
   printf("Enter data (Press 0 for no node): ");
   scanf("%d",&num);
   if(num==0)
  	return(0);
   temp->data=num;
   printf("Enter left child of %d\n",num);
   temp->left=create();
   printf("Enter right child of %d\n",num);
   temp->right=create();
   return(temp);
}
void preorder(struct node *root)
{
   if(root!=NULL)
   {
  	printf("%d\t",root->data);
  	preorder(root->left);
  	preorder(root->right);
   }
}
void inorder(struct node *root)
{
   if(root!=NULL)
   {
 	inorder(root->left);
 	printf("%d\t",root->data);
 	inorder(root->right);
   }
}
void postorder(struct node *root)
{
   if(root!=NULL)
   {
  	postorder(root->left);
  	postorder(root->right);
  	printf("%d\t",root->data);
   }
}


 
//EXPERIMENT NO 11
//Write a program to create a binary search tree(BST)..

#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *left,*right;
};
struct node *createtree(struct node *root,int data);
struct node *deletetree(struct node *root,int data);
struct node *findmin(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node *root=NULL;
void main()
{
   int data,ch,i,n;
   clrscr();
   while(ch!=6)
   {
      printf("\n-----------------------------Menu--------------------------------");
  	printf("\n1.Insert \t2.Delete \t3.Inorder \t4.Preorder");
  	printf("\n5.Postorder \t6.Exit");
      printf("\n-----------------------------------------------------------------");
  	printf("\nEnter your choice:");
  	scanf("%d",&ch);
  	switch(ch)
  	{
        	 case 1:printf("Enter how many values do you want to insert:");
                    	scanf("%d",&n);
                    	for(i=0;i<n;i++)
                    	{
                    	   printf("Enter element:");
                    	   scanf("%d",&data);
                    	   root=createtree(root,data);
                    	}
                    	break;
        	 case 2:printf("Enter element to delete:");
                    	scanf("%d",&data);
                    	root=deletetree(root,data);
                    	break;
        	 case 3:printf("Inorder Traversal:");
                    	inorder(root);
                    	break;
        	 case 4:printf("Preorder Traversal:");
                    	preorder(root);
                    	break;
        	 case 5:printf("Postorder Traversal:");
                    	postorder(root);
                    	break;
        	 case 6:exit(0);
        	 default:printf("Invalid choice..");
  	}
   }
}
struct node *createtree(struct node *root,int data)
{
   if(root==NULL)
   {
  	struct node *temp;
  	temp=(struct node *)malloc(sizeof(struct node));
  	temp->data=data;
  	temp->left=NULL;
      temp->right=NULL;
  	return(temp);
   }
   if(data<(root->data))
       root->left=createtree(root->left,data);
   else if(data>root->data)
       root->right=createtree(root->right,data);
   return root;
}
void preorder(struct node *root)
{
   if(root!=NULL)
   {
  	printf("%d\t",root->data);
  	preorder(root->left);
  	preorder(root->right);
   }
}
void inorder(struct node *root)
{
   if(root!=NULL)
   {
 	inorder(root->left);
 	printf("%d\t",root->data);
 	inorder(root->right);
   }
}
void postorder(struct node *root)
{
   if(root!=NULL)
   {
  	postorder(root->left);
  	postorder(root->right);
  	printf("%d\t",root->data);
   }
}
struct node *deletetree(struct node *root,int data)
{
   struct node *temp;
   if(root==NULL)
  	printf("Element not found..");
   else if(data<root->data)
      root->left=deletetree(root->left,data);
   else if(data>root->data)
      root->right=deletetree(root->right,data);
   else
   {
  	if(root->right&&root->left)
  	{
        	 temp=findmin(root->right);
        	 root->data=temp->data;
  	}
  	else
  	{
        	 temp=root;
        	 if(root->left==NULL)
        	    root=root->right;
        	 else if(root->right==NULL)
        	    root=root->left;
        	    free(temp);
        	    printf("Element deleted..");
  	}
   }
   return root;
}
struct node *findmin(struct node *root)
{
  if(root==NULL)
 	return NULL;
  if(root->left)
 	return findmin(root->left);
  else
 	return root;
}



 

 
//EXPERIMENT NO 12
//Write a program to construct an AVL tree for the given set of keys.
// Also write function for deleting a key from the given AVL tree

#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
   int ht;
};
struct node *root = NULL;
struct node *create(int);
struct node *insert(struct node*, int);
struct node *delete(struct node*, int);
struct node *search(struct node*, int);
struct node *rotate_left(struct node*);
struct node *rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void main()
{
   int ch,data,i,n;
   struct node* result = NULL;
   clrscr();
   while (ch!=7)
   {
      printf("\n---------------------------MENU-----------------------------");
  	printf("\n1.Insert \t2.Delete \t3.Search \t4.Inorder");
  	printf("\n5.Preorder \t6.Postorder \t7.Exit");
      printf("\n------------------------------------------------------------");
  	printf("\nEnter your choice:");
  	scanf("%d",&ch);
  	switch(ch)
  	{
        	 case 1:printf("Enter how many elements you want to insert:");
                    	scanf("%d",&n);
                    	for(i=0;i<n;i++)
                    	{
                    	   printf("Enter value:");
                    	   scanf("%d",&data);
                    	   root=insert(root,data);
                    	}
                    	break;
        	 case 2:printf("Enter data:");
                    	scanf("%d",&data);
                    	root=delete(root,data);
                    	printf("Key deleted..");
                    	break;
        	 case 3:printf("Enter data:");
                    	scanf("%d",&data);
                    	result=search(root,data);
                    	if(result==NULL)
                    		printf("Node not found!");
                    	else
                    		printf("Node found");
                    	break;
        	 case 4:printf("Inorder traversal:");
                    	inorder(root);
                    	break;
        	 case 5:printf("Preorder tracersal:");
                    	preorder(root);
                    	break;
        	 case 6:printf("Postorder traversal:");
                    	postorder(root);
                    	break;
        	 case 7:exit(0);
        	 default:printf("Invalid Choice..");
  	}
   }
   getch();
}
struct node *create(int data)
{
   struct node *new_node=(struct node *)malloc(sizeof(struct node));
   if (new_node==NULL)
   {
  	printf("Memory can't be allocated..");
        	 return NULL;
   }
   new_node->data=data;
   new_node->left=NULL;
   new_node->right=NULL;
   return new_node;
}
struct node *rotate_left(struct node *root)
{
   struct node *right_child=root->right;
   root->right=right_child->left;
   right_child->left=root;
   root->ht=height(root);
   right_child->ht=height(right_child);
   return right_child;
}
struct node *rotate_right(struct node *root)
{
   struct node *left_child=root->left;
   root->left=left_child->right;
   left_child->right=root;
   root->ht=height(root);
   left_child->ht=height(left_child);
   return left_child;
}
int balance_factor(struct node *root)
{
   int lh,rh;
   if(root==NULL)
   	return 0;
   if(root->left==NULL)
   	lh=0;
   else
   	lh=1+root->left->ht;
   if(root->right==NULL)
   	rh=0;
   else
   	rh=1+root->right->ht;
   return lh-rh;
}
int height(struct node *root)
{
   int lh,rh;
   if(root==NULL)
  	return 0;
   if(root->left==NULL)
  	lh=0;
   else
  	lh=1+root->left->ht;
   if(root->right==NULL)
  	rh=0;
   else
  	rh=1+root->right->ht;
   if(lh>rh)
  	return (lh);
   return (rh);
}
struct node *insert(struct node *root,int data)
{
   if(root==NULL)
   {
  	struct node *new_node=create(data);
  	if(new_node==NULL)
        	  return NULL;
  	root=new_node;
   }
   else if(data>root->data)
   {
       root->right=insert(root->right,data);
   	if(balance_factor(root)==-2)
   	{
        	  if(data>root->right->data)
                    	root=rotate_left(root);
        	  else
        	  {
        	     root->right=rotate_right(root->right);
        	     root=rotate_left(root);
        	  }
   	}
   }
   else
   {
   	root->left=insert(root->left, data);
       if(balance_factor(root)==2)
   	{
        	  if(data<root->left->data)
        	     root=rotate_right(root);
        	  else
        	  {
        	     root->left=rotate_left(root->left);
        	     root=rotate_right(root);
        	  }
   	}
   }
   root->ht=height(root);
   return root;
}
struct node *delete(struct node *root,int x)
{
   struct node *temp=NULL;
   if(root==NULL)
   	return NULL;
   if(x>root->data)
   {
  	root->right=delete(root->right,x);
  	if(balance_factor(root)==2)
  	{
        	 if(balance_factor(root->left)>=0)
        	      root=rotate_right(root);
        	 else
        	 {
        	     root->left=rotate_left(root->left);
        	     root=rotate_right(root);
        	 }
  	}
   }
   else if(x<root->data)
   {
   	root->left=delete(root->left,x);
   	if(balance_factor(root)==-2)
   	{
        	  if(balance_factor(root->right)<=0)
        	      root=rotate_left(root);
        	  else
        	  {
        	      root->right=rotate_right(root->right);
        	      root=rotate_left(root);
        	  }
   	}
   }
   else
   {
  	if(root->right!=NULL)
      {
        	  temp=root->right;
        	  while(temp->left!=NULL)
        	     temp=temp->left;
        	  root->data=temp->data;
        	  root->right=delete(root->right,temp->data);
        	  if(balance_factor(root)==2)
        	  {
        	     if(balance_factor(root->left)>=0)
                    	root = rotate_right(root);
        	     else
        	     {
                    	root->left=rotate_left(root->left);
                    	root=rotate_right(root);
        	     }
        	  }
  	}
  	else
        	 return (root->left);
   }
   root->ht=height(root);
   return (root);
}
struct node *search(struct node *root,int key)
{
   if(root==NULL)
   	return NULL;
   if(root->data==key)
   	return root;
   if(key>root->data)
   	search(root->right,key);
   else
   	search(root->left,key);
}
void inorder(struct node *root)
{
   if(root==NULL)
  	return;
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}
void preorder(struct node *root)
{
   if(root==NULL)
  	return;
   printf("%d ",root->data);
   preorder(root->left);
   preorder(root->right);
}
void postorder(struct node *root)
{
   if(root==NULL)
  	return;
   postorder(root->left);
   postorder(root->right);
   printf("%d ",root->data);
}




//EXEPERIMENT NO 13
//Write a program for implementation of graph traversals by applying:
//a. BFS  b. DFS
 

#include<stdio.h>
#include<conio.h>
int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int delete();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void main()
{
   int n,i,s,ch,j;
   clrscr();
   printf("Enter number of vertices:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
  	for(j=1;j<=n;j++)
  	{
        	 printf("Enter 1 if %d has a node with %d else 0:",i,j);
        	 scanf("%d",&a[i][j]);
  	}
   }
   printf("The adjacency matrix is:\n");
   for(i=1;i<=n;i++)
   {
  	for(j=1;j<=n;j++)
  	{
        	 printf(" %d",a[i][j]);
  	}
  	printf("\n");
   }
   while(ch!=3)
   {
  	for(i=1;i<=n;i++)
  	vis[i]=0;
      printf("\n-----------------MENU-----------------");
  	printf("\n1.B.F.S \t2.D.F.S \t3.Exit");
      printf("\n--------------------------------------");
  	printf("\nEnter your choice:");
  	scanf("%d",&ch);
  	switch(ch)
  	{
        	 case 1:printf("Enter the source vertex:");
                    	scanf("%d",&s);
                    	bfs(s,n);
                    	break;
        	 case 2:printf("Enter the source vertex:");
                    	scanf("%d",&s);
                    	dfs(s,n);
                    	break;
        	 case 3:exit(0);
        	 default:printf("Invalid choice..");
  	}
   }
   getch();
}
void bfs(int s,int n)
{
   int p,i;
   add(s);
   vis[s]=1;
   p=delete();
   if(p!=0)
  	printf("%d\t",p);
   while(p!=0)
   {
  	for(i=1;i<=n;i++)
  	{
        	 if((a[p][i]!=0)&&(vis[i]==0))
        	 {
        	    add(i);
        	    vis[i]=1;
        	 }
        	 p=delete();
        	 if(p!=0)
        	    printf("%d\t",p);
  	}
   }
   for(i=1;i<=n;i++)
   {
  	if(vis[i]==0)
        	 bfs(i,n);
   }
}
void add(int item)
{
   if(rear==19)
  	printf("Queue full");
   else
   {
  	if(rear==-1)
  	{
        	 q[++rear]=item;
        	 front++;
  	}
  	else
        	 q[++rear]=item;
   }
}
int delete()
{
   int k;
   if((front>rear)||(front==-1))
  	return(0);
   else
   {
  	k=q[front++];
        	 return(k);
   }
}
void dfs(int s,int n)
{
   int i,k;
   push(s);
   vis[s]=1;
   k=pop();
   if(k!=0)
  	printf("%d\t",k);
   while(k!=0)
   {
  	for(i=1;i<=n;i++)
  	{
        	 if((a[k][i]!=0)&&(vis[i]==0))
        	 {
        	    push(i);
        	    vis[i]=1;
        	 }
        	 k=pop();
        	 if(k!=0)
        	 printf("%d\t",k);
  	}
   }
   for(i=1;i<=n;i++)
   {
  	if(vis[i]==0)
        	 dfs(i,n);
   }
}
void push(int item)
{
   if(top==19)
  	printf("Stack overflow ");
   else
  	stack[++top]=item;
}
int pop()
{
   int k;
   if(top==-1)
  	return(0);
   else
   {
  	k=stack[top--];
  	return(k);
   }
}



//EXPERIMNET NO 14.1
//Write a program to implement insertion sort.
 
#include<stdio.h>
#include<conio.h>
void insert(int a[],int n)
{
   int i,j,temp;
   for(i=1;i<n;i++)
   {
  	temp=a[i];
  	j=i-1;
  	while(j>=0 && temp<=a[j])
  	{
        	 a[j+1]=a[j];
        	 j=j-1;
  	}
  	a[j+1]=temp;
   }
}
void display(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
  	printf("%d\t",a[i]);
}
void main()
{
 
   int a[10],n,i;
   clrscr();
   printf("Enter how many elements you want to insert:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
  	printf("Enter element:");
  	scanf("%d",&a[i]);
   }
   printf("Before sorting:\n");
   display(a,n);
   insert(a,n);
   printf("\nAfter sorting:\n");
   display(a,n);
   getch();
}
 


//EXPERIMENT NO 14.2
//Write a program to implement selection sorT

#include<stdio.h>
#include<conio.h>
void selection(int a[],int n)
{
   int i,j,small,temp;
   for(i=0;i<n-1;i++)
   {
  	small=i;
  	for(j=i+1;j<n;j++)
  	if(a[j]<a[small])
        	 small=j;
  	temp=a[small];
  	a[small]=a[i];
  	a[i]=temp;
	}
}
void display(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
  	printf("%d\t",a[i]);
}
void main()
{
   int a[10],n,i;
   clrscr();
   printf("Enter how many elements you want to insert:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
  	printf("Enter element:");
  	scanf("%d",&a[i]);
   }
   printf("Before sorting:\n");
   display(a, n);
   selection(a, n);
   printf("\nAfter sorting:\n");
   display(a, n);
   getch();
}


//EXPERIMENT NO 15.1
//Write a program to implement quick sort.

#include<stdio.h>
#include<conio.h>
void quick(int a[10],int first,int last)
{
   int i,j,pivot,temp;
   if(first<last)
   {
  	pivot=first;
  	i=first;
  	j=last;
  	while(i<j)
  	{
        	 while(a[i]<=a[pivot]&&i<last)
        	    i++;
        	 while(a[j]>a[pivot])
        	    j--;
        	 if(i<j)
        	 {
        	    temp=a[i];
        	    a[i]=a[j];
        	    a[j]=temp;
        	 }
  	}
  	temp=a[pivot];
  	a[pivot]=a[j];
  	a[j]=temp;
  	quick(a,first,j-1);
  	quick(a,j+1,last);
   }
}
void display(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
  	printf("%d\t",a[i]);
}
void main(){
   int i,n,a[10];
   clrscr();
   printf("Enter how many elements you want to insert:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
  	printf("Enter element:");
  	scanf("%d",&a[i]);
   }
   printf("Before sorting:\n");
   display(a,n);
   quick(a,0,n-1);
   printf("\nAfter sorting:\n");
   display(a,n);
   getch();
}



//EXPERIMENT NO 15.2
//Write a program to implement merge sort.

#include <stdio.h>
#include<conio.h>
void merge(int a[],int mid,int low,int high)
{
   int i,j,k,b[20];
   i=low;
   j=mid + 1;
   k=low;
   while(i<=mid&&j<=high)
   {
  	if(a[i]<a[j])
  	{
        	 b[k]=a[i];
        	 i++;
        	 k++;
 	 }
  	else
  	{
        	 b[k]=a[j];
        	 j++;
        	 k++;
  	}
   }
   while(i<=mid)
   {
  	b[k]=a[i];
  	k++;
  	i++;
   }
   while(j<=high)
   {
  	b[k]=a[j];
  	k++;
  	j++;
   }
   for(i=low;i<=high;i++)
  	a[i]=b[i];
}
void mergeSort(int a[],int low,int high)
{
   int mid;
   if(low<high)
   {
  	mid=(low+high)/2;
  	mergeSort(a,low,mid);
  	mergeSort(a,mid+1,high);
  	merge(a,mid,low,high);
   }
}
void display(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
        	printf("%d\t",a[i]);
}
void main()
{
   int a[10],n,i;
   clrscr();
   printf("Enter how many elements you want to insert:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
  	printf("Enter element:");
  	scanf("%d",&a[i]);
   }
   printf("Before sorting:\n");
   display(a,n);
   mergeSort(a,0,n-1);
   printf("\nBefore sorting:\n");
   display(a, n);
   getch();
}

 



