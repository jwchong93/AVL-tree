#include "manageAVL.h"
#include <stdio.h>
#include "CException.h"
Node* leftRotate(Node *elem)
{
	if(elem->balance==2&&elem->rightChild->balance==1)
	{
		elem->balance=0;
		elem->rightChild->balance=0;
	}
	else if(elem->balance==1&&elem->rightChild->balance==-1)
	{
		elem->balance-=1;
		elem->rightChild->balance-=1;
	}
	else if(elem->balance==1&&elem->rightChild->balance==1)
	{
		elem->balance-=2;
		elem->rightChild->balance-=2;
	}
	else if(elem->balance==2&&elem->rightChild->balance==2)
	{
		elem->balance-=3;
		elem->rightChild->balance-=2;
	}
	 else if(elem->balance==2&&elem->rightChild->balance==0)
	{
		elem->balance-=1;
		elem->rightChild->balance-=1;
	}
	Node *tempNode=elem->rightChild;
	elem->rightChild = tempNode->leftChild;
	tempNode->leftChild = elem;
	//getBalance(tempNode);
	return tempNode;
}

Node* rightRotate(Node *elem)
{

	if(elem->balance==-2&&elem->leftChild->balance==-1)
	{
		elem->balance=0;
		elem->leftChild->balance=0;
	}
	else if(elem->balance==-1&&elem->leftChild->balance==1)
	{
		elem->balance+=1;
		elem->leftChild->balance+=1;
	}
	else if(elem->balance==-1&&elem->leftChild->balance==-1)
	{
		elem->balance+=2;
		elem->leftChild->balance+=2;
	}
	else if(elem->balance==-2&&elem->leftChild->balance==-2)
	{
		elem->balance+=3;
		elem->leftChild->balance+=2;
	}
	else if(elem->balance==-2&&elem->leftChild->balance==0)
	{
		elem->balance+=1;
		elem->leftChild->balance+=1;
	}
	Node *tempNode=elem->leftChild;
	elem->leftChild = tempNode->rightChild;
	tempNode->rightChild = elem;
	//getBalance(tempNode);
	return tempNode;
}

Node* doubleRightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild->rightChild;
	Node *tempNode2= tempNode->leftChild;
	if(elem->leftChild->balance==1&&elem->leftChild->rightChild->balance==0)
	{
		elem->leftChild->balance-=1;
		elem->leftChild->rightChild->balance-=1;
	}
	else if(elem->leftChild->balance==1&&elem->leftChild->rightChild->balance==1)
	{
		elem->leftChild->balance-=2;
		elem->leftChild->rightChild->balance-=2;
	}
	else if(elem->leftChild->balance==1&&elem->leftChild->rightChild->balance==-1)
	{
		elem->leftChild->balance-=1;
		elem->leftChild->rightChild->balance-=1;
	}
	tempNode->leftChild = elem->leftChild;
	elem->leftChild = tempNode;
	tempNode->leftChild->rightChild=tempNode2;
	tempNode = rightRotate(elem);
	//getBalance(tempNode);
	return tempNode;
}

Node* doubleLeftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild->leftChild;
	Node *tempNode2= tempNode->rightChild;
	if(elem->rightChild->balance==-1&&elem->rightChild->leftChild->balance==0)
	{
		elem->rightChild->balance+=1;
		elem->rightChild->leftChild->balance+=1;
	}
	else if(elem->rightChild->balance==1&&elem->rightChild->leftChild->balance==1)
	{
		elem->rightChild->balance+=2;
		elem->rightChild->leftChild->balance+=2;
	}
	else if(elem->rightChild->balance==-1&&elem->rightChild->leftChild->balance==1)
	{
		elem->rightChild->balance+=1;
		elem->rightChild->leftChild->balance+=1;
	}
	tempNode->rightChild = elem->rightChild;
	elem->rightChild = tempNode;
	tempNode->rightChild->leftChild=tempNode2;
	tempNode = leftRotate(elem);
	//getBalance(tempNode);
	return tempNode;
}

int getHeight(Node *elem)
{
	int leftHeight=0,rightHeight=0;
	if(elem!=NULL)
	{
		leftHeight = getHeight(elem->leftChild);
		rightHeight = getHeight(elem->rightChild);
		if(leftHeight>=rightHeight)
		{
			return leftHeight+1;
		}
		else
		{
			return rightHeight+1;
		}
	}
	else
	{
		return 0;
	}
}

void getBalance(Node *elem)
{
	int leftHeight=0,rightHeight=0;
	if(elem!=NULL)
	{
		getBalance(elem->leftChild);
		getBalance(elem->rightChild);
		rightHeight = getHeight(elem->rightChild);
		leftHeight = getHeight(elem->leftChild);
		elem->balance = rightHeight-leftHeight;
	}
	
}

Node * AVLBalance(Node *root)
{
	if(root->balance==2&&(root->rightChild->balance==1||root->rightChild->balance==0))
	root = leftRotate(root);
	else if(root->balance==-2&&(root->leftChild->balance==-1||root->leftChild->balance==0))
	root = rightRotate(root);
	else if(root->balance==2&&root->rightChild->balance==-1)
	root = doubleLeftRotate(root);
	else if(root->balance==-2&&root->leftChild->balance==1)
	root = doubleRightRotate(root);
	
	
	//getBalance(root);
	return root;
}

Node *AVLAdd(Node *root,Node *nodeToAdd)
{
	int temp=0;
	if(root==NULL)
	{
		root = nodeToAdd;
	}
	else
	{
		if(root->data<nodeToAdd->data)
		{
				if(root->rightChild!=NULL)
				{
					temp = root->rightChild->balance;
					root->rightChild = AVLAdd(root->rightChild,nodeToAdd);
					if(temp!=root->rightChild->balance)
					{
						if(root->rightChild->balance==0)
						{
							root->balance=root->balance;
						}
						else
						{
							root->balance++;
						}
					}
				}
				else
				{
					root->rightChild = AVLAdd(root->rightChild,nodeToAdd);
					root->balance++;
				}
		}
		else if(root->data>nodeToAdd->data)
		{
			if(root->leftChild!=NULL)
			{
				temp=root->leftChild->balance;
				root->leftChild = AVLAdd(root->leftChild,nodeToAdd);
					if(temp!=root->leftChild->balance)
					{
						if(root->leftChild->balance==0)
						{
							root->balance=root->balance;
						}
						else
						{
							root->balance--;
						}
					}
			}
			else
			{
				root->leftChild = AVLAdd(root->leftChild,nodeToAdd);
				root->balance--;
			}
		}
		else
		{
			Throw(INVALID_INPUT);
		}
	}
	//getBalance(root);
	root = AVLBalance(root);
	return root;
}
Node * getReplacer(Node ** root)
{
	Node *tempNode=NULL;
	if((*root)->rightChild==NULL)
	{
		if((*root)->leftChild!=NULL)
		tempNode = (*root)->leftChild;
		(*root)->balance++;
		return tempNode;
	}
	if((*root)->rightChild->rightChild==NULL)
	{
		tempNode=(*root)->rightChild;
		if((*root)->rightChild->leftChild!=NULL)
		(*root)->rightChild=(*root)->rightChild->leftChild;
	}
	else
	{
		tempNode=getReplacer(&((*root)->rightChild));
	}
	if(tempNode!=NULL)
	{
		(*root)->balance--;
	}
	return tempNode;
}
Node* AVLRemove(Node **root,Node *nodeToRemove)
{
	Node *tempNode=NULL;
	Node *checkNode=NULL;
	if(nodeToRemove==(*root)->leftChild)
	{
		tempNode= (*root)->leftChild;
		(*root)->leftChild=NULL;
		(*root)->balance++;
		
	}
	else if(nodeToRemove==(*root)->rightChild)
	{
		tempNode = (*root)->rightChild;
		if((*root)->rightChild->leftChild!=NULL)
		{
			(*root)->rightChild=getReplacer(&((*root)->rightChild->leftChild));
			(*root)->rightChild->rightChild=tempNode->rightChild;
		}
		else if((*root)->rightChild->rightChild!=NULL)
		(*root)->rightChild=(*root)->rightChild->rightChild;
		else
		(*root)->rightChild=NULL;
		
		(*root)->balance--;
	}
	else if((*root)->leftChild!=NULL||(*root)->rightChild!=NULL)
	{
		if((*root)->rightChild!=NULL)
		{
			checkNode = AVLRemove(&((*root)->rightChild),nodeToRemove);
			if(checkNode == NULL && (*root)->leftChild!=NULL)
			{
				checkNode = AVLRemove(&((*root)->leftChild),nodeToRemove);
			}
			else
			{
				(*root)->balance--;
			}
		}
		else if((*root)->leftChild!=NULL)
		{
			checkNode = AVLRemove(&((*root)->leftChild),nodeToRemove);
			if(checkNode == NULL && (*root)->rightChild!=NULL)
			{
				checkNode = AVLRemove(&((*root)->rightChild),nodeToRemove);
			}
			else
			{
				(*root)->balance++;
			}
		}
		
	}
	// printf("What is this value?%d\n",(*root)->balance);
	(*root)=AVLBalance(*root);
	// printf("What is this value?%d\n",(*root)->balance);
	if(checkNode!=NULL)
	return checkNode;
	else
	return tempNode;
}





























