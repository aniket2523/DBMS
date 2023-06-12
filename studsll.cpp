// Assignment No.1 - Based on SLL for Employee record //
#include <iostream>
using namespace std;
class emp
{
   int id;
   char *name;
   char *des;
   long int mn;
   float sal;
   emp *next;
   public:
   emp()  // Constructor
  {
    name=new char;  // Memory allocation
    des=new char;
   }

  void create();
  void display();
  void add_front();  //Insertion operation
  void add_last();
  void add_middle();
  void del_at_f();  //Deletion operation
  void del_l();
  void del_m();
}*start;
void emp::create()
{
   emp *temp;
   temp=new emp;
   cout<<"\n enter the id=";
   cin>>temp->id;
   cout<<"\n enter the empolye name=";
   cin>>temp->name;
   cout<<"\n enter the designation=";
   cin>>temp->des;
   cout<<"\n enter the mobile no=";
   cin>>temp->mn;
   cout<<"\n enter the salary=";
   cin>>temp->sal;
   temp->next=NULL;
   temp->next=start;
   start=temp;
}
void emp::display()
{
  int count=0;
  emp *temp;
  temp=start;
  if(temp==NULL)
  {
     cout<<"\n list is empty";
  }
  else
  {
    while(temp!=NULL)
    {
      cout<<"\n"<<temp->id;
      cout<<"\t"<<temp->name;
      cout<<"\t"<<temp->des;
      cout<<"\t"<<temp->mn;
      cout<<"\t"<<temp->sal;
      temp=temp->next;
      count++;
    }
    cout<<"\n";
    cout<<"\n number of records="<<count;
  }
}
void emp::add_front()   // Insertion at Front side
{
  emp *temp,*ptr;
  ptr=new emp;
   cout<<"\n enter the id=";
   cin>>ptr->id;
   cout<<"\n enter the empolye name=";
   cin>>ptr->name;
   cout<<"\n enter the designation=";
   cin>>ptr->des;
   cout<<"\n enter the mobile no=";
   cin>>ptr->mn;
   cout<<"\n enter the salary=";
   cin>>ptr->sal;
  if(temp==NULL)
  {
     temp=ptr;
  }
  else
  {
     temp=start;
     start=ptr;
     ptr->next=temp;
  }
}

void emp::add_last()   // Insertion at Last
{
  emp *temp,*newptr;
  newptr=new emp;
  cout<<"\n enter the id=";
   cin>>newptr->id;
   cout<<"\n enter the empolye name=";
   cin>>newptr->name;
   cout<<"\n enter the designation=";
   cin>>newptr->des;
   cout<<"\n enter the mobile no=";
   cin>>newptr->mn;
   cout<<"\n enter the salary=";
   cin>>newptr->sal;
  newptr->next=NULL;
  temp=start;
  if(temp==NULL)
  {
    temp=newptr;
  }
  else
  {
       while(temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=newptr;
  }
}
void emp::add_middle()   // Insertion at the Middle Side
{
  emp *temp,*ptr;
  ptr=new emp;
  int loc,i;
  temp=start;
  cout<<"\n enter at which location you want to enter the element=";
  cin>>loc;
  cout<<"\n enter the id=";
   cin>>ptr->id;
   cout<<"\n enter the empolye name=";
   cin>>ptr->name;
   cout<<"\n enter the designation=";
   cin>>ptr->des;
   cout<<"\n enter the mobile no=";
   cin>>ptr->mn;
   cout<<"\n enter the salary=";
   cin>>ptr->sal;
  if(temp==NULL)
  {
    temp=ptr;
  }
  else
  {
    for(i=1;i<loc;i++)
    {
      temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
  }

}
void emp::del_at_f()    // Deletion at Front side
{
   emp *temp;
   temp=start;
   if(temp==NULL)
   {
    cout<<"\n list is empty";
   }
   else
   {
     start=start->next;
     delete[] temp;
     cout<<"\n record is deleted";
   }
}
void emp::del_l()    // Deletion at Last sides
{
   emp *temp,*q;
   temp=start;
   if(temp==NULL)
   {
    cout<<"\n list is empty";
   }
   else
   {
     while(temp->next->next!=NULL)
     {
      temp=temp->next;
     }
      q=temp->next;
      temp->next=NULL;
      delete[]q;
      cout<<"\n record is deleted";
   }
}
void emp::del_m()   // Deletion at Middle side
{
  emp *temp,*p;
  int loc,i;
  temp=start;
  cout<<"\n enter at which location you want to enter the element=";
  cin>>loc;
  if(temp==NULL)
  {
    cout<<"\n list is empty";
  }
  else
  {
    for(i=1;i<loc;i++)
    {
      temp=temp->next;
    }
    p=temp->next;
    temp->next=p->next;
    delete[]p;
    cout<<"\n record is deleted";
  }

}

int main()
{
  emp n;
  int ch,i;
  start=NULL;
  do{
    cout<<"\n menu \n 1.create \n 2.display \n 3.add at front \n 4.add at middle \n 5.add at last \n 6.delete at front \n 7.delete at last \n 8.delete at middle \n .exit";
    cout<<"\n enter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:
      int add;
      do{
        n.create();
        cout<<"\n you want accept more data (yes=1/no=0)=";
        cin>>add;
      }while(add==1);
      break;
      case 2:
      n.display();
      break;
      case 3:
      n.add_front();
      break;
      case 4:
      n.add_middle();
      break;
      case 5:
      n.add_last();
      break;
      case 6:
      n.del_at_f();
      break;
      case 7:
      n.del_l();
      break;
      case 8:
      n.del_m();
      break;
    }
  }while(ch!=0);
  return 0;
}