#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *lc;
  int data;
  struct node *rc;
};
struct node *root,*rcptr,*lcptr,*new,*parent,*ptr,*ptr1,*ptr0,*ptr2;
int item,key,top,top1,flag;
void creation(struct node*,int);
void insertion(int,int);
void deletion(int);
void display(struct node*);
struct node* stack[100];
int main(int argc,char **argv)
{
  int choice,k=0;
  root=malloc(sizeof(struct node));
  root->lc=NULL;
  root->rc=NULL;
  while(k==0)
  {
    printf("\n\t1.Creation\n\t2.Insertion\n\t3.Deletion\n\t4.Display");
    printf("\n\tPress another key to exit\n\tEnter your choice\n\t");
    scanf("%d",&choice);
    switch(choice)
    {
       case  1: printf("\n\tEnter the item to be inserted at root node\n\t");
                scanf("%d",&item);
                creation(root,item);
                ptr1=root;
                ptr0=root;
                break;
       case  2: if(ptr1!=NULL)
                {
                  printf("\n\tEnter the key node after which new node to be inserted\n\t");
                  scanf("%d",&key);
                  printf("\n\tEnter the item to be inserted\n\t");
                  scanf("%d",&item);
                  insertion(key,item);
                }
                else
                  printf("\n\tCreate tree first then press this option");
                break;
       case  3: if(ptr1!=NULL)
                {
                  printf("\n\tEnter the item to be deleted\n\t");
                  scanf("%d",&item);
                  deletion(item);
                }
                else
                                    printf("\n\tNo tree created\n\t");
                break;
       case  4: display(ptr1);
                break;
       default: exit(0);
    }
  }
  return 0;
}
void creation(struct node* ptr,int item)
{
   int option,newl;
   if(ptr!=NULL)
   {
     ptr->data=item;
     printf("\n\tWhether the node %d has left subtree if yes press 1 else press 2\n\t",item);
     scanf("%d",&option);
     if(option==1)
     {
       lcptr=malloc(sizeof(struct node));
       ptr->lc=lcptr;
       printf("\n\tEnter the item to be inserted\n\t");
       scanf("%d",&newl);
       creation(lcptr,newl);
     }
     else
       ptr->lc=NULL;
     printf("\n\tWhether the node %d has right subtree if yes press 1 else press 2\n\t",item);
     scanf("%d",&option);
     if(option==1)
     {
       rcptr=malloc(sizeof(struct node));
       ptr->rc=rcptr;
       printf("\n\tEnter the item to be inserted\n\t");
       scanf("%d",&newl);
       creation(rcptr,newl);
     }
     else
       ptr->rc=NULL;
   }
}
void push(struct node* ptr)
{
     top=top+1;
     stack[top]=ptr;
}
struct node * pop()
{
  if(top!=-1)
  {
    ptr=stack[top];
    top=top-1;
    return ptr;
  }
}
struct node* search_link(struct node* ptr,int key)
{
  struct node *ptr3,*ptr4;
  push(ptr);
  while(top!=-1)
    {
     ptr=pop();
     if(ptr!=NULL)
     {
       ptr3=ptr->lc;
       ptr4=ptr->rc;
       if(ptr->data==key)
        ptr2=ptr;
       if(ptr3!=NULL)
        push(ptr4);
       if(ptr!=NULL)
        push(ptr3);
     }
  }
  if(ptr2->data!=key)
    return NULL;
  else
    return ptr2;
}
void insertion(int key,int item)
{
  int option;
  ptr=search_link(ptr0,key);
  if(ptr==NULL)
    printf("\n\tSearch unsucessful: No insertion\n\t");
  else
  {
    if(ptr->lc==NULL||ptr->rc==NULL)
    {
      printf("\n\tPress 1 for inserting as left subtree else press 2 for inserting as right subtree\n\t");
      scanf("%d",&option);
      if(option==1)
      {
         if(ptr->lc==NULL)
         {
           new=malloc(sizeof(struct node));
           new->data=item;
           new->lc=new->rc=NULL;
           ptr->lc=new;
         }
         else
           printf("\n\tInsertion not possible as left child\n\t");
      }
      else
      {
         if(ptr->rc==NULL)
         {
           new=malloc(sizeof(struct node));
           new->data=item;
           new->lc=new->rc=NULL;
           ptr->rc=new;
         }
         else
           printf("\n\tInsertion not possible as right child\n\t");
      }
    }
    else
      printf("\n\tThe key node already has child\n\t");
  }
}
void inorder(struct node* ptr1)
{
  if (ptr1!= NULL)
  {
      inorder(ptr1->lc);
      printf("%d\t", ptr1->data);
      inorder(ptr1->rc);
  }
}
void preorder(struct node* ptr1)
{
  if (ptr1!= NULL)
  {
      printf("%d\t", ptr1->data);
      preorder(ptr1->lc);
      preorder(ptr1->rc);
  }
}
void postorder(struct node* ptr1)
{
  if (ptr1!=NULL)
  {
      postorder(ptr1->lc);
      postorder(ptr1->rc);
      printf("%d\t", ptr1->data);
  }
}
void display(struct node* ptr1)
{
    if(ptr1==NULL)
       printf("\n\tNo tree to display\n\t");
    else
    {
      printf("\n\tThe inorder traversal of tree is:\n\t");
      inorder(ptr1);
      printf("\n\tThe preorder traversal of tree is:\n\t");
      preorder(ptr1);
      printf("\n\tThe postorder traversal of tree is:\n\t");
      postorder(ptr1);
    }
    printf("\n\t");
}
struct node* search_parent(struct node* ptr,int item)
{
  struct node *ptr3,*ptr4;
  top=-1;
  flag=0;
  push(ptr);
  while(ptr->data!=item)
  {
     ptr=pop();
     if(ptr!=NULL)
     {
        ptr3=ptr->lc;
        ptr4=ptr->rc;
        if(ptr->data==item)
        {
          flag=1;
          break;
        }
        if(ptr3!=NULL)
        {
          parent=ptr;
          push(ptr3);
        }
        if(ptr4!=NULL)
        {
          parent=ptr;
          push(ptr4);
        }
     }
  }
  if(flag==0)
    return NULL;
  else
    return parent;
}
void deletion(int item)
{
  struct node *c;
  ptr=root;
  if(ptr==NULL)
    printf("\n\tTree is empty\n\t");
  else
  {
    if(ptr->rc==NULL&&ptr->lc==NULL)
    {
       root->data=0;
       ptr0=ptr1=NULL;
       return;
    }
    parent=search_parent(ptr,item);
    printf("\n\tParent:%d\n\t",parent->data);
    if(parent==NULL)
      printf("\n\tParent node not found\n");
    else
    {
      if(parent->lc!=NULL)
      {
          c=parent->lc;
          if(c->data==item)
          {
             parent->lc=NULL;
             c->data=0;
             c->lc=NULL;
             c->rc=NULL;
             free(c);
          }
      }
      if(parent->rc!=NULL)
      {
         c=parent->rc;
         if(c->data==item)
         {
             parent->rc=NULL;
             c->data=0;
             c->lc=NULL;
             c->rc=NULL;
             free(c);
         }
      }
   }
  }
}  