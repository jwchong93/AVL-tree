#ifndef manageAVL_H
#define manageAVL_H
typedef struct node 
{
	int balance;
	struct node*leftChild;
	struct node*rightChild;
	int data;
}Node;
typedef enum error {INVALID_INPUT}Error;

int getHeight(Node *elem);
void getBalance(Node *elem);
Node* rightRotate(Node *elem);
Node* leftRotate(Node *elem);
Node* doubleRightRotate(Node *elem);
Node* doubleLeftRotate(Node *elem);
Node * AVLBalance(Node *root);
Node * AVLAdd(Node *root,Node *nodeToAdd);
void AVLRemove();
#endif // manageAVL_H
