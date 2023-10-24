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

