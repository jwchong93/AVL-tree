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
	if(elem->leftChild->balance==1&&elem->leftChild->rightChild->balance==1)
	{
		elem->leftChild->balance-=2;
		elem->leftChild->rightChild->balance-=2;
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
	if(elem->leftChild->balance==-1&&elem->leftChild->rightChild->balance==0)
	{
		elem->leftChild->balance+=1;
		elem->leftChild->rightChild->balance+=1;
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
	if(root->balance==2&&root->rightChild->balance==1)
	root = leftRotate(root);
	else if(root->balance==-2&&root->leftChild->balance==-1)
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
	if(root==NULL)
	{
		root = nodeToAdd;
	}
	else
	{
		if(root->data<nodeToAdd->data)
		{
				root->rightChild = AVLAdd(root->rightChild,nodeToAdd);
		}
		else if(root->data>nodeToAdd->data)
		{
				root->leftChild = AVLAdd(root->leftChild,nodeToAdd);
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






























