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
 
