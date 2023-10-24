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
