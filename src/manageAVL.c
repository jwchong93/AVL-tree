#include "manageAVL.h"
#include <stdio.h>

Node* leftRotate(Node *elem)
{
	Node *tempNode=elem->rightChild;
	elem->rightChild = tempNode->leftChild;
	tempNode->leftChild = elem;
	getRank(tempNode);
	return tempNode;
}

Node* rightRotate(Node *elem)
{
	Node *tempNode=elem->leftChild;
	elem->leftChild = tempNode->rightChild;
	tempNode->rightChild = elem;
	tempNode->rank++;
	getRank(tempNode);
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
	getRank(tempNode);
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
	getRank(tempNode);
	return tempNode;
	/*
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
	*/
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

void getRank(Node *elem)
{
	int leftHeight=0,rightHeight=0;
	if(elem!=NULL)
	{
		getRank(elem->leftChild);
		getRank(elem->rightChild);
		rightHeight = getHeight(elem->rightChild);
		leftHeight = getHeight(elem->leftChild);
		elem->rank = rightHeight-leftHeight;
	}
	
}