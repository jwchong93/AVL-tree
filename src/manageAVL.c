#include "manageAVL.h"
#include <stdio.h>
#include "CException.h"
//#include "AVLInt.h"

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
	else if(elem->rightChild->balance==-1&&elem->rightChild->leftChild->balance==1)
	{
		elem->rightChild->balance+=1;
		elem->rightChild->leftChild->balance+=1;
	}
	else if(elem->rightChild->balance==-1&&elem->rightChild->leftChild->balance==-1)
	{
		elem->rightChild->balance+=2;
		elem->rightChild->leftChild->balance+=2;
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
	{
		root = leftRotate(root);
	}
	else if(root->balance==-2&&(root->leftChild->balance==-1||root->leftChild->balance==0))
	{
		root = rightRotate(root);
	}
	else if(root->balance==2&&root->rightChild->balance==-1)
	{
		root = doubleLeftRotate(root);
	}
	else if(root->balance==-2&&root->leftChild->balance==1)
	{
		root = doubleRightRotate(root);
	}
	
	//getBalance(root);
	return root;
}

Node *avlAdd(Node *root,Node *nodeToAdd,int (*compare)(void*,void*))
{
	int temp=0;
	int compareResult;

	if(nodeToAdd==NULL)
	{
		return NULL;
	}
	if(root==NULL)
	{
		root = nodeToAdd;
	}
	else
	{
		compareResult = compare(root,nodeToAdd);
		if(compareResult==-1)
		{
				if(root->rightChild!=NULL)
				{
					temp = root->rightChild->balance;
					root->rightChild = avlAdd(root->rightChild,nodeToAdd,compare);
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
					else
					{
							if(root->rightChild->balance==0)
					        root->balance++;
					}
				}
				else
				{
					root->rightChild = avlAdd(root->rightChild,nodeToAdd,compare);
					root->balance++;
					
				}
		}
		else if(compareResult==1)
		{
			if(root->leftChild!=NULL)
			{
				temp=root->leftChild->balance;
				root->leftChild = avlAdd(root->leftChild,nodeToAdd,compare);
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
				root->leftChild = avlAdd(root->leftChild,nodeToAdd,compare);
				root->balance--;
			}
		}
		else if (compareResult==0)
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
	int temp;
	
	if((*root)->rightChild==NULL)
	{
		tempNode=(*root);
		if((*root)->leftChild!=NULL)
		(*root)=(*root)->leftChild;
		
		
	}
	else if((*root)->rightChild->rightChild==NULL)
	{	
		tempNode=(*root)->rightChild;
		if((*root)->rightChild->leftChild!=NULL)
		{
			(*root)->rightChild=(*root)->rightChild->leftChild;
			//printf("The removed node balance:%d\nThe root rightChild balance:%d\n",tempNode->balance,(*root)->rightChild->balance);
			//printf("The data \nRemoved data:%d\nThe root rightChild balance:%d\n",tempNode->data,(*root)->rightChild->data);
			(*root)->rightChild->balance=tempNode->balance+1;
			//printf("After\nThe removed node balance:%d\nThe root rightChild balance:%d\n",tempNode->balance,(*root)->rightChild->balance);
		}
		else
		{
			(*root)->rightChild=NULL;
		}

			(*root)->balance--; 
			
		if((*root)->rightChild!=NULL)
		{
			if((*root)->rightChild->leftChild!=NULL)
			{
				(*root)->balance+=2; 
			}
		}

	}
	else
	{
		temp = (*root)->balance;
		tempNode = getReplacer(&((*root)->rightChild));
		if(temp!=(*root)->rightChild->balance)
		{
			(*root)->balance--;

		}
	}
	
	/*
	if((*root)->rightChild==NULL)
	{
	        tempNode = (*root);
		if((*root)->leftChild!=NULL)
		{
		        (*root)=(*root)->leftChild;
		        (*root)->balance=tempNode->balance+1;
		}
		else
		{
			(*root)=NULL;
		}
		return tempNode;
	}
	else
	{
		tempNode=getReplacer(&((*root)->rightChild));
		
	}
	if(tempNode!=NULL)
	{
		(*root)->balance--;
	}
	*/
	return tempNode;
	
}
Node* AVLRemove(Node **root,Node *nodeToRemove)
{
	Node *tempNode=NULL;
	Node *tempNode2=NULL;
	Node *checkNode=NULL;
	int temp;
	if(nodeToRemove==(*root))
	{
		tempNode=(*root);
		if((*root)->leftChild!=NULL)
		{
			temp=(*root)->leftChild->balance;
			(*root)=getReplacer(&((*root)->leftChild));
			if((*root)!=tempNode->leftChild)
			(*root)->leftChild=tempNode->leftChild;
			(*root)->rightChild=tempNode->rightChild;
			(*root)->balance=tempNode->balance+1;
			
			

		}
		else if((*root)->rightChild!=NULL)
		{
			(*root)=getReplacer(&((*root)->rightChild));
			(*root)->leftChild=tempNode->leftChild;
			(*root)->rightChild=tempNode->rightChild;
			(*root)->balance=tempNode->balance-1;
		}
		else
		{
			(*root)=NULL;
		}
		
	}
	else if ((*root)->rightChild!=NULL&&nodeToRemove->data>(*root)->data)
	{
		checkNode = AVLRemove(&((*root)->rightChild),nodeToRemove);
		if(checkNode!=NULL)
		{
			if((*root)->rightChild!=NULL)
			{
				if((*root)->rightChild->balance==-1||(*root)->rightChild->balance==1)
				{
					
				}
				else
				{
					(*root)->balance--;
				}
			}
			else
			{
				(*root)->balance--;
			}
	
		}
				
	}
	else if ((*root)->leftChild!=NULL&&nodeToRemove->data<(*root)->data)
	{
		checkNode = AVLRemove(&((*root)->leftChild),nodeToRemove);
		if(checkNode!=NULL)
				{
					if((*root)->leftChild!=NULL)
					{
						if((*root)->leftChild->balance==-1||(*root)->leftChild->balance==1)
						{
						}
						else
						{
							(*root)->balance++;
						}
					}
					else
					{
						(*root)->balance++;
					}
				}
				
	}
	// else if(nodeToRemove==(*root)->leftChild)
	// {
		// tempNode= (*root)->leftChild;
		// (*root)->leftChild=NULL;
		// (*root)->balance++;
		
	// }
	// else if(nodeToRemove==(*root)->rightChild)
	// {
		// tempNode = (*root)->rightChild;
		// temp = (*root)->rightChild->balance;
		// if((*root)->rightChild->leftChild!=NULL)
		// {
			// (*root)->rightChild=getReplacer(&((*root)->rightChild->leftChild));
			// (*root)->rightChild->rightChild=tempNode->rightChild;
			// (*root)->rightChild->leftChild=tempNode->leftChild;
			// (*root)->rightChild->balance =tempNode->balance+1;
		// }
		// else if((*root)->rightChild->rightChild!=NULL)
		// (*root)->rightChild=(*root)->rightChild->rightChild;
		// else
		// (*root)->rightChild=NULL;
		
		// if((*root)->rightChild!=NULL)
		// {
			// if((*root)->rightChild->balance==1)
			// {
			// }
			// else
			// {
				// (*root)->balance--;
			// }
		// }
		// else 
		// {
			// (*root)->balance--;
		// }	
	// }
	// else if((*root)->leftChild!=NULL||(*root)->rightChild!=NULL)
	// {
		// if((*root)->rightChild!=NULL)
		// {
			// checkNode = AVLRemove(&((*root)->rightChild),nodeToRemove);
			// if(checkNode == NULL)
			// {
				// if((*root)->leftChild!=NULL)
				// checkNode = AVLRemove(&((*root)->leftChild),nodeToRemove);
				
				//#####################################################################################
				// if(checkNode!=NULL)
				// {
					// if((*root)->leftChild!=NULL)
					// {
						// if((*root)->leftChild->balance==-1||(*root)->leftChild->balance==1)
						// {
						// }
						// else
						// {
							// (*root)->balance++;
						// }
					// }
					// else
					// {
						// (*root)->balance++;
					// }
				// }
				//#####################################################################################
			// }
			// else
			// {
				 // if((*root)->rightChild!=NULL)
				 // {
					// if((*root)->rightChild->balance==-1||(*root)->rightChild->balance==1)
					// {
					// }
					// else
					// {
						// (*root)->balance--;
					// }
				// }
				// else
				// {
					// (*root)->balance--;
				// }
					//return checkNode;
			// }
		// }
		// else if((*root)->leftChild!=NULL)
		// {
			// checkNode = AVLRemove(&((*root)->leftChild),nodeToRemove);
			// if(checkNode == NULL)
			// {
				// if((*root)->rightChild!=NULL)
				// checkNode = AVLRemove(&((*root)->rightChild),nodeToRemove);
				//#####################################################################################
				// if(checkNode!=NULL)
				// {
					// if((*root)->rightChild!=NULL)
					 // {
						// if((*root)->rightChild->balance==-1||(*root)->rightChild->balance==1)
						// {
						// }
						// else
						// {
							// (*root)->balance--;
						// }
					// }
					// else
					// {
						// (*root)->balance--;
					// }
				// }
				//#####################################################################################
			// }
			// else
			// {
				// if((*root)->leftChild!=NULL)
				// {
					// if((*root)->leftChild->balance==-1||(*root)->leftChild->balance==1)
					// {
					// }
					// else
					// {
						// (*root)->balance++;
					// }
				// }
				// else
				// {
					// (*root)->balance++;
				// }
					//return checkNode;
			// }

		// }
		
	// }
	
	if((*root)!=NULL)
	(*root)=AVLBalance(*root);
	if(checkNode!=NULL)
	{
		return checkNode;
	}
	else
	{
		return tempNode;
	}
}



























