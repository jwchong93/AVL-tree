#ifndef manageAVL_H
#define manageAVL_H
typedef struct node 
{
	int rank;
	struct node*leftChild;
	struct node*rightChild;
	int data;
}Node;


int getHeight(Node *elem);
void getRank(Node *elem);
Node* rightRotate(Node *elem);
Node* leftRotate(Node *elem);
Node* doubleRightRotate(Node *elem);
Node* doubleLeftRotate(Node *elem);
#endif // manageAVL_H
