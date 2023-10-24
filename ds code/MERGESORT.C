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
