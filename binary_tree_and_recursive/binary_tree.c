/*
 * binary_tree.c
 *
 *  Created on: May 1, 2020
 *      Author: ZHU_JUN
 */

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
}TreeNode_t;


// Definition for a binary tree node.
typedef struct TreeNode_with_Parent {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
      struct TreeNode *parentNode;
}TreeNode_with_Parent_t;



void pre_order_traverse(TreeNode_t *tree){
	if (tree == NULL){
		return;
	}

	printf("Node: %d. \n", tree->val);
	fflush(stdout);

	pre_order_traverse(tree->left);
	pre_order_traverse(tree->right);

	return;
}



void in_order_traverse(TreeNode_t *tree){
	if (tree == NULL){
		return;
	}

	in_order_traverse(tree->left);
	printf("Node: %d. \n", tree->val);
	fflush(stdout);
	in_order_traverse(tree->right);

	return;
}


void post_order_traverse(TreeNode_t *tree){
	if (tree == NULL){
		return;
	}

	post_order_traverse(tree->left);
	post_order_traverse(tree->right);
	printf("Node: %d. \n", tree->val);
	fflush(stdout);

	return;
}


//static int preV[3] = {1 ,2, 4}; //{1,2,4,7,3,5,6,8};
//static int inV[3] = {2, 1, 4}; //{4,7,2,1,5,3,8,6};
static int preV[8] = {1,2,4,7,3,5,6,8};
static int inV[8] = {4,7,2,1,5,3,8,6};


TreeNode_t* reConstruct(int preV_start, int preV_end, int inV_start, int inV_end){
	TreeNode_t *Tree_node;
	int preV_start_left, preV_end_left, inV_start_left, inV_end_left;
	int preV_start_right, preV_end_right, inV_start_right, inV_end_right;
	int i, len;

	Tree_node = (TreeNode_t *) malloc(sizeof(TreeNode_t));
	Tree_node->val = preV[preV_start];

	if ((preV_start == preV_end) || (inV_start == inV_end)){
			Tree_node->left = NULL;
			Tree_node->right = NULL;
			return Tree_node;
		//return NULL;
	}

	for (i=inV_start;i<=inV_end;i++)
	{
		if (preV[preV_start] == inV[i]){
			break;
		}
	}

	len = i - inV_start;


	if (len == 0){
		Tree_node->left = NULL;
		//return NULL;

	} else {
		preV_start_left = preV_start + 1;
		preV_end_left = preV_start_left + len-1;
		inV_start_left = inV_start;
		inV_end_left = i - 1;

		Tree_node->left = reConstruct(preV_start_left, preV_end_left, inV_start_left, inV_end_left);
	}

	if (len == (inV_end - inV_start)){
		Tree_node->right = NULL;
		//return NULL;

	}else {
		preV_start_right = preV_start + len + 1;
		preV_end_right = preV_end;
		inV_start_right = i + 1;
		inV_end_right = inV_end;

		Tree_node->right = reConstruct(preV_start_right, preV_end_right, inV_start_right, inV_end_right);
	}

	return Tree_node;
}

TreeNode_with_Parent_t *nextNode(TreeNode_with_Parent_t *tree_node_p){
	TreeNode_with_Parent_t *ptree, *parentNode;
	/* Case 1:
	 有右子节点
	右子节点有无左子节点
		无 —— 右子节点就是当前结点下一节
		有 —— 递归寻找右子节点的左子节点就是下一节点
	*/

	if (tree_node_p->right != NULL){
		if (tree_node_p->right->left == NULL){
			return tree_node_p->right;
		}else {
			ptree = tree_node_p->right->left;
			while (ptree->left!=NULL)
				ptree = ptree->left;

			return ptree;
		}
	}

	/*
		无右子节点
			无父节点 —— 无下一结点
			有父节点
				- 当前结点作为父节点的左子节点 —— 下一结点为父节点
				- 当前结点作为父节点的右子节点 —— 向父节点递归寻找作为左子节点的结点就是下一节点
	*/

	if (tree_node_p->right == NULL){
		if (tree_node_p->parentNode == NULL){
			return NULL;
		}else {
			ptree = tree_node_p; //->parentNode;
			while (ptree->parentNode != NULL){
				if (ptree->parentNode->left == ptree){
					return ptree->parentNode;
				}

				if (ptree->parentNode->right == ptree){
						ptree = ptree->parentNode;
				}
			}
		}
	}

	return NULL;
}

/*Need two iterations here*/

/* Is treeB is subtree of treeA */
int IsBSubTreeofA(TreeNode_t *treeA, TreeNode_t *treeB){
	 if (treeB == NULL){
		 return 1;
	 }

	if (treeA == NULL){
		return 0;
	}

	if (treeA->val != treeB->val){
		return 0;
	}


	if (treeA->val == treeB->val){
		return (IsBSubTreeofA(treeA->left, treeB->left) && IsBSubTreeofA(treeA->right, treeB->right));
	}

	return 0;
}

/*treeA combinations*/
int TreeA_Combinations(TreeNode_t *treeA, TreeNode_t *treeB){
	if (treeA == NULL){
			return 0;
	}

	 if (treeB == NULL){
			 return 1;
	 }

	 if (treeA->val == treeB->val){
	 		return (IsBSubTreeofA(treeA->left, treeB->left) && IsBSubTreeofA(treeA->right, treeB->right));
	 }

	return (TreeA_Combinations(treeA->left, treeB) || TreeA_Combinations(treeA->right, treeB));
}




void mirror_binary_tree(TreeNode_t *tree){
	TreeNode_t *temp_tree;

	if (tree == NULL)
		return;

	temp_tree = tree->left;
	tree->left = tree->right;
	tree->right = temp_tree;

	mirror_binary_tree(tree->left);

	mirror_binary_tree(tree->right);


	return;
}




int Symmetric_tree(TreeNode_t *tree){
	if ((tree->left == NULL) && (tree->right == NULL))
		return 1;

	if ((tree->left == NULL) && (tree->right != NULL))
		return 0;

	if ((tree->left != NULL) && (tree->right == NULL))
		return 0;

	if (tree->left->val != tree->right->val)
		return 0;

	return ((Symmetric_tree(tree->left))&&Symmetric_tree(tree->right));
}


#define MAX(x,y) (x)>(y)?(x):(y)

int MaxTreeDepth(TreeNode_t *tree){
	int leftDepth;
	int rightDepth;
	int depth;

	if (tree == NULL)
		return 0;

	leftDepth = MaxTreeDepth(tree->left);
	rightDepth = MaxTreeDepth(tree->right);

	depth = MAX(leftDepth, rightDepth);
	depth += 1;
	return depth;
}

int cnt = 0;
int K = 4;
int KstNode(TreeNode_t *tree){
	if (tree==NULL)
		return 0;

	KstNode(tree->left);
	cnt++;

	//if (cnt == K){
		printf("the %d'th Node is %d. \n", cnt, tree->val);
		fflush(stdout);
	//}

	KstNode(tree->right);

	return 0;
}

int NodeVal[100];
int serialize_cnt = 0;

void serialize(TreeNode_t *tree){
	if (tree == NULL){
		NodeVal[serialize_cnt++] = 1000;
		return;
	}

	NodeVal[serialize_cnt++] = tree->val;
	serialize(tree->left);
	serialize(tree->right);

	return;
}


int NodeVal_deS[13] = {0, 1, 3, 1000, 1000, 4, 5, 1000, 1000, 1000, 2, 1000, 1000};
int deS_cnt = 0;

TreeNode_t* deSerialize(){
	TreeNode_t *Tree_node;

	if (deS_cnt == 13)
		return NULL;

	if (NodeVal_deS[deS_cnt]==1000){
		deS_cnt++;
		return NULL;
	}


	Tree_node = (TreeNode_t *) malloc(sizeof(TreeNode_t));

	Tree_node->val = NodeVal_deS[deS_cnt++];

	Tree_node->left = deSerialize();

	Tree_node->right = deSerialize();




	return Tree_node;
}


int stack[20]; // stack
int stack_sum = 0; // sum in stack elements
int stack_cnt = 0; // number of element in stack

int path_num = 0;  // number of path
int savedPath[10][20]; // max number of path, path length
int savedPathLen[10];

void treeSum(TreeNode_t *Tree_node, int expected_sum){

	stack[stack_cnt++] = Tree_node->val;
	stack_sum += Tree_node->val;

	if ((Tree_node->left == NULL) && (Tree_node->right == NULL)){
		if (stack_sum == expected_sum){
			savedPathLen[path_num] = stack_cnt;
			memcpy(savedPath[path_num], stack, stack_cnt * sizeof(int));
			path_num++; // increase number of path
		}
	}

	if (Tree_node->left != NULL)
		treeSum(Tree_node->left, expected_sum);

	if (Tree_node->right != NULL)
		treeSum(Tree_node->right, expected_sum);


	stack_cnt--; // decrease the number of element in stack
	stack_sum -= Tree_node->val;

	return;
}

//int array[4] = {1, 2, 3, 4};

int isPostOrder(int *array, int start, int end){
	int i, j;
	int left_start, left_end, right_start, right_end;
	int isLeftPostOrder, isRightPostOrder;

	if (start>end){
		return 1;
	}

	for (i=start;i<end;i++){
		if (array[i] > array[end]){
			break;
		}
	}

	left_start = start;
	left_end = i-1;


	right_start = i;
	right_end = end -1;


	for (j=right_start;j<end;j++){
		if (array[j] < array[end])
			return 0;
	}


	isLeftPostOrder = isPostOrder(array, left_start, left_end);
	isRightPostOrder = isPostOrder(array, right_start, right_end);

	return (isLeftPostOrder && isRightPostOrder);
}


void levelOrder(TreeNode_t *tree){
	TreeNode_t *queueNode[100];
	int enqueueNodeCnt = 0;
	int outqueueNodeCnt = 0;
	int i;

	queueNode[enqueueNodeCnt++] = tree;

	while (outqueueNodeCnt < enqueueNodeCnt){
		if (tree->left != NULL){
			queueNode[enqueueNodeCnt++] = tree->left;
		}

		if (tree->right != NULL){
			queueNode[enqueueNodeCnt++] = tree->right;
		}

		tree = queueNode[++outqueueNodeCnt];
	}


	for (i=0;i<enqueueNodeCnt;i++)
	{
		printf("%d ", queueNode[i]->val);
		fflush(stdout);
	}

	printf("\n");
	fflush(stdout);
}

int test_levelOrder(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = &a6;

	a3.val = 3;
	a3.left = NULL;
	a3.right = &a6;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;


	a6.val = 6;
	a6.left = NULL;
	a6.right = NULL;



	levelOrder(&a0);

	return 0;
}


int test_isPostOrder(){
	int array[4] = {0, 3, 1, 2};
	int isPost;

	isPost = isPostOrder(array, 0, 3);
	printf("Is the array in post order: %d. \n", isPost);
	fflush(stdout);

	return 0;
}

int test_treeSum(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	int sum = 4;
	int i, j;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = NULL;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;

	treeSum(&a0, sum);


	if (path_num == 0){
		printf("Path not found!\n");
		fflush(stdout);
	}

	for (i=0;i<path_num;i++){
		printf("Path %d: ", i);
		fflush(stdout);

		for (j = 0;j<savedPathLen[i];j++){
			printf("%d ", savedPath[i][j]);
			fflush(stdout);
		}

		printf("\n");
		fflush(stdout);
	}


	return 0;
}

int test_serialize(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	TreeNode_t *d;
	int i;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = NULL;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;

	serialize(&a0);

	for (i=0;i<serialize_cnt;i++){
		printf("%d ", NodeVal[i]);
		fflush(stdout);
	}

	printf("\n");

	d = deSerialize();
	pre_order_traverse(d);


	return 0;
}

int test_KstDepth(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	int maxDepth;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = NULL;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;

	maxDepth = KstNode(&a0);

	return 0;
}

int test_MaxTreeDepth(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	TreeNode_t b0, b1, b2, b3, b4, b5, b6;
	int maxDepth;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = NULL;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;

	maxDepth = MaxTreeDepth(&a0);

	printf("Max Tree Depth: %d \n", maxDepth);
	fflush(stdout);

	return 0;
}


int test_Symmetric_tree(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = NULL;
	a1.right = NULL;

	a2.val = 1;
	a2.left = NULL;
	a2.right = NULL;



	printf("Is symmetric tree: 1: yes 0: no. Ans: %d \n", Symmetric_tree(&a0));
	fflush(stdout);

	return 0;
}

int test_Subtree(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;
	TreeNode_t b0, b1, b2, b3, b4, b5, b6;
	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = NULL;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = &a5;
	a4.right = NULL;

	a5.val = 5;
	a5.left = NULL;
	a5.right = NULL;


	b0.val = 4;
	b0.left = &b5;
	b0.right = NULL;

	b5.val = 5;
	b5.left = NULL;
	b5.right = NULL;

	printf("Is subtree: 1: yes 0: no. Ans: %d \n", TreeA_Combinations(&a0, &b0));
	fflush(stdout);

	return 0;
}





int test_mirror_binary_tree(){
	TreeNode_t a0, a1, a2, a3, a4, a5, a6;

	a0.val = 0;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.left = NULL;
	a2.right = &a5;

	a3.val = 3;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.left = NULL;
	a4.right = NULL;

	a5.val = 5;
	a5.left = &a6;
	a5.right = NULL;


	a6.val = 6;
	a6.left = NULL;
	a6.right = NULL;


	mirror_binary_tree(&a0);


	printf("pre order: \n");
	fflush(stdout);
	pre_order_traverse(&a0);

	return 0;
}



int test_nextNode(){
	TreeNode_with_Parent_t *currentNode, *targetNode;
	TreeNode_with_Parent_t a0, a1, a2, a3, a4, a5, a6;

	a0.val = 0;
	a0.parentNode = NULL;
	a0.left = &a1;
	a0.right = &a2;

	a1.val = 1;
	a1.parentNode = &a0;
	a1.left = &a3;
	a1.right = &a4;

	a2.val = 2;
	a2.parentNode = &a0;
	a2.left = NULL;
	a2.right = &a5;

	a3.val = 3;
	a3.parentNode = &a1;
	a3.left = NULL;
	a3.right = NULL;

	a4.val = 4;
	a4.parentNode = &a1;
	a4.left = NULL;
	a4.right = NULL;

	a5.val = 5;
	a5.parentNode = &a2;
	a5.left = &a6;
	a5.right = NULL;


	a6.val = 6;
	a6.parentNode = &a5;
	a6.left = NULL;
	a6.right = NULL;

	currentNode = &a6;
	//currentNode = &a3;
	//currentNode = &a4;
	//currentNode = &a5;
	//currentNode = &a6;

	targetNode = nextNode(currentNode);
	if (targetNode != NULL){
		printf("target next node is %d. \n", targetNode->val);
		fflush(stdout);
	}else {
		printf("target next node is NULL. \n");
		fflush(stdout);
	}
	return 0;
}


int test_reConstruct(int argc, char **argv){
	TreeNode_t *pTree;

	pTree = reConstruct(0, 7, 0, 7);
	//pTree = reConstruct(0, 2, 0, 2);


	printf("pre order: \n");
	fflush(stdout);
	pre_order_traverse(pTree);
	printf("in order: \n");
	fflush(stdout);
	in_order_traverse(pTree);

	return 0;
}



int binary_tree(){

	//test_nextNode();
	//test_reConstruct();
	//test_Subtree();
	//test_mirror_binary_tree();
	//test_Symmetric_tree();
	//test_MaxTreeDepth();
	//test_KstDepth();
	//test_serialize();
	//test_treeSum();
	//test_isPostOrder();
	//test_levelOrder();

	return 0;
}

