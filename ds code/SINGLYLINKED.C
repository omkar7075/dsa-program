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
