#include<stdio.h>
#include<stdlib.h>
void insertionsort();
void msort(int[],int,int);
void quicksort(int[],int,int);
void heapsort();
void display();
int size=6;
int A[50],B[50],item,beg,mid,end,i,j,k;
int main()
{
 int choice,u=0;
 printf("\n\tEnter the elements in array\n\t");
 for(i=1;i<=size;i++)
 {
    scanf("%d",&A[i]);
    printf("\n\t");
 }
 while(u==0)
 {
      printf("\n\t1.Insertion Sort\n\t2.Quick Sort");
      printf("\n\tPress another key to exit\n\tEnter your choice\n\t");
      scanf("%d",&choice);
      switch(choice)
      {
         case  1: insertionsort();
                  break;
         case  2: quicksort(A,1,size);
                  display();
                  break;
         default: exit(0);
      }
 }
 return 0;
}
void insertionsort()
{
  int temp;
  for(k=1;k<=size;k++)
  {
    temp=A[k];
    j=k-1;
    while(temp<A[j]&&j>=0)
    {
      A[j+1]=A[j];
      j=j-1;
    }
        A[j+1]=temp;
  }
  display();
}
void quicksort(int A[50],int low,int high)
{
 int pivot,temp;
 if(low<high)
 {
  pivot = low;
  i = low;
  j = high;
  while(i<j)
  {
     while((A[i]<=A[pivot])&&(i<high))
      i++;
     while(A[j]>A[pivot])
      j--;
     if(i<j)
     {
       temp=A[i];
       A[i]=A[j];
       A[j]=temp;
     }
  }
  temp=A[pivot];
  A[pivot]=A[j];
  A[j]=temp;
  quicksort(A,low,j-1);
  quicksort(A,j+1,high);
 }
}
void display()
{
  printf("\n\tThe elements in sorted array are:\n\t");
  for(i=1;i<=size;i++)
    printf("%d\t",A[i]);
}
