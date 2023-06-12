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


/*===================================================================================
==============================================================================
=====================================================================*/

#include<iostream>
#include<string>
#define max 20
using namespace std;
class graph
{
	private:
		string data;
		graph *link,*down,*start;
		string city[10];
		int a[10][10];
		int n;
	public:
		void create_list();
		void display_list();
		void create_matrix();
		void display_matrix();
};

void graph::create_list()
{
	graph *temp,*node,*temp1,*node1;
	temp=new graph;
	temp1=new graph;
	node=new graph;
	node1=new graph;
	char ch,ch1;
	cout<<"\nEnter the parent node: ";
	cin>>node->data;
	node->down=NULL;
	node->link=NULL;
	start=node;
	temp=node1=start;
	temp1=node;
	do
	{
		node1=new graph;
		cout<<"\nEnter adjacent node for: "<<node->data<<"->";
		cin>>node1->data;
		node1->down=NULL;
		node1->link=NULL;
		temp1->link=node1;
		temp1=node1;
		cout<<"\nDo you want to insert more adjacent nodes?(Y/N): ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<"\nDo you want to enter more parent nodes?(Y/N): ";
	cin>>ch1;
	if(ch1=='y' || ch1=='Y')
	{
		do
		{
			node=new graph;
			cout<<"\nEnter the parent node: ";
			cin>>node->data;
			node->down=NULL;
			node->link=NULL;
			temp->down=node;
			temp=node;
			temp1=node;
			do
			{
				node1=new graph;
				cout<<"\nEnter adjacent node for "<<node->data<<"->";
				cin>>node1->data;
				node1->down=NULL;
				node1->link=NULL;
				temp1->link=node1;
				temp1=node1;
				cout<<"\nDo you want to insert more adjacent nodes?(Y/N): ";
				cin>>ch;
			}while(ch=='y' || ch=='Y');
			cout<<"\nDo you want to enter more parent nodes?(Y/N): ";
			cin>>ch1;
		}while(ch1=='y' || ch1=='Y');
	}
}

void graph::display_list()
{
	graph *temp,*temp1;
	temp=new graph;
	temp1=new graph;
	temp=start;
	cout<<"\nThe graph is: "<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp1=temp->link;
		while(temp1!=NULL)
		{
			cout<<"->"<<temp1->data;
			temp1=temp1->link;
		}

		temp=temp->down;
		if(temp!=NULL)
		{
			cout<<"\n";
		}
	}
}

void graph::create_matrix()
{
	cout<<"\nEnter number of cities: ";
	cin>>n;
	cout<<"\nEnter name of cities: ";
	for(int i=0;i<n;i++)
	{
		cin>>city[i];
	}
	cout<<"\nEnter the distances: ";
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
				continue;
			}
			cout<<"\nEnter the distance between "<<city[i]<<" and "<<city[j]<<": ";
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
}

void graph::display_matrix()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
	}
}

int main()
{
	int ch;
	graph g;
	do
	{
		cout<<"\nMenu:";
		cout<<"\n1.Create linked list \n2.Display linked list \n3.Create Matrix \n4.Display Matrix";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.create_list();
				break;
			case 2:
				g.display_list();
				break;
			case 3:
				g.create_matrix();
				break;
			case 4:
				g.display_matrix();
				break;
			default:
				cout<<"\nInvalid Choice!!";
		}
	}while(ch!=0);
	return 0;
}