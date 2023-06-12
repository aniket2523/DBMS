#include <iostream>
using namespace std;
int top=-1;
class bt
{
   public:
   char data;
   bt *rchild,*lchild;
   
   void create();
   void insert(bt *root,bt *nex);
   void inorder(bt *root);
   void preorder(bt *root);
   void postorder(bt *root);   
}*root,*nex,*st[20];

void bt::create()
{
   root=new bt;
   root->rchild=NULL;
   root->lchild=NULL;
   cout<<"\n enter the data=";
   cin>>root->data;
   int ch;
   do
   {
     cout<<"\n do you want to insert more node(yes=1)=";
     cin>>ch;
     if(ch==1)
     {
       nex=new bt;
       nex->rchild=NULL;
       nex->lchild=NULL;
       cout<<"\n enter the new data=";
       cin>>nex->data;
       insert(root,nex);
     }
   }while(ch==1);
}

void bt::insert(bt *root,bt *nex)
{
  char ch2;
  cout<<"\n the root node of tree is="<<root->data;
  cout<<"\n do you want to insert node left(l) of right(r)=";
  cin>>ch2;
  if(ch2=='l')
  {
     if(root->lchild==NULL)
     {
        root->lchild=nex;
     }
     else
     {
       insert(root->lchild,nex);
     }
  }
  else if(ch2=='r')
  {
     if(root->rchild==NULL)
     {
        root->rchild=nex;
     }
     else
     {
       insert(root->rchild,nex);
     }
  }
}

void bt::inorder(bt *root)
{
   bt *temp;
   temp=root;
   if(temp!=NULL)
   {
     do{
       while(temp!=NULL)
      {
        
         top++;
         st[top]=temp;
         temp=temp->lchild;
       }
        if(top!=-1)
        {
         temp=st[top];
         cout<<"\t"<<temp->data;
         top--;
         temp=temp->rchild;
        }
  
   }while(top!=-1 || temp!=NULL);
   }
}

void bt::preorder(bt *root)
{
   bt *temp;
   temp=root;
   if(temp!=NULL)
   {
     do{
       while(temp!=NULL)
      {
        
         top++;
         st[top]=temp;
         cout<<"\t"<<temp->data;
         temp=temp->lchild;
       }
        if(top!=-1)
        {
         temp=st[top];
         top--;
         temp=temp->rchild;
        }
  
   }while(top!=-1 || temp!=NULL);
   }
}

void bt::postorder(bt *root)
{
   bt*temp;
   int i=0,top=-1;
   temp=root;
   char ar[30];
   if(root!=NULL)
   {
    do{
      while(temp!=NULL)
   {
      ar[i]=temp->data;
      i++;
      top++;
      st[top]=temp;
      temp=temp->rchild;
   }
    if(temp!=NULL)
    {
     temp=st[top];
     top--;
     temp=temp->lchild;
    }
   }while(top!=-1 || temp!=NULL);
   cout<<ar[i];
   }
   
   
   
}

int main()
{
  bt t;
  int ch3;
  do{
     cout<<"\n menu \n 1.create \n 2.display by inorder \n 3.display by preorder \n 4.display by postorder \n 5.exit";
     cout<<"\n enter your choice=";
     cin>>ch3;
     switch(ch3)
     {
       case 1:
       t.create();
       break;
       case 2:
       t.inorder(root);
       break;
       case 3:
       t.preorder(root);
       break;
       case 4:
       t.postorder(root);
       break;
     }
  }while(ch3!=5);
  
}