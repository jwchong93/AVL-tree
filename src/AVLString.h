#ifndef AVLString_H
#define AVLString_H
#include "manageAVL.h"
struct NodeString
{
	int balance;
	Node *leftChild;
	Node *rightChild;
	char* string;
};

int compareString(void *nodeInTree,void *nodeToCompare);

#endif // AVLString_H
