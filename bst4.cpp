#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};
void insert(Node *&root, Node *&next)
{

    char ch;
    cout << "The Root of  " << root->data << " \nWhere You Wnat TO insert (l 0r R)" << endl;
    cin >> ch;
    if (ch == 'L' || ch == 'l')
    {
        if (root->left == NULL)
        {
            root->left = next;
        }
        else
        {
            insert(root->left, next);
        }
    }
    if (ch == 'r' || ch == 'R')
    {
        if (root->right == NULL)
        {
            root->right = next;
        }
        else
        {
            insert(root->right, next);
        }
    }
}
void accept(Node *&root)
{
    char data;
    cout << "Enter the Root Data ->  ";
    cin >> data;
    int ch = 1;
    root->data = data;

    while (ch == 1)
    {
        cout << "DO YOU want To ADD More data (0 or 1 ) -> ";
        cin >> ch;
        if (ch == 1)
        {
            Node *next = new Node;
            cout << "Enter The data of new Child -> ";
            cin >> data;
            next->data = data;

            insert(root, next);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
        
            cout << endl;
            if (!q.empty())
            {
         
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int leafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftans = leafNode(root->left);
    int right = leafNode(root->right);
    int ans = leftans + right;
    return ans;
}

void MirrorImg(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        Node *temp;

        MirrorImg(root->left);
        MirrorImg(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int main()
{
    Node *n1 = new Node;
    accept(n1);
    int cnt = 0;
    cout << "The height of the Tree is -> " << height(n1);

    cout << endl
         << "the Number oF leafNode is -> " << leafNode(n1);

    int ch = 0;

    while (ch != 5)
    {
        cout << "\n\nMENU \n1)CREATE THE TREE \n2)COUT THE LEAF NODE \n3)HEIGHT OF THE TREEE \n4)MirrorImg OF THE TREE \n5)EXIT\n";
        cout << "\nEnter Your Choice ->  ";
        cin >> ch;
        if (ch == 1)
        {
            accept(n1);
        }
        if (ch == 2)
        {
            cout << endl
                 << "the Number oF leafNode is -> " << leafNode(n1);
            cout << endl;
        }
        if (ch == 3)
        {   int ans=height(n1);
            cout << "The height of the Tree is -> "<<ans;
        }
        if (ch == 4)
        {
            cout << "\nBEFORE MIRROR MIRRORING \n";
            levelOrderTraversal(n1);
            MirrorImg(n1);
            cout << "\n AFTER MIRROR MIRRORING \n";
            levelOrderTraversal(n1);
            cout << endl;
        }
        if (ch == 5)
        {
            cout << endl;
        }
    }

    return 0;
  
}


==========

#include<iostream>
#include<stack>
using namespace std;
struct node
{
 int data;
 node* left;
 node* right;
};

node* create_node(int data)
{
  node* temp=new node();
  temp->data =data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

void insert(node* root,int data)
{

  if(data<=root->data)
  {
    if(root->left==NULL)
    {
      root->left=create_node(data);
      
    }
    else
    {
      insert(root->left,data);
    }
  }
  else
  {
    if(root->right==NULL)
    {
      root->right=create_node(data);
    }
    else
    {
     insert(root->right,data);
    }
  }
  
  
}

void postorder(node* root)
{
  node*curr=root;
  stack<node*>s1,s2;
  s1.push(curr);
  while(!s1.empty())
  {
    curr=s1.top();
    s1.pop();
    s2.push(curr);
    if(curr->left!=NULL)
      s1.push(curr->left);
    if(curr->right!=NULL)
     s2.push(curr->right);  
  }
  while(!s2.empty())
  {
    curr=s2.top();
    cout<<curr->data<<" ";
    s2.pop();
  }
}

void preorder(node* root)
{
 node* curr;
 if(root==NULL)
    return;
 stack<node*> s;
 s.push(root);
 while(!s.empty())
 {
   curr=s.top();
   cout<<curr->data<<" ";
   s.pop();
   
   if(curr->right!=NULL)
     s.push(curr->right);
   if(curr->left!=NULL)
     s.push(curr->left);  
 }
 cout<<endl;
}
void inorder(node* root)
{
  node* curr=root;
  if(root==NULL)
    return;
    stack<node*> s;
    while(curr!=NULL || !s.empty())
    {
      while(curr!=NULL)
      {
      
       s.push(curr);
       curr=curr->left;
      
      }
      curr=s.top();
      s.pop();
      cout<<curr->data<<" ";
      curr=curr->right;
    }
    
}
//MIRROR IMAGE OF  BST TREE
node* mirrorimage(node* root)
{
  if(root==NULL)
    return root;
    
  node* left=mirrorimage(root->left);
  node* right=mirrorimage(root->right);
  root->left=right;
  root->right=left;  
  return root;
}

//HEIGHT OF TREE
int height(node* root)
{
  if(!root)
    return -1;
   int lheight=height(root->left);
   int rheight=height(root->right);
   return max(lheight,rheight)+1; 
}

//TOTAL NO OF LEAF NODES IN TREE
int get_leaf(node* root){
 if(root==NULL)
   return 0;
 if(root->left==NULL && root->right==NULL)
  return 1;
 return get_leaf(root->left)+get_leaf(root->right);  
 } 
int main()
{
 node* root=NULL;
 int n,data;
 cout<<"Enter n. of elements do you want to insert :";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cout<<"Enter element "<<i+1<<":";
  cin>>data;
  if(root==NULL)
  {
    root=create_node(data);
    
  }
  else
  insert(root,data);
 }
 cout<<"\nThe preorder traversal of tree is :";
 preorder(root);
 cout<<"\nThe inorder traversal of tree is :";
 inorder(root);
 cout<<"\nPostorder traversal is ";
 postorder(root);
 cout<<"\nHieght of Tree is"<<height(root); 
 cout<<"Total no. of leaf nodes are :"<<get_leaf(root);
 cout<<"\nMirror image is :";
 root=mirrorimage(root);
 preorder(root);
 
  return 0;
}





