#include<iostream>
using namespace std;

class bt
{
public:
 char data;
 bt *lchild,*rchild;
               void create();
               void insert(bt *root,bt *next);
               void inorder(bt *root);
               void preorder(bt *root);
               void postorder(bt *root);
}*root;



void bt::create()
{
 bt *next;
 int ch; 
 root=new bt;
 root->lchild=NULL;
 root->rchild=NULL;
 
         cout<<"\n   Enter the data for root node:-\n";
         cin>>root->data;

 do
 {
   cout<<"\n   Do you want to continue if yes than press 1:";
   cin>>ch;
 if(ch==1)
 { 
  next=new bt;
  next->lchild=NULL;
  next->rchild=NULL;
           
 cout<<"\nEnter new node data:";
 cin>>next->data;
 insert(root,next);
 }
  }while(ch==1);
 }
void bt::insert(bt *root,bt *next)
{
char chr;
 cout<<"\nThe data for root :"<<root->data<<"\n  where you want to enter at left or right (PRESS L OR R)\nS";
 cin>>chr;
 if(chr=='l'||chr=='L')
 {
  if(root->lchild==NULL)
  {
     root->lchild=next;
   }
   else
   {
     insert(root->lchild,next);
   }
 
 }
 else
 {
  if(root->rchild==NULL)
  {
     root->rchild=next;
   }
   else
   {
     insert(root->rchild,next);
   }
 
 
 
 }
 }
void bt::inorder(bt *root)
{

      if(root!=NULL)
{
      inorder(root->lchild);
      cout<<root->data<<"\t";
      inorder(root->rchild);

}
}
void bt::preorder(bt *root)
{

    if(root!=NULL)
{
      cout<<root->data<<"\t";
      inorder(root->lchild);
      inorder(root->rchild);

}


}
void bt::postorder(bt *root)
{

    if(root!=NULL)
{
      inorder(root->lchild);
      inorder(root->rchild);
      cout<<root->data<<"\t";

}
}
int main()
{
bt b;      //Creating object of the class bt
 int n,ch; 
do{
 cout<<"=================MENU==================="; 
 cout<<"\n1. CREATE";
 cout<<"\n2. IN-ORDER";
 cout<<"\n3. PRE-ORDER";
 cout<<"\n4. POST-ORDER";
 cout<<"\n5. TERMINATE THE CODE..................";
 cout<<"\n ENTER YOUR CHOICE\n ";
 cin>>ch;
switch(ch)
{
 case 1:
      b.create();
      break;
 case 2:
      b.inorder(root);
      break;
 case 3:
      b.preorder(root);
      break;
 case 4:
      b.postorder(root);
      break;
      
}
}while(ch!=5);
}
