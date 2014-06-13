#include "manageAVL.h"
#include <stdio.h>

Node* leftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild;
	elem->rightChild = tempNode->leftChild;
	tempNode->leftChild = elem;
	getBalance(tempNode);
	return tempNode;
}

Node* rightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild;
	elem->leftChild = tempNode->rightChild;
	tempNode->rightChild = elem;
	getBalance(tempNode);
	return tempNode;
}

Node* doubleRightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild->rightChild;
	Node *tempNode2= tempNode->leftChild;

	tempNode->leftChild = elem->leftChild;
	elem->leftChild = tempNode;
	tempNode->leftChild->rightChild=tempNode2;
	tempNode = rightRotate(elem);
	getBalance(tempNode);
	return tempNode;
}

Node* doubleLeftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild->leftChild;
	Node *tempNode2= tempNode->rightChild;

	tempNode->rightChild = elem->rightChild;
	elem->rightChild = tempNode;
	tempNode->rightChild->leftChild=tempNode2;
	tempNode = leftRotate(elem);
	getBalance(tempNode);
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
		else
		{
				root->leftChild = AVLAdd(root->leftChild,nodeToAdd);
		}
	}
	getBalance(root);
	return root;
}

Node * AVLBalance(Node *root)
{
	
}































