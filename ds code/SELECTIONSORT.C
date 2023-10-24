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
