#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{   
    string vertex;
    int time;
    node *next;
};   
class adjmatlist
{    
    int m[10][10],n,i,j; 
    char ch;  
	 string v[20];   
	 node *head[20];  
	 node *temp=NULL;

     public:
	     adjmatlist()
	     {      for(i=0;i<20;i++)
	            {    
					head[i]=NULL; 
				}
	     }          
	     void getgraph();
	     void adjlist();
	     void display_matrix();
	     void display_list();
};
void adjmatlist::getgraph()
{
   cout<<"\n ENTER THE NUMBER OF CITIES :";
   cin>>n;
   cout<<"\n ENTER NAME OF CITIES :";
   for(i=0;i<n;i++)
     cin>>v[i];         
   for(i=0;i<n;i++)
   { 
      for(j=0;j<n;j++)
      {  
      cout<<"\n IS THEIR ANY PATH PRESENT BETWEEN CITY "<<v[i] <<" AND "<<v[j] <<" THEN ENTER y OTHERWISE ENTER n : "; 
         cin>>ch;
         if(ch=='y')
         { 
          cout<<"\n ENTER THE AMOUNT OF TIME REQUIRED TO REACH THE CITY "<<v[j] <<" FROM "<<v[i] <<" IN MINUTES :";
           
		   cin>>m[i][j];
         }
         else if(ch=='n')
         {  m[i][j]=0;  }
         else
         { cout<<"\n INVALID ENTRY";  }
      }
   }       
      adjlist();
        
}
void adjmatlist::adjlist()
{      cout<<"\n ********************************************************************************************************";
       for(i=0;i<n;i++)
       {  node *p=new(struct node);
          p->next=NULL;
          p->vertex=v[i];   
          head[i]=p;      
		  cout<<"\n"<<head[i]->vertex;
       }
     
       for(i=0;i<n;i++)
       {  for(j=0;j<n;j++)
          {
                   if(m[i][j]!=0)
                   {      
                         node *p=new(struct node);
                         p->vertex=v[j];
                         p->time=m[i][j];
                         p->next=NULL;
                         if(head[i]->next==NULL)
                         {  
						 head[i]->next=p;  
						 }
                         else
                         {  
						 temp=head[i];
                         while(temp->next!=NULL)
                         {  
						  temp=temp->next;  
						 }
                             temp->next=p;
                         }

                   }
          }
       }  
     
}
void adjmatlist::display_matrix()
{    
cout<<"\n\n\n";
     for(j=0;j<n;j++)
     {  
	 	cout<<"\t\t\t"<<v[j];  
	 }

     for(i=0;i<n;i++)
     {  
	 cout<<"\n\n\n"<<v[i];
        for(j=0;j<n;j++)
        {   
		cout<<"\t\t\t"<<m[i][j];
        }
            cout<<"\n\n\n";
     }
}   
void adjmatlist::display_list()
{     
       cout<<"\n ADJACENCY LIST IS : ";
     
       for(i=0;i<n;i++)
       { 
                         if(head[i]==NULL)
                         {   
							 cout<<"\n ADJACENCY LIST NOT PRESENT";  
							 break;   
						 }
                         else
                         { 
	                         cout<<"\n"<<head[i]->vertex;
	                         temp=head[i]->next;
	                         while(temp!=NULL)
	                         {  
							    cout<<"-> "<<temp->vertex;
	                            temp=temp->next;  
							 }
                            
                         }
         
       }

         cout<<"\n PATH AND TIME REQUIRED TO REACH CITIES IS :";
       
       for(i=0;i<n;i++)
       { 
                 
                         if(head[i]==NULL)
                         {   
							 cout<<"\n ADJACENCY LIST NOT PRESENT";    
							 break;   
						 }
                         else
                         { 
                           
                         temp=head[i]->next;
                         while(temp!=NULL)
                         {  
							cout<<"\n\n"<<head[i]->vertex;
	                        cout<<"-> "<<temp->vertex<<"\n   [TIME REQUIRED IS : "<<temp->time<<" MIN ]";
	                        temp=temp->next;  
						 }
                            
                         }    
       }
}
int main()
{  
   adjmatlist a;
   cout<<"\n 1.ENTER THE GRAPH";
    a.getgraph();
    cout<<"\n 2.DISPLAY ADJACENCY MATRIX FOR GIVEN CITIES : ";
    a.display_matrix();
   cout<<"\n 3.DISPLAY ADJACENCY LIST FOR GIVEN CITIES : ";
   a.display_list();
    return 0;
}                            
