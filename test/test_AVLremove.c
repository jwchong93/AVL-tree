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
/**
 *      50  => NULL
 *
 * where 50 is being removed 
 */
void test_AVLRemove_change_the_root_become_NULL_after_the_last_element_been_removed()
{
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50}

		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	
	testNode2=AVLRemove(&testNode,&N50);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode2);
	TEST_ASSERT_NULL(testNode);

}


/**
 *      50
 *     /     =>    25
 *   25
 *
 * where 50 is being removed
 */
 void test_AVLRemove_will_take_the_only_child_to_replace_the_root()
 {
 	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25}

		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	
	testNode2=AVLRemove(&testNode,&N50);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode2);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(&N25,testNode);
 }
/**
        200          200
       /  \   =>       \
      180 250          250
**/
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

/**
        200          200
       /  \   =>     /
      180 250      180
**/
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

/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        /
 *      150
 *
 * where 200 is being removed
 */
 void test_AVLRemove_will_replace_200_with_150_after_remove()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N150,0,testNode);
	
 }
 
 /**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   200
 *        / \            /
 *      150 220        150
 * 
 * where 220 is being removed
 */
 
  void test_AVLRemove_will_replace_the_node_with_null_if_the_node_does_not_contain_any_child()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
	N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N220);
	
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N220,0,testNode->rightChild);
	
	testNode2=AVLRemove(&testNode,&N220);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N220,testNode2);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,NULL,-1,testNode->rightChild);
	
 }
 
/**
 *      50
 *        \     =>    50
 *        200
 *
 * where 200 is being removed
 */
 void test_AVLRemove_will_remove_the_right_child()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
	N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N200);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testNode);
 }
 
 /**
 *        50                  50
 *      /   \               /   \
 *     25   200           25    200
 *    /    /  \    =>    /     /  \
 *   1   150  250       1    150  220
 *            /
 *          220
 * 
 * where 250 is being removed
 */
 
 void test_AVLRemove_will_remove_the_third_level_node_and_replace_it_by_the_leftChild_of_the_node()
 {
		Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
		N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N250);
	testNode=AVLAdd(testNode,&N220);
	
	testNode2=AVLRemove(&testNode,&N250);
	TEST_ASSERT_EQUAL(&N250,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N220,0,testNode->rightChild);

	
 }
 
 /**
 *        50                 50            25
 *      /   \               /            /   \
 *     25   150    =>     25       =>   1    50
 *    /                  /
 *   1                  1
 *
 * where 150 is being removed
 */
 void test_AVLRemove_will_balance_the_tree_after_remove_the_specific_element()
 {
		Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N1);
	
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N150,-1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	
	testNode2=AVLRemove(&testNode,&N150);
	TEST_ASSERT_EQUAL(&N150,testNode2);
	//printf("The Value of the testNode->%d",testNode->data);
	TEST_ASSERT_EQUAL(&N25,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N50,0,testNode);
	
 }
 
 /**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \    /  \
 *   1   50    200       1   50             1   40  75  150
 *      /  \                /  \
 *     40  75              40  75
 *
 * where 200 is being removed
 */
 
 void test_AVLRemove_will_remove_and_balance_the_tree_using_double_rotation()
 {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N40);
	testNode=AVLAdd(testNode,&N75);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N100,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N40,0,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N75,&N150,0,testNode->rightChild);
 }
 
 
 /**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   1   50    200       1   50             1      75  150
 *         \                   \
 *         75                  75
 *
 * where 200 is being removed
 */
 
 void test_AVLRemove_will_balance_the_tree_using_double_rotation()
 {
		Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N75);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N100,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N75,&N150,0,testNode->rightChild);
 }
 
 /**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \       \
 *   1   50    200       1   50             1   40      150
 *      /                   /
 *     40                  40
 *
 * where 200 is being removed
 */
 
 void test_AVLRemove_will_perform_doubleRotation_if_there_are_some_other_children_need_to_be_handle()
 {
 	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N40);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N100,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N40,0,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N150,1,testNode->rightChild);
	
 }
 
 /**
 *        100                  100                40
 *      /    \               /    \             /    \
 *     40    150           40     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   25  75   200        25  75             1      75   150
 *  /    /              /    /                    /
 * 1    50             1    50                  50
 *
 * where 200 is being removed
 */
 
 void test_AVLRemove_will_right_rotate_the_tree_after_remove()
 {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N40);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N75);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	
	testNode2=AVLRemove(&testNode,&N200);
	TEST_ASSERT_EQUAL(&N200,testNode2);
	TEST_ASSERT_EQUAL(&N40,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N100,1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N75,&N150,-1,testNode->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N50,NULL,-1,testNode->rightChild->leftChild);
	
 }
 
/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *             \                  \
 *             200                200
 *
 * Attempt to remove 1, which cannot be found in the tree.
 */
 
 void test_AVLRemove_will_return_null_when_the_node_can_not_be_found()
 {
 	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N200);
	
	testNode2=AVLRemove(&testNode,&N1);
	TEST_ASSERT_NULL(testNode2);
	//printf("What is the leftChild?->%d",testNode->leftChild->data);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N150,1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N200,1,testNode->rightChild);
 }
 
 
/**
 *      50             50
 *     /  \     =>       \
 *   25   150            150
 *
 * where 25 is being removed
 */
 
 void test_AVLRemove_will_remove_leftChild()
 {
	 	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	
	testNode2=AVLRemove(&testNode,&N25);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N25,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N150,1,testNode);
 }
 
 
/**
 *        50                 150
 *      /   \               /  \
 *     25   150    =>     50   200
 *             \
 *             200
 *
 * where 25 is being removed
 */
 
 void test_AVLRemove_will_remove_a_node_and_perform_left_rotate()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N200);
	
	testNode2=AVLRemove(&testNode,&N25);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N25,testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N50,&N200,0,testNode);
 }

 /**
 *        50                 50
 *      /   \               /  \
 *    25    150    =>     1    150
 *    /       \                  \
 *   1       200                 200
 *
 * where 25 is being removed
 */
 
 void test_AVLRemove_will_remove_the_node_and_replace_the_empty_space_using_its_child()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N1);
	
	testNode2=AVLRemove(&testNode,&N25);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N25,testNode2);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N150,1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N200,1,testNode->rightChild);
 }
 
 /**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \     /  \
 *   1    150  220              150  220        25  120 175  220
 *       /  \                  /  \
 *     120  175              120  175
 *
 * where 1 is being removed
 */
 
 void test_AVLRemove_will_balance_the_tree_using_doubel_right_rotate()
 {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220},
		N120={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=120},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
		N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175}
	;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N220);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N120);
	testNode=AVLAdd(testNode,&N175);
	
	testNode2=AVLRemove(&testNode,&N1);
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N1,testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N100,&N200,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N175,&N220,0,testNode->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N120,0,testNode->leftChild);
 }
 /**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  120     220
 *       /                     /
 *     120                   120
 *
 * where 1 is being removed
 */
 
 void test_AVLRemove_will_remove_one_and_perform_a_double_left_rotate_even_the_tree_are_not_perfectly_balanced()
 {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220},
		N120={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=120},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N220);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N120);
	
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,1,testNode); 
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N220,-1,testNode->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N120,NULL,-1,testNode->rightChild->leftChild);
	
	testNode2=AVLRemove(&testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N1,testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N100,&N200,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N120,0,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N220,1,testNode->rightChild);
	

	
 }
 
 /**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /        /  \
 *   1    150  220              150  220        25      175  220
 *          \                     \
 *          175                   175
 *
 * where 1 is being removed
 */
 
  void test_AVLRemove_will_perform_double_left_rotate_if_the_right_sided_tree_with_different_form()
  {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220},
		N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N220);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N175);
	
	TEST_ASSERT_EQUAL(&N100,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,1,testNode); 
	TEST_ASSERT_EQUAL_AVL_Node(&N1,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N150,&N220,-1,testNode->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N175,1,testNode->rightChild->leftChild);
	
	testNode2=AVLRemove(&testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N1,testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N100,&N200,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,NULL,-1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N175,&N220,0,testNode->rightChild);
  }
 
 /**
 *        100                  100                    200
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     220
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  150     250
 *          \    \                \    \              \
 *          175  250              175  250            175
 *
 * where 1 is being removed
 */
 void test_AVLRemove_will_perform_a_left_rotate()
 {
	Node N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N220={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=220},
		N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
		N175={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=175},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
		
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N100);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N220);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N175);
	testNode=AVLAdd(testNode,&N250);
	
	testNode2=AVLRemove(&testNode,&N1);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N1,testNode2);
	TEST_ASSERT_EQUAL(&N200,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N100,&N220,-1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N150,1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N175,1,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N250,1,testNode->rightChild);
 }
 
 /**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       40   200
 *    \
 *    40
 *
 * where 25 is being removed
 */
 
 void test_AVLRemove_will_get_the_replacer_from_right_if_there_is_NULL_at_left()
 {
	Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40}
		;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N40);
		
	testNode2=AVLRemove(&testNode,&N40);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N40,testNode2);
	
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,0,testNode);
 }
 
 /**
 *       50             50
 *      /  \     =>    /  \
 *    25   200        1   200
 *   / \               \
 *  1  40              40
 *
 * where 25 is being removed
 */
 
 void test_AVLRemove_will_replace_the_node_if_there_are_only_leftChild()
 {
		Node N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
		
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N40);
	testNode=AVLAdd(testNode,&N1);
	
	testNode2=AVLRemove(&testNode,&N25);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N25,testNode2);
	
	//printf("What is the leftChild?->%d",testNode->leftChild->leftChild->data);
	TEST_ASSERT_EQUAL(&N50,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N200,-1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N40,1,testNode->leftChild);
	
 }
 
  /**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *       \
 *       90
 *
 * where 150 is being removed
 */
 
 void test_AVLRemove_will_be_balanced_when_the_root_is_been_removeed()
 {
	Node N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N90={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=90},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
		
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N250);
	testNode=AVLAdd(testNode,&N90);
	
	testNode2=AVLRemove(&testNode,&N150);
	
	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode2);
	//printf("What is the data in here ? ->%d",testNode->data);
	TEST_ASSERT_EQUAL(&N90,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,0,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N50,0,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N250,1,testNode->rightChild);
 }
 
 
/**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *    /  \              /
 *   40  90            40
 *
 * where 150 is being removed
 */
 
 void xtest_AVLRemove_will_take_the_right_most_node_to_replace()
 {	
	Node N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
		N25={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=25},
		N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
		N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
		N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50},
		N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
		N90={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=90},
		N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1}
		;
	
	Node *testNode=NULL;
	Node *testNode2=NULL;
	
		
	testNode=AVLAdd(testNode,&N150);
	testNode=AVLAdd(testNode,&N25);
	testNode=AVLAdd(testNode,&N200);
	testNode=AVLAdd(testNode,&N1);
	testNode=AVLAdd(testNode,&N50);
	testNode=AVLAdd(testNode,&N250);
	testNode=AVLAdd(testNode,&N90);
	testNode=AVLAdd(testNode,&N40);
	
	TEST_ASSERT_EQUAL(&N150,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,-1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N50,1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N40,&N90,0,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N250,1,testNode->rightChild);
	
	testNode2=AVLRemove(&testNode,&N150);

	TEST_ASSERT_NOT_NULL(testNode2);
	TEST_ASSERT_EQUAL(&N150,testNode2);
	printf("What is the data in here ? ->%d",testNode->data);
	TEST_ASSERT_EQUAL(&N90,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N25,&N200,-1,testNode);
	TEST_ASSERT_EQUAL_AVL_Node(&N1,&N50,1,testNode->leftChild);
	TEST_ASSERT_EQUAL_AVL_Node(&N40,NULL,-1,testNode->leftChild->rightChild);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&N250,1,testNode->rightChild);
	
	
	
 }
// /**
        // 200          200         180
       // /  \   =>     /     =>    / \
      // 180 250      180         150 200
     // /  \          / \              /
    // 150 190      150 190           190
// **/

// void test_AVLRemove_will_balance_the_tree_after_remove()
// {
	// Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	// N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	// N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	// N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	// N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150}
		// ;
		
	// Node *testNode=NULL;
	// Node *testRoot=NULL;
	// testRoot=AVLAdd(testRoot,&N250);
	// testRoot=AVLAdd(testRoot,&N200);
	// testRoot=AVLAdd(testRoot,&N180);
	// testRoot=AVLAdd(testRoot,&N190);
	// testRoot=AVLAdd(testRoot,&N150);
	
	// testNode=AVLRemove(&testRoot,&N250);
	// TEST_ASSERT_NOT_NULL(testNode);
	// TEST_ASSERT_EQUAL(&N250,testNode);
	// TEST_ASSERT_EQUAL(&N180,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N150,&N200,1,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N190,NULL,-1,testRoot->rightChild);
// }



// /**
        // 200          200          200           190
       // /  \   =>     /  \   =>    / \    =>    /   \
      // 180 250      180  250     190 250      180   200
     // /  \   \      / \          / \          / \   /  \
    // 150 190 300   150 190     180 195      150 185 195 250
        // / \           / \     / \       
      // 185 195       185 195 150 185      
// **/
// void test_AVLRemove_will_balance_the_tree_after_remove_the_element_at_level_3()
// {
	// Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	// N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	// N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	// N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	// N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	// N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	// N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	// N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		// ;
	// Node *testNode=NULL;
	// Node *testRoot=NULL;
	// testRoot=AVLAdd(testRoot,&N250);
	// testRoot=AVLAdd(testRoot,&N200);
	// testRoot=AVLAdd(testRoot,&N180);
	// testRoot=AVLAdd(testRoot,&N190);
	// testRoot=AVLAdd(testRoot,&N150);
	// testRoot=AVLAdd(testRoot,&N300);
	// testRoot=AVLAdd(testRoot,&N185);
	// testRoot=AVLAdd(testRoot,&N195);
	
	// testNode=AVLRemove(&testRoot,&N300);
	// TEST_ASSERT_NOT_NULL(testNode);
	// TEST_ASSERT_EQUAL(&N300,testNode);
	// TEST_ASSERT_EQUAL(&N190,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N180,&N200,0,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N150,&N185,0,testRoot->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N195,&N250,0,testRoot->rightChild);

// }
// /**
        // 200          200          200           190
       // /  \   =>     /  \   =>    / \    =>    /   \
      // 180 250      180  300     190 300      180   200
     // /  \   \      / \          / \          / \   /  \
    // 150 190 300   150 190     180 195      150 185 195 300
        // / \           / \     / \       
      // 185 195       185 195 150 185      
// **/
// void test_AVLRemove_will_replace_the_empty_space_of_N250_with_N300()
// {
	// Node N250={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=250},
	// N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	// N180={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=180},
	// N190={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=190},
	// N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	// N300={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=300},
	// N185={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=185},
	// N195={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=195}
		// ;
	// Node *testNode=NULL;
	// Node *testRoot=NULL;
	// testRoot=AVLAdd(testRoot,&N250);
	// testRoot=AVLAdd(testRoot,&N200);
	// testRoot=AVLAdd(testRoot,&N180);
	// testRoot=AVLAdd(testRoot,&N190);
	// testRoot=AVLAdd(testRoot,&N150);
	// testRoot=AVLAdd(testRoot,&N300);
	// testRoot=AVLAdd(testRoot,&N185);
	// testRoot=AVLAdd(testRoot,&N195);
	
	// testNode=AVLRemove(&testRoot,&N250);
	// TEST_ASSERT_NOT_NULL(testNode);
	// TEST_ASSERT_EQUAL(&N250,testNode);
	//printf("What this?->%d\n",testRoot->data);
	// TEST_ASSERT_EQUAL(&N190,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N180,&N200,0,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N150,&N185,0,testRoot->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N195,&N300,0,testRoot->rightChild);

// }
// /**
        // 200          200          200           190
       // /  \   =>     /  \   =>    / \    =>    /   \
      // 180 250      180  300     190 300      180   200
     // /  \   \      / \          / \          / \   /  \
    // 150 190 300   150 190     180 195      150 185 195 300
        // / \           / \     / \       
      // 185 195       185 195 150 185      
// **/

// void test_AVLRemove_N100_will_replace_by_N75()
// {
	// Node N60={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=60},
	// N140={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=140},
	// N40={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=40},
	// N200={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=200},
	// N150={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=150},
	// N19={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=19},
	// N17={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=17},
	// N5={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=5},
	// N75={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=75},
	// N100={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=100},
	// N1={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=1},
	// N50={.balance=0 ,.leftChild=NULL ,.rightChild=NULL,.data=50}
		// ;
	// Node *testNode=NULL;
	// Node *testRoot=NULL;
	// testRoot=AVLAdd(testRoot,&N50);
	// testRoot=AVLAdd(testRoot,&N1);
	// testRoot=AVLAdd(testRoot,&N100);
	// testRoot=AVLAdd(testRoot,&N75);
	// testRoot=AVLAdd(testRoot,&N5);
	// testRoot=AVLAdd(testRoot,&N17);
	
	// testRoot=AVLAdd(testRoot,&N19);
	// testRoot=AVLAdd(testRoot,&N150);
	// testRoot=AVLAdd(testRoot,&N200);
	// testRoot=AVLAdd(testRoot,&N140);
	// testRoot=AVLAdd(testRoot,&N60);
	// testRoot=AVLAdd(testRoot,&N40);
	
	// TEST_ASSERT_EQUAL(&N50,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N5,&N100,0,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N1,&N19,1,testRoot->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N17,&N40,0,testRoot->leftChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->rightChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N75,&N150,0,testRoot->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N140,&N200,0,testRoot->rightChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N60,NULL,-1,testRoot->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->leftChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->rightChild->rightChild);
	
	
	// testNode=AVLRemove(&testRoot,&N100);
	// TEST_ASSERT_NOT_NULL(testNode);
	// TEST_ASSERT_EQUAL(&N100,testNode);
	
	// TEST_ASSERT_EQUAL(&N50,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N5,&N75,0,testRoot);
	// TEST_ASSERT_EQUAL_AVL_Node(&N1,&N19,1,testRoot->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N17,&N40,0,testRoot->leftChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->leftChild->rightChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N60,&N150,1,testRoot->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(&N140,&N200,0,testRoot->rightChild->rightChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->rightChild->leftChild);
	// TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,testRoot->rightChild->rightChild->rightChild);
	

// }













