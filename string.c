#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char A[50],B[50];
int i,j,S;
int stringcmp(char[],char[]);
void stringcat(char[],char[]);
void stringcpy(char[],char[]);
void display(char[],int);
int main()
{
 int choice,u=0;
 printf("\n\tEnter the string1\n\t");
 scanf("%s",A);
 printf("\n\tEnter the string2\n\t");
 scanf("%s",B);
 while(u==0)
 {
    printf("\n\t1.String Compare\n\t2.String Copy\n\t3.String Concatenate");
    printf("\n\tPress another key to exit\n\tEnter your choice\n\t");
    scanf("%d",&choice);
    switch(choice)
    {
       case  1: S=stringcmp(A,B);
                if(S!=0)
                  printf("\n\tStrings are not equal\n\t");
                else
                  printf("\n\tStrings are equal\n\t");
                break;
       case  2: stringcpy(A,B);
                display(A,1);
                display(B,2);
                break;
       case  3: stringcat(A,B);
                display(A,1);
                break;
       default: exit(0);
   }
 }
 return 0;
}
int stringcmp(char A[],char B[])
{
  for(i=0;i<=strlen(A)-1;i++)
  {
    for(j=0;j<=strlen(B)-1;j++)
    {
      if(A[i]==B[j])
         S=0;
      else
         S=S+1;
    }
  }
  return S;
}
void stringcpy(char A[],char B[])
{
  i=0;
  for(j=0;j<=strlen(B)-1;j++)
  {
      A[i]=B[j];
       i++;
  }
}
void stringcat(char A[],char B[])
{
  i=strlen(A);
  for(j=0;j<=strlen(B)-1;j++)
  {
     A[i]=B[j];
     i++;
  }
}
void display(char C[],int S)
{
  printf("\n\tThe string %d is:",S);
  printf("\n\t%s\n\t",C);
}