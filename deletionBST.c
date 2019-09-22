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