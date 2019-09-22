#include<stdio.h>
#include<stdlib.h>
int i=0,k,item,BST[50],flag,ptr=0;
void searchBST(int);
void insertBST(int);
void deleteBST(int);
void display();
int main()
{
  int choice,k=0;
  while(k==0)
  {
    printf("\n\t1.Search\n\t2.Insertion\n\t3.Deletion\n\t4.Display");
    printf("\n\tPress another key to exit\n\tEnter your choice\n\t");
    scanf("%d",&choice);
    switch(choice)
    {
       case  1: if(ptr!=0)
                {
                  printf("\n\tEnter the item to be searched\n\t");
                  scanf("%d",&item);
                  searchBST(item);
                }
                else
                  printf("\n\tNo tree created\n\t");
                break;
       case  2: printf("\n\tEnter the item to be inserted\n\t");
                scanf("%d",&item);
                insertBST(item);
                break;
       case  3: if(ptr!=0)
                {
                  printf("\n\tEnter the item to be deleted\n\t");
                  scanf("%d",&item);
                  deleteBST(item);
                }
                else
                  printf("\n\tNo tree created\n\t");
                break;
       case  4: display();
                break;
       default: exit(0);
    }
 }
 return 0;
}
void searchBST(int item)
{
  int j=1;
  flag=0;
  while(BST[j]&&flag==0)
  {
    if(item<BST[j])
       j=2*j;
    else if(item>BST[j])
       j=(2*j)+1;
    else
       flag=1;
  }
  if(flag==0)
    printf("\n\tItem not found\n\t");
  else
    printf("\n\tItem found at position %d\n\t",j);
}
void insertBST(int item)
{
  int p;
  if(i==0)
  {
     i=i+1;
     BST[i]=item;
     ptr=ptr+1;
  }
  else
  {
     i=1;
     while(BST[i]!=0)
     {
        if(item < BST[i])
        {
          p=BST[i];
          i=2*i;
          if(BST[i]==0)
            break;
        }
        else if(item > BST[i])
        {
          p=BST[i];
          i=2*i+1;
          if(BST[i]==0)
            break;
        }
        else
        {
          printf("\n\tItem alredy exists\n\t");
          break;
        }
     }
     if(BST[i]==0)
     {
        ptr=ptr+1;
        if(p<item)
           BST[i]=item;
        else
          BST[i]=item;
     }
  }
}
void preorder1(int BST[],int root)
{
  BST[(root/2)-1]=BST[root];
  BST[root]=0;
  if(BST[2*root]!=0)
    preorder1(BST,2*root);
  if(BST[2*root+1]!=0)
    preorder1(BST,2*root+1);
}
void search(int item)
{
  int j=1;
  flag=0;
  while(BST[j]&&flag==0)
  {
    if(item<BST[j])
       j=2*j;
    else if(item>BST[j])
       j=(2*j)+1;
    else
       flag=1;
  }
}
void deleteBST(int item1)
{
  int succ;
  search(item);
  if(flag!=0)
  {
    i=1;
    while(BST[i]!=item1)
    {
      if(item1<BST[i])
         i=2*i;
      else
        i=2*i+1;
    }
    if(BST[i]!=0)
    {
       if(BST[2*i]==0&&BST[2*i+1]==0)
       {
          BST[i]=0;
          ptr--;
       }
       else if(BST[2*i]==0||BST[2*i+1]==0)
       {
          if(BST[2*i]!=0)
            preorder1(BST,2*i);
                    else
            preorder1(BST,2*i+1);
          ptr--;
       }
       else
       {
         succ=2*i+1;
         while(BST[2*succ]!=0)
         {
           succ=2*succ;
         }
         BST[i]=BST[succ];
         if(BST[2*succ+1]==0)
           BST[succ]=0;
         else
           preorder1(BST,2*i+1);
         ptr--;
       }
    }
  }
  else
    printf("\n\tItem not found\n\t");
}
void inorder(int k)
{
  if (BST[k]!=0)
  {
      inorder(2*k);
      printf("%d\t",BST[k]);
      inorder(2*k+1);
  }
}
void preorder(int k)
{
  if (BST[k]!=0)
  {
      printf("%d\t",BST[k]);
      preorder(2*k);
      preorder(2*k+1);
  }
}
void postorder(int k)
{
  if (BST[k]!=0)
  {
      postorder(2*k);
      postorder(2*k+1);
      printf("%d\t",BST[k]);
  }
}
void display()
{
    if(ptr==0)
       printf("\n\tNo tree to display\n\t");
    else
    {
      k=1;
      printf("\n\tThe inorder traversal of tree is:\n\t");
      inorder(k);
      printf("\n\tThe preorder traversal of tree is:\n\t");
      preorder(k);
      printf("\n\tThe postorder traversal of tree is:\n\t");
      postorder(k);
    }
    printf("\n\t");
}