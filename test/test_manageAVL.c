#include "unity.h"
#include "manageAVL.h"
#include "CException.h"
#include "customAssert.h"
#include "AVLInt.h"
void setUp(void)
{
}

void tearDown(void)
{
}
/*
*      (1)             (2)
*        \            /   \
*        (2)    =>  (1)   (3)
*          \
*          (3)
*
*
*/

void test_leftRotate_will_work_as_the_figure_show_above()
{
	Node N3={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=3},
		N2={.balance=1 ,.leftChild=NULL ,.rightChild=&N3,.data=2},	
		N1={.balance=2 ,.leftChild=NULL ,.rightChild=&N2,.data=1};
	Node *testNode;
	
	testNode =leftRotate(&N1);
	TEST_ASSERT_EQUAL(&N2,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N3,testNode->rightChild);

	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
		
}


/*
*      (10)           (30)
*     /   \             /   
*   (5)   (30)    =>  (10)
*         /           /  \
*       (40)	     (5) (40)
*
*
*/

void test_leftRotate_will_work_if_there_are_four_elements()
{
	Node N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N30={.balance=-1 ,.leftChild=&N40 ,.rightChild=NULL,.data=30},	
		N5={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=5},	
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10};
	Node *testNode;
	
	testNode =leftRotate(&N10);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N40,testNode->leftChild->rightChild);
	
	TEST_ASSERT_EQUAL(-2,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild);
		
}

/*
*      (10)             (30)
*     /   \             /   \
*   (5)   (30)    =>  (10)   (40)
*   /     /   \        / \     /
*  (1)   (20) (40)	 (5) (20) (35)
*             /       /
*          (35)      (1)
*/
void test_leftRotate_will_work_if_there_are_special_case()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},	
		N20={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=20},
		N35={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=35},
		N40={.balance=-1 ,.leftChild=&N35 ,.rightChild=NULL,.data=40},
		N30={.balance=1 ,.leftChild=&N20 ,.rightChild=&N40,.data=30},
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10};
	Node *testNode;
	
	testNode =leftRotate(&N10);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N35,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(-1,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->rightChild);
		
}

/*
*      (10)             (30)
*     /   \             /   \
*   (5)   (30)    =>  (10)   (40)
*   /     /   \        / \    
*  (1)   (20) (40)	 (5) (20)
*           \         /    \
*          (35)      (1)   (35)
*/
void test_leftRotate_will_work_if_there_are_special_case_for_3_levels()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},	
		N35={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=35},
		N20={.balance=1 ,.leftChild=NULL ,.rightChild=&N35,.data=20},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N30={.balance=-1 ,.leftChild=&N20 ,.rightChild=&N40,.data=30},
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10};
	Node *testNode;
	
	testNode =leftRotate(&N10);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N35,testNode->leftChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild);
	
	TEST_ASSERT_EQUAL(-2,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->rightChild->balance);

	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
		
}

/*
*        (50)                    (100)
*        /  \                     / \
*      (10) (100)              (50) (150)
*            / \         =>    /  \    \
*          (70)(150)         (10) (70) (200) 
*                \
*               (200)
*/
void test_leftRotate_will_work_as_the_figure_show_above_with_larger_level()
{
	Node N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N150={.balance=1 ,.leftChild=NULL ,.rightChild=&N200,.data=150},	
		N70={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=70},	
		N100={.balance=1 ,.leftChild=&N70 ,.rightChild=&N150,.data=100},
		N10={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=10},
		N50={.balance=2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50};
	Node *testNode;
	
	testNode =leftRotate(&N50);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N70,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
}

/*
*      (3)           (2)
*      /            /   \
*    (2)    =>    (1)   (3)
*    /
*  (1)
*
*
*/
void test_rightRotate_will_work_as_the_figure_show_above()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N2={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=2},	
		N3={.balance=-2 ,.leftChild=&N2 ,.rightChild=NULL,.data=3};
	Node *testNode;
	
	testNode =rightRotate(&N3);
	TEST_ASSERT_EQUAL(&N2,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N3,testNode->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
		
}
/*
*        (50)                    (10)
*        /  \                     / \
*      (10) (100)              (5) (50)
*       / \         =>         /    /  \
*    (5)(30)                 (1) (30) (100) 
*    /
*  (1)
*/
void test_rightRotate_will_work_as_the_figure_show_above_with_larger_level()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},	
		N30={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=30},	
		N10={.balance=-1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=10};
	Node *testNode;
	
	testNode =rightRotate(&N50);
	TEST_ASSERT_EQUAL(&N10,testNode);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N30,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild);
}

/*
*      (2)           (3)
*      /            /   \
*    (1)    =>    (1)   (2)
*      \
*      (3)
*
*
*/
void test_doubleRightRotate_will_work_as_the_figure_show_above()
{
	Node N3={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=3},
		N1={.balance=1 ,.leftChild=NULL ,.rightChild=&N3,.data=1},	
		N2={.balance=-2 ,.leftChild=&N1 ,.rightChild=NULL,.data=2};
	Node *testNode;
	
	testNode =doubleRightRotate(&N2);
	TEST_ASSERT_EQUAL(&N3,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N2,testNode->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
		
}

/*
*        (50)                      (30)
*        /  \                      / \
*      (10) (100)                (10) (50)
*       / \         =>           /    /  \
*     (5) (30)                 (5) (40) (100) 
*           \
*          (40)
*/
void test_doubleRightRotate_will_work_as_the_figure_show_above_with_deeper_level()
{
	Node N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N30={.balance=1 ,.leftChild=NULL ,.rightChild=&N40,.data=30},	
		N5={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=5},
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50}
		;
	Node *testNode;
	
	testNode =doubleRightRotate(&N50);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild);
		
}

/*
*        (50)                      (30)
*        /  \                      / \
*      (10) (100)                (10) (50)
*       / \         =>           /  \    \
*     (5) (30)                 (5) (20) (100) 
*          /
*        (20)
*/
void test_doubleRightRotate_will_rotate_the_about_tree()
{
	Node N20={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N30={.balance=1 ,.leftChild=&N20 ,.rightChild=NULL,.data=30},	
		N5={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=5},
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50}
		;
	Node *testNode;
	
	testNode =doubleRightRotate(&N50);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild);
		
}

/*
*        (50)                        (30)
*        /  \                      /     \
*      (10) (100)                (10)   (50)
*       / \    \       =>         / \   /  \
*     (5) (30) (150)            (5)(20)(40) (100) 
*     /    / \                  /       /      \
*    (1) (20)(40)             (1)     (35)  (150)
*             /
*           (35)
*/

void test_doubleRightRotate_will_rotate_the_tree_with_wheight_of_5()
{
	Node N35={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=35},
		N40={.balance=-1 ,.leftChild=&N35 ,.rightChild=NULL,.data=40},	
		N20={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=20},	
		N30={.balance=1 ,.leftChild=&N20 ,.rightChild=&N40,.data=30},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},		
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N100={.balance=1 ,.leftChild=NULL ,.rightChild=&N150,.data=100},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50}
		;
	Node *testNode;
	
	testNode =doubleRightRotate(&N50);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N35,testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild->rightChild);

	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	
}

/*
*        (50)                        (30)
*        /  \                      /     \
*      (10) (100)                (10)   (50)
*       / \    \       =>         / \   /  \
*     (5) (30) (150)            (5)(20)(40) (100) 
*     /    / \                  /     \      \
*    (1) (20)(40)             (1)     (25)  (150)
*           \
*           (25)
*/

void test_doubleRightRotate_will_rotate_the_tree_with_height_of_5()
{
	Node N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N20={.balance=1 ,.leftChild=NULL ,.rightChild=&N25,.data=20},	
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},	
		N30={.balance=-1 ,.leftChild=&N20 ,.rightChild=&N40,.data=30},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},		
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N100={.balance=1 ,.leftChild=NULL ,.rightChild=&N150,.data=100},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50}
		;
	Node *testNode;
	
	testNode =doubleRightRotate(&N50);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N25,testNode->leftChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild->rightChild);

	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild->rightChild->rightChild);
	
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	
}


/*
*      (2)               (1)
*        \              /   \
*        (3)    =>    (2)   (3)
*        /
*      (1)
*
*
*/
void test_doubleLeftRotate_will_work_as_the_figure_show_above()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N3={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=3},	
		N2={.balance=2 ,.leftChild=NULL ,.rightChild=&N3,.data=2};
	Node *testNode;
	
	testNode =doubleLeftRotate(&N2);
	TEST_ASSERT_EQUAL(&N1,testNode);
	TEST_ASSERT_EQUAL(&N2,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N3,testNode->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	TEST_ASSERT_NULL(testNode->leftChild->leftChild);
	TEST_ASSERT_NULL(testNode->leftChild->rightChild);
	TEST_ASSERT_NULL(testNode->rightChild->leftChild);
	TEST_ASSERT_NULL(testNode->rightChild->rightChild);
		
}

/*
*     (2)
*    /   \
*  (1)   (3)
*
*
*/
void test_getHeight_will_return_the_maximun_height_of_the_AVL_tree()
{
	Node N3={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=3},
	N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N2={.balance=0 ,.leftChild=&N1 ,.rightChild=&N3,.data=2};
	int testHeight;
	
	testHeight = getHeight(&N2);
	TEST_ASSERT_EQUAL(2,testHeight);
}

/*
*     (2)
*    /   \
*  (1)   (3)
*  /
*(0)
*
*/
void test_getHeight_will_return_the_maximun_height_of_the_AVL_tree_for_three_level()
{
	Node N3={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=3},
	N0={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N1={.balance=0 ,.leftChild=&N0 ,.rightChild=NULL,.data=1},
	N2={.balance=0 ,.leftChild=&N1 ,.rightChild=&N3,.data=2};
	int testHeight;
	
	testHeight = getHeight(&N2);
	TEST_ASSERT_EQUAL(3,testHeight);
}

/*
*          (10)
*         /   \
*       (9)   (15)
*       /       \
*     (5)       (20)
*
*/
void test_getHeight_will_return_the_maximun_height_of_the_AVL_tree_for_three_level_two_leaves()
{
	Node N5={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=5},
	N20={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=20},
	N9={.balance=0 ,.leftChild=&N5 ,.rightChild=NULL,.data=9},
	N15={.balance=0 ,.leftChild=NULL ,.rightChild=&N20,.data=15},
	N10={.balance=0 ,.leftChild=&N9 ,.rightChild=&N15,.data=10};
	int testHeight;
	
	testHeight = getHeight(&N10);
	TEST_ASSERT_EQUAL(3,testHeight);
}


/*
*      (1)             (2)
*        \            /   \
*        (2)    =>  (1)   (3)
*          \
*          (3)
*
*
*/

void test_AVLBalance_will_will_rotate_the_tree_to_form_a_nearly_balanced_tree_with_three_element()
{
	Node N3={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=3},
	N2={.balance=1 ,.leftChild=NULL ,.rightChild=&N3,.data=2},	
	N1={.balance=2 ,.leftChild=NULL ,.rightChild=&N2,.data=1};
	Node *testNode;
	testNode = AVLBalance(&N1);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N2,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N3,testNode->rightChild);
}

/*
*        (50)                    (100)
*        /  \                     / \
*      (10) (100)              (50) (150)
*            / \         =>    /  \    \
*          (70)(150)         (10) (70) (200) 
*                \
*               (200)
*/

void test_AVLBalance_will_will_rotate_the_tree_to_form_a_nearly_balanced_tree_with_6_elements()
{
	Node N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N150={.balance=1 ,.leftChild=NULL ,.rightChild=&N200,.data=150},	
		N70={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=70},	
		N100={.balance=1 ,.leftChild=&N70 ,.rightChild=&N150,.data=100},
		N10={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=10},
		N50={.balance=2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50};
	Node *testNode;
	
	testNode = AVLBalance(&N50);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N70,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	
}

/*
*        (50)                        (30)
*        /  \                      /     \
*      (10) (100)                (10)   (50)
*       / \    \       =>         / \   /  \
*     (5) (30) (150)            (5)(20)(40) (100) 
*     /    / \                  /       /      \
*    (1) (20)(40)             (1)     (35)  (150)
*             /
*           (35)
*/

void test_AVLBalance_will_rotate_the_tree_to_form_a_nearly_balanced_tree_with_11_elements()
{
	Node N35={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=35},
		N40={.balance=-1 ,.leftChild=&N35 ,.rightChild=NULL,.data=40},	
		N20={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=20},	
		N30={.balance=1 ,.leftChild=&N20 ,.rightChild=&N40,.data=30},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=0 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},		
		N10={.balance=1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N100={.balance=1 ,.leftChild=NULL ,.rightChild=&N150,.data=100},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=50}
		;
	Node *testNode;
	
	testNode=AVLBalance(&N50);
	TEST_ASSERT_EQUAL(&N30,testNode);
	TEST_ASSERT_EQUAL(&N10,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N20,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N40,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N35,testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild->rightChild);
	
}
	
/*
*        (50)                    (10)
*        /  \                     / \
*      (10) (100)              (5) (50)
*       / \         =>         /    /  \
*    (5)(30)                 (1) (30) (100) 
*    /
*  (1)
*/
void test_AVLBalance_will_will_rotate_the_tree_to_form_a_nearly_balanced_tree_with_6_elements_using_left_rotate()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N5={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=5},	
		N30={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=30},	
		N10={.balance=-1 ,.leftChild=&N5 ,.rightChild=&N30,.data=10},
		N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N50={.balance=-2 ,.leftChild=&N10 ,.rightChild=&N100,.data=10};
	Node *testNode;

	testNode=AVLBalance(&N50);
	TEST_ASSERT_EQUAL(&N10,testNode);
	TEST_ASSERT_EQUAL(&N5,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N30,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	
}

/*
*      (2)               (1)
*        \              /   \
*        (3)    =>    (2)   (3)
*        /
*      (1)
*
*
*/
void test_AVLBalance_will_balance_the_tree_using_doubleLeftRotate()
{
	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N3={.balance=-1 ,.leftChild=&N1 ,.rightChild=NULL,.data=3},	
		N2={.balance=2 ,.leftChild=NULL ,.rightChild=&N3,.data=2};
	Node *testNode;
	
	testNode=AVLBalance(&N2);
	TEST_ASSERT_EQUAL(&N1,testNode);
	TEST_ASSERT_EQUAL(&N2,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N3,testNode->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
}
	void test_avlAddInt_will_add_the_element_according_to_the_AVL_rule_with_three_element()
{
	Node Nroot ={.balance=0,.leftChild = NULL,.rightChild=NULL,.data=10},
		N15 = {.balance=0,.leftChild=NULL,.rightChild=NULL,.data = 15},
		N5 = {.balance=0,.leftChild=NULL,.rightChild=NULL,.data = 5};
		Node *testNode=NULL;
	
		testNode = avlAddInt(testNode,&Nroot);
		
		TEST_ASSERT_NOT_NULL(testNode);
		TEST_ASSERT_EQUAL(&Nroot,testNode);
		testNode = avlAddInt(testNode,&N15);
		TEST_ASSERT_NOT_NULL(testNode->rightChild);
		TEST_ASSERT_EQUAL(&N15,testNode->rightChild);
		testNode = avlAddInt(testNode,&N5);
		TEST_ASSERT_NOT_NULL(testNode->leftChild);
		TEST_ASSERT_EQUAL(&N5,testNode->leftChild);
}
/*
		1


*/
void test_avlAddInt_will_add_one_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}

		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
}
/*
		1
		  \
		   50

*/
void test_avlAddInt_will_add_two_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
			N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50}	
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
}
/********************************************************

Starting from here, the element of the tree is increasing.
The elements is same except for the latest element.

**********************************************************/
/*
		1					50
		  \				   /  \
		   50		=>    1   100
			 \
			  100

*/
void test_avlAddInt_will_add_three_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
			N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100}		
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
}

/*
			50
		   /  \
		  1   100
				/
			  75

*/
void test_avlAddInt_will_add_four_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
			N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75}
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
		
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	
}



/*
			50
		   /  \
		  1   100
				/\
			  75 150

*/
void test_avlAddInt_will_add_five_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
			N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
	testNode=avlAddInt(testNode,&N150);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	
}

/*
			50						100
		   /  \						/  \
		  1   100				   50  150
				/\      =>		   / \  \
			  75 150              1  75  200
					\                      
					200                    
*/
void test_avlAddInt_will_add_six_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
	testNode=avlAddInt(testNode,&N150);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	
}

/*
	     100
	    /  \
	  50  150
	 / \    \
	1  75   200
          
                
*/
void test_avlAddInt_will_add_seven_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N120={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=120}
		;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
	testNode=avlAddInt(testNode,&N150);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N120);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	
}

/*
	        120
	    /        \
	  100        150
	 /   \      /   \
	50   110  130  200
       / \   /    \     \ 
       1  75 105   140   250     
                
*/
void test_avlAddInt_will_add_eleven_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N120={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=120},
	N110={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=110},
	N130={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=130},
	N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N140={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=140}
	;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
	testNode=avlAddInt(testNode,&N150);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N120);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N110);
	
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N110,testNode->rightChild->leftChild->leftChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);

	testNode=avlAddInt(testNode,&N130);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N110,testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N130,testNode->rightChild->leftChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(-1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N250);
	
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N110,testNode->rightChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N130,testNode->rightChild->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	testNode=avlAddInt(testNode,&N140);
	
	TEST_ASSERT_EQUAL(&N120,testNode);
	TEST_ASSERT_EQUAL(&N100,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N110,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N130,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N140,testNode->rightChild->leftChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	
	
}

/*
		    120
	    /        \
	  100        150
	 /   \      /   \
	50   110  130  200
    / \   /    \     \ 
   1  75 105   140   250     
                
*/
void test_avlAddInt_will_add_twelve_element_into_the_tree()
{

	Node N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N120={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=120},
	N110={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=110},
	N130={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=130},
	N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N140={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=140},
	N105={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=105}
	;
	Node *testNode=NULL;	
	
	testNode=avlAddInt(testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(testNode,&N1);
	TEST_ASSERT_NULL(testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
	testNode=avlAddInt(testNode,&N50);
	TEST_ASSERT_EQUAL(&N50,testNode->rightChild);
	TEST_ASSERT_NULL(testNode->leftChild);
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	
	testNode=avlAddInt(testNode,&N100);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N75);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	
	testNode=avlAddInt(testNode,&N150);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N75,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(1,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N120);
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N120,testNode->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL(0,testNode->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	
	testNode=avlAddInt(testNode,&N110);
	testNode=avlAddInt(testNode,&N130);
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N140);
	
	TEST_ASSERT_EQUAL(&N120,testNode);
	TEST_ASSERT_EQUAL(&N100,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N110,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N130,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N140,testNode->rightChild->leftChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->balance);	
	
	testNode=avlAddInt(testNode,&N105);
		
	TEST_ASSERT_EQUAL(&N120,testNode);
	TEST_ASSERT_EQUAL(&N100,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N50,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N1,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N75,testNode->leftChild->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N110,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N105,testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N130,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N140,testNode->rightChild->leftChild->rightChild);
	
	TEST_ASSERT_EQUAL(0,testNode->rightChild->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->rightChild->balance);
	TEST_ASSERT_EQUAL(1,testNode->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->leftChild->balance);
	TEST_ASSERT_EQUAL(-1,testNode->leftChild->rightChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->rightChild->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->leftChild->balance);
	TEST_ASSERT_EQUAL(0,testNode->balance);
	
}
/*************************************************************************************
Starting from here , it is another set of elements that going to the tree.
The previous elements in the tree is remain the same, except for the latest element.
*************************************************************************************/

/*
         250          200         
		 /           /   \
        200        180   250
		/
	  180
*/
void test_avlAddInt_will_balance_the_tree_while_all_the_data_go_to_the_left() 
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180}
		;
	Node *testNode=NULL;
	
	testNode=avlAddInt(testNode,&N250);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N250,testNode);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode->leftChild);
	
	testNode=avlAddInt(testNode,&N180);
	TEST_ASSERT_EQUAL(&N200,testNode);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N180,testNode->leftChild);
}

/*
         250          200         
		 /           /   \
        200        180   250
		/
	  180
*/
void test_avlAddInt_will_balance_the_tree_for_three_data() 
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180}
		;
	Node *testNode=NULL;
	
	testNode=avlAddInt(testNode,&N250);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N250,testNode);
	
	testNode=avlAddInt(testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode->leftChild);
	
	testNode=avlAddInt(testNode,&N180);
	TEST_ASSERT_EQUAL(&N200,testNode);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N180,testNode->leftChild);
}

/*
	200
	/ \
  180 250
    \
	195
*/

void test_avlAddInt_will_balance_for_four_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	
	TEST_ASSERT_EQUAL(&N200,testNode);
	TEST_ASSERT_EQUAL(&N180,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->leftChild->rightChild);
}

/*
	 200
	/   \
  180   250
  /  \
 170 195
*/

void test_avlAddInt_will_balance_for_five_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195},
	N170={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=170}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	testNode=avlAddInt(testNode,&N170);
	
	TEST_ASSERT_EQUAL(&N200,testNode);
	TEST_ASSERT_EQUAL(&N180,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N170,testNode->leftChild->leftChild);
}

/*
	  200                 180
	 /    \              /   \
    180   250          170   200
   /   \         =>    /     /  \
  170  195           150    195  250
  /
 150
 
 
*/

void test_avlAddInt_will_balance_for_six_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195},
	N170={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=170},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	testNode=avlAddInt(testNode,&N170);
	testNode=avlAddInt(testNode,&N150);
	
	TEST_ASSERT_EQUAL(&N180,testNode);
	TEST_ASSERT_EQUAL(&N170,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->leftChild->leftChild);
}

/*
       180                 180
      /   \                /    \
    170   200      =>    170    200
   /      /  \          /   \   /  \
 150     195  250      150 175 195  250


 
 
*/

void test_avlAddInt_will_balance_for_seven_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195},
	N170={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=170},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	testNode=avlAddInt(testNode,&N170);
	testNode=avlAddInt(testNode,&N150);
	testNode=avlAddInt(testNode,&N175);
	
	TEST_ASSERT_EQUAL(&N180,testNode);
	TEST_ASSERT_EQUAL(&N170,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N175,testNode->leftChild->rightChild);
}

/*
           180                        175
         /    \                    /      \
       170    200      =>         170     180
       /   \   /  \              /  \     /  \
     150 175 195  250          150  174  176  200  
     /    / \                  /     /        / \
    100  174 176              100   172      195 250
         /
	   172  
 
*/

void test_avlAddInt_will_balance_for_eleven_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195},
	N170={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=170},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175},
	N174={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=174},
	N176={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=176},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N172={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=172}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	testNode=avlAddInt(testNode,&N170);
	testNode=avlAddInt(testNode,&N150);
	testNode=avlAddInt(testNode,&N175);
	testNode=avlAddInt(testNode,&N174);
	testNode=avlAddInt(testNode,&N176);
	testNode=avlAddInt(testNode,&N100);
	testNode=avlAddInt(testNode,&N172);
	
	TEST_ASSERT_EQUAL(&N175,testNode);
	TEST_ASSERT_EQUAL(&N170,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N180,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N176,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N174,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N172,testNode->leftChild->rightChild->leftChild);
}

/*
           180                        175
         /    \                    /      \
       170    200      =>         170     180
       /   \   /  \              /  \     /  \
     150 175 195  250          150  174  176  200  
     /    / \                  /     /        / \
    100  174 176              100   172      195 250
         /
	   172  
 
*/

void test_avlAddInt_will_balance_for_twelve_element()
{
	Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195},
	N170={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=170},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175},
	N174={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=174},
	N176={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=176},
	N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	N172={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=172},
	N177={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=177}
		;
	Node *testNode=NULL;
	testNode=avlAddInt(testNode,&N250);
	testNode=avlAddInt(testNode,&N200);
	testNode=avlAddInt(testNode,&N180);
	testNode=avlAddInt(testNode,&N195);
	testNode=avlAddInt(testNode,&N170);
	testNode=avlAddInt(testNode,&N150);
	testNode=avlAddInt(testNode,&N175);
	testNode=avlAddInt(testNode,&N174);
	testNode=avlAddInt(testNode,&N176);
	testNode=avlAddInt(testNode,&N100);
	testNode=avlAddInt(testNode,&N172);
	testNode=avlAddInt(testNode,&N177);
	
	TEST_ASSERT_EQUAL(&N175,testNode);
	TEST_ASSERT_EQUAL(&N170,testNode->leftChild);
	TEST_ASSERT_EQUAL(&N180,testNode->rightChild);
	TEST_ASSERT_EQUAL(&N200,testNode->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N250,testNode->rightChild->rightChild->rightChild);
	TEST_ASSERT_EQUAL(&N195,testNode->rightChild->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N176,testNode->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N100,testNode->leftChild->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N150,testNode->leftChild->leftChild);
	TEST_ASSERT_EQUAL(&N174,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL(&N172,testNode->leftChild->rightChild->leftChild);
	TEST_ASSERT_EQUAL(&N177,testNode->rightChild->leftChild->rightChild);
}

void test_avlAddInt_will_throw_an_error_when_same_input_detected()
{
	Node N250A={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
		N250B={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250};
	Error e;
	Node *testNode=NULL;
	
	testNode=avlAddInt(testNode,&N250A);
	
	Try
	{
	testNode=avlAddInt(testNode,&N250B);
	printf("Hahaha,You failed your program.");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(INVALID_INPUT,e);
	}
}
