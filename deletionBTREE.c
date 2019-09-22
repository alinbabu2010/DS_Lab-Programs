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
  struct node *temp;
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
          temp=parent->lc;
          if(temp->data==item)
          {
             parent->lc=NULL;
             temp->data=0;
             temp->lc=NULL;
             temp->rc=NULL;
             free(temp);
          }
      }
      if(parent->rc!=NULL)
      {
         temp=parent->rc;
         if(temp->data==item)
         {
             parent->rc=NULL;
             temp->data=0;
             temp->lc=NULL;
             temp->rc=NULL;
             free(temp);
         }
      }
   }
  }
}