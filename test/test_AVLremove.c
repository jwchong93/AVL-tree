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

void test_AVLRemove_will_remove_the_left_child_of_the_root()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N250);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N180);
	
	testNode2=AVLRemove(&testNode,&N180);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N180,testNode2);
	TEST_ASSERT_NULL(testNode->leftChild);
}

void test_AVLRemove_will_remove_the_right_child_of_the_root()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N250);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N180);
	
	testNode2=AVLRemove(&testNode,&N250);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N250,testNode2);
	TEST_ASSERT_NULL(testNode->rightChild);
}

void test_AVLRemove_will_balance_the_tree_after_remove()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
		;
		
	Node *testNode=NULL;
	Node *testRoot=NULL;
	testRoot=AVLAdd(testRoot,&N250);
	testRoot=AVLAdd(testRoot,&N200);
	testRoot=AVLAdd(testRoot,&N180);
	testRoot=AVLAdd(testRoot,&N190);
	testRoot=AVLAdd(testRoot,&N150);
	
	testNode=AVLRemove(&testRoot,&N250);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N250,testNode);
	TEST_ASSERT_EQUAL(&N180,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N200,1,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N190,NULL,-1,testRoot->rightChild);
}

void test_AVLRemove_will_balance_the_tree_after_remove_the_element_at_level_3()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		;
	Node *testNode=NULL;
	Node *testRoot=NULL;
	testRoot=AVLAdd(testRoot,&N250);
	testRoot=AVLAdd(testRoot,&N200);
	testRoot=AVLAdd(testRoot,&N180);
	testRoot=AVLAdd(testRoot,&N190);
	testRoot=AVLAdd(testRoot,&N150);
	testRoot=AVLAdd(testRoot,&N300);
	testRoot=AVLAdd(testRoot,&N185);
	testRoot=AVLAdd(testRoot,&N195);
	
	testNode=AVLRemove(&testRoot,&N300);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N300,testNode);
	TEST_ASSERT_EQUAL(&N190,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N180,&N200,0,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N185,0,testRoot->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N195,&N250,0,testRoot->rightChild);

}

void test_AVLRemove_will_replace_the_empty_space_of_N250_with_N300()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		;
	Node *testNode=NULL;
	Node *testRoot=NULL;
	testRoot=AVLAdd(testRoot,&N250);
	testRoot=AVLAdd(testRoot,&N200);
	testRoot=AVLAdd(testRoot,&N180);
	testRoot=AVLAdd(testRoot,&N190);
	testRoot=AVLAdd(testRoot,&N150);
	testRoot=AVLAdd(testRoot,&N300);
	testRoot=AVLAdd(testRoot,&N185);
	testRoot=AVLAdd(testRoot,&N195);
	
	testNode=AVLRemove(&testRoot,&N250);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N250,testNode);
	TEST_ASSERT_EQUAL(&N190,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N180,&N200,0,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N185,0,testRoot->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N195,&N300,0,testRoot->rightChild);

}

void test_AVLRemove_will_replace_the_empty_space_of_N250_with_N300_()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		;
	Node *testNode=NULL;
	Node *testRoot=NULL;
	testRoot=AVLAdd(testRoot,&N250);
	testRoot=AVLAdd(testRoot,&N200);
	testRoot=AVLAdd(testRoot,&N180);
	testRoot=AVLAdd(testRoot,&N190);
	testRoot=AVLAdd(testRoot,&N150);
	testRoot=AVLAdd(testRoot,&N300);
	testRoot=AVLAdd(testRoot,&N185);
	testRoot=AVLAdd(testRoot,&N195);
	
	testNode=AVLRemove(&testRoot,&N250);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N250,testNode);
	TEST_ASSERT_EQUAL(&N190,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N180,&N200,0,testRoot);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N185,0,testRoot->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N195,&N300,0,testRoot->rightChild);

}












