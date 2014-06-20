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

void test_getReplacer_will_move_to_the_right_until_the_last_location()
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
	Node *testRoot=NULL;
	
	
}