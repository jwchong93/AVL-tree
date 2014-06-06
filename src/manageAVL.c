#include "manageAVL.h"
#include <stdio.h>

Node* leftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild;
	elem->rightChild = tempNode->leftChild;
	tempNode->leftChild = elem;
	tempNode->rank = getRank(tempNode);
	tempNode->rightChild->rank= getRank(tempNode->rightChild);
	tempNode->leftChild->rank= getRank(tempNode->leftChild);
	return tempNode;
}

Node* rightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild;
	elem->leftChild = tempNode->rightChild;
	tempNode->rightChild = elem;
	tempNode->rank++;
	tempNode->rank = getRank(tempNode);
	tempNode->rightChild->rank= getRank(tempNode->rightChild);
	tempNode->leftChild->rank= getRank(tempNode->leftChild);
	return tempNode;
}

Node* doubleRightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild->rightChild;
	if(tempNode->rightChild==NULL)
	tempNode->rightChild=tempNode->leftChild;
	tempNode->leftChild = elem->leftChild;
	elem->leftChild = tempNode;
	tempNode->rank--;
	tempNode->leftChild->rank--;
	tempNode->leftChild->rightChild=NULL;
	tempNode = rightRotate(elem);
	if(tempNode->rank!=0)
	{
		tempNode->rank--;
	}
	return tempNode;
}

Node* doubleLeftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild->leftChild;
	tempNode->rightChild = elem->rightChild;
	elem->rightChild = tempNode;
	tempNode->rank++;
	tempNode->rightChild->rank++;
	tempNode->rightChild->leftChild=NULL;
	tempNode = leftRotate(elem);
	if(tempNode->rank!=0)
	{
		tempNode->rank++;
	}
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

int getRank(Node *elem)
{
	int leftHeight=0,rightHeight=0;
	rightHeight = getHeight(elem->rightChild);
	leftHeight = getHeight(elem->leftChild);
	return rightHeight-leftHeight;
}