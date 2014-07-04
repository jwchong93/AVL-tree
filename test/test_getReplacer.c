#include "unity.h"
#include "manageAVL.h"
#include "CException.h"
#include "customAssert.h"

void setUp(void)
{
}

void tearDown(void)
{
}
/*
	180
      \
	  150
*/
void test_getReplacer_will_return_right_node_when_there_are_two_nodes()
{
	Node
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N150={.balance=1 ,.leftChild=NULL ,.rightChild=&N180,.data=150}
	;

	Node *testRoot=&N150;
	Node *testNode=NULL;
	testNode=getReplacer(&testRoot);
	TEST_ASSERT_EQUAL(&N180,testNode);
	TEST_ASSERT_EQUAL(0,testRoot->balance);
}

/*
	150
     \
	  150
	   \
	   185
	   remove 185
*/
void test_getReplacer_will_return_right_node_when_there_are_three_nodes()
{
	Node
	N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	N180={.balance=1 ,.leftChild=NULL ,.rightChild=&N185,.data=180},
	N150={.balance=2 ,.leftChild=NULL ,.rightChild=&N180,.data=150}
	;

	Node *testRoot=&N150;
	Node *testNode=NULL;
	//printf("Starting....\n");
	testNode=getReplacer(&testRoot);
	//printf("Ending....\n");
	TEST_ASSERT_EQUAL(&N185,testNode);
	TEST_ASSERT_EQUAL(1,testRoot->balance);
	TEST_ASSERT_EQUAL(0,testRoot->rightChild->balance);
}

void test_getReplacer_will_move_to_the_right_until_the_last_location()
{
	Node N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	N250={.balance=1 ,.leftChild=NULL ,.rightChild=&N300,.data=250},
	N200={.balance=2 ,.leftChild=NULL ,.rightChild=&N250,.data=200},
	N195={.balance=3 ,.leftChild=NULL ,.rightChild=&N200,.data=195},
	N190={.balance=4 ,.leftChild=NULL ,.rightChild=&N195,.data=190},
	N185={.balance=5 ,.leftChild=NULL ,.rightChild=&N190,.data=185},
	N180={.balance=6 ,.leftChild=NULL ,.rightChild=&N185,.data=180},
	N150={.balance=7 ,.leftChild=NULL ,.rightChild=&N180,.data=150}
		;
	Node *testRoot=&N150;
	Node *testNode=NULL;
	testNode=getReplacer(&testRoot);
	
	TEST_ASSERT_EQUAL(&N300,testNode);
	TEST_ASSERT_EQUAL(6,testRoot->balance);
	TEST_ASSERT_EQUAL(5,testRoot->rightChild->balance);
	TEST_ASSERT_EQUAL(4,testRoot->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(3,testRoot->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(2,testRoot->rightChild->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testRoot->rightChild->rightChild->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testRoot->rightChild->rightChild->rightChild->rightChild->rightChild->rightChild->balance);
}


void test_getReplacer_will_return_the_root_when_there_are_no_rightChild_or_leftChild()
{
	Node
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
	;

	Node *testRoot=&N150;
	Node *testNode=NULL;
	testNode=getReplacer(&testRoot);
	TEST_ASSERT_EQUAL(&N150,testNode);
}


void test_getReplacer_will_replace_the_root_with_leftChild_and_return_root_while_there_is_no_rightChild()
{
	Node
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N180={.balance=-1 ,.leftChild=&N150 ,.rightChild=NULL,.data=180}
	;

	Node *testRoot=&N180;
	Node *testNode=NULL;
	testNode=getReplacer(&testRoot);
	TEST_ASSERT_EQUAL(&N180,testNode);
    TEST_ASSERT_EQUAL(&N150,testRoot);
	TEST_ASSERT_EQUAL(0,testRoot->balance);
}

void test_getReplacer_will_return_the_last_rightChild_and_replace_the_rightChild_location_with_leftChild()
{
	Node
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N150={.balance=-1 ,.leftChild=&N180 ,.rightChild=NULL,.data=150},
	N120={.balance=2 ,.leftChild=NULL ,.rightChild=&N150,.data=120},
	N50={.balance=3 ,.leftChild=NULL,.rightChild=&N120,.data=50}
	;

	Node *testRoot=&N50;
	Node *testNode=NULL;
	testNode=getReplacer(&testRoot);
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N120,2,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N180,1,testRoot->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->rightChild);
	
}
