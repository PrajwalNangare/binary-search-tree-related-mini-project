#include<iostream>
using namespace std;
struct Node
{
	public:
	int data;
	struct Node* lchild;
	struct Node* rchild;
};
struct Node* root=NULL;
void create_binarysearchtree(int Key)
{
	struct Node* ptr=root;
	struct Node* tail=NULL;
	struct Node* temp=new Node;
	temp->data=Key;
	temp->lchild=temp->rchild=NULL;
	if(root==NULL)
	{
		root=temp;
		return;
	}
	else
	{
	   while(ptr!=NULL)
	   {
			tail=ptr;
			if(ptr->data<Key)
			{
				ptr=ptr->rchild;
			}
			else if(ptr->data>Key)
			{
				ptr=ptr->lchild;
			}
			else
			{
				return;
			}
	   }
    }
	if(tail->data<temp->data)
	{
		    tail->rchild=temp;
	}
	else
	{
		    tail->lchild=temp;
	}
	return;
}
void inorder(struct Node* ptr)
{
    if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<ptr->data<<" ";
		inorder(ptr->rchild);
	}
}
int CountTotalNodeInGivenBinarySearchTree(struct Node* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountTotalNodeInGivenTree(ptr->lchild);
		y=CountTotalNodeInGivenTree(ptr->rchild);
		return x+y+1;
	}
}
int CountNodeWhoseDegreeIsZero(struct Node* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsZero(ptr->lchild);
		y=CountNodeWhoseDegreeIsZero(ptr->rchild);
		if(ptr->lchild==NULL && ptr->rchild==NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
int CountNodeWhoseDegreeIsOne(struct Node* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsOne(ptr->lchild);
		y=CountNodeWhoseDegreeIsOne(ptr->rchild);
		if((ptr->lchild!=NULL && ptr->rchild==NULL)||(ptr->lchild==NULL && ptr->rchild!=NULL))
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
int CountNodeWhoseDegreeIsOneandTwo(struct Node* ptr)
{
    int x,y;

    if(ptr==NULL)
    {
        return 0;
    }
    
    else
    {
      x=CountNodeWhoseDegreeIsOneandTwo(ptr->lchild);
      y=CountNodeWhoseDegreeIsOneandTwo(ptr->rchild);

      if(ptr->lchild!=NULL || ptr->rchild!=NULL)
      {
          return x+y+1;
      }
      else
      {
          return x+y;
      }
    }
}
int CountNodeWhoseDegreeIsTwo(struct Node* ptr)
{
	int x,y;
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		x=CountNodeWhoseDegreeIsTwo(ptr->lchild);
		y=CountNodeWhoseDegreeIsTwo(ptr->rchild);
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
}
void preorder(struct Node *ptr)
{
	if(ptr!=NULL)
	{
	   cout<<ptr->data<<" ";
	   preorder(ptr->lchild);
	   preorder(ptr->rchild);
    }
}
void postorder(struct Node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		cout<<ptr->data<<" ";
	}
}
int main()
{
	while(true)
	{
	cout<<"*******Welcome to the binary search tree based project*******"<<endl;
	cout<<"Create  binary search tree"<<endl;
	cout<<"the inorder of the binary search tree is"<<endl;
	cout<<"count total node in given binary search tree is"<<endl;
	cout<<"count zero child node in given binary search tree is"<<endl;
	cout<<"count one child node in given binary search tree is"<<endl;
	cout<<"count two child node in given binary search tree is"<<endl;
	cout<<"count both one and two node in given binary search tree is"<<endl;
	cout<<"the preorder of the given binary search tree is:"<<endl;
	cout<<"the postorder of the given binary search tree is:"<<endl;
	cout<<"Exit"<<endl;
	cout<<"----------------------------"<<endl;
	int choice;
	cout<<"enter the choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
		   int n;
		   cout<<"Enter size of binary serach tree:";
		   cin>>n;
		   int Arr[n]={0};
		   cout<<"the elements of the binary search tree are:"<<endl;
		   for(int i=0;i<n;i++)
		   {
			  cin>>Arr[i];
		   }  
		   cout<<"the binary search tree is:"<<endl;
		   for(int i=0;i<n;i++)
		   {
			cout<<"Inserting to binary search tree:"<<Arr[i]<<endl;
			create_binarysearchtree(Arr[i]);
		   }
		   break;
	    }
		case 2:
		{
			cout<<"the inorder of given binary search tree is:";
			inorder(root);
			cout<<endl;
		}
		break;
		case 3:
		{
		        cout<<"the total node in given binary serach tree is:";
			cout<<CountTotalNodeInGivenBinarySearchTree(root);
			cout<<endl;	
		}
		break;
		case 4:
		{
			cout<<"the zero degree node in given binary search tree is:";
			cout<<CountNodeWhoseDegreeIsZero(root);
			cout<<endl;
		}
		break;
		case 5:
		{
			cout<<"the one degree node in given binary search tree is:";
			cout<<CountNodeWhoseDegreeIsOne(root);
			cout<<endl;
		}
		break;
		case 6:
		{
			cout<<"the two degree node in given binary search tree is:";
			cout<<CountNodeWhoseDegreeIsTwo(root);
			cout<<endl;
		}
		break;
		case 7:
		{
			cout<<"the one and two degree node is:";
			cout<<CountNodeWhoseDegreeIsOneandTwo(root);
			cout<<endl;
		}
		break;
		case 8:
		{
			cout<<"the preorder of the given binary search tree is:";
			preorder(root);
			cout<<endl;
		}
		break;
		case 9:
		{
			cout<<"the postorder of the given binary search tree is:";
			postorder(root);
			cout<<endl;
		}
		break;
		case 10:
		{
		       cout<<"invalid input:";	
		}
		break;
	}
    }
}
