/*
 * LinkedList.c
 *
 *  Created on: May 9, 2020
 *      Author: ZHU_JUN
 */
#include "stdio.h"

typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode_t;

LinkNode_t *reversedLinkedList(LinkNode_t *rootNode){
	LinkNode_t *tempNode, *nextNode;
	LinkNode_t *next;

	next = NULL;
	tempNode = rootNode;

	while (tempNode->next != NULL)
	{
		nextNode = tempNode->next;
		tempNode->next = next;
		next = tempNode;
		tempNode = nextNode;
	}

	tempNode->next = next;

	return tempNode;
}


LinkNode_t *delLinkedList(LinkNode_t *rootNode, LinkNode_t *delNode){
	LinkNode_t *nextNode;
	if (delNode->next == NULL){
		if (rootNode == delNode)
			return NULL;

		nextNode = rootNode;
		while(nextNode->next != delNode){
			nextNode = nextNode->next;
		}

		nextNode->next = NULL;
		return rootNode;
	}


	nextNode = delNode->next;
	delNode->data = nextNode->data;
	delNode->next = nextNode->next;

	return rootNode;
}


LinkNode_t *findMidNode(LinkNode_t *rootNode){
	LinkNode_t *step1, *step2;

	step1 = rootNode;
	step2 = rootNode;

	while(step2->next != NULL){
		if (step2->next->next == NULL){
			break;
		}

		step1 = step1->next;
		step2 = step2->next->next;
	}


	return step1;
}



LinkNode_t *findinvKNode(LinkNode_t *rootNode, int K){
	LinkNode_t *step1, *step2;
	int cnt = 1;

	step1 = rootNode;
	step2 = rootNode;

	while(cnt < K){
		if (step2 == NULL)
			return NULL;

		step2 = step2->next;
		cnt++;
	}


	while (step2->next != NULL){
		step1 = step1->next;
		step2 = step2->next;
	}

	return step1;
}


LinkNode_t *combineLinkedList(LinkNode_t *list_A, LinkNode_t *list_B){
	LinkNode_t *p1, *p2, *pT;
	LinkNode_t *targetNode;

	int cnt = 1;

	targetNode = (LinkNode_t *)malloc(sizeof(LinkNode_t));

	p1 = list_A;
	p2 = list_B;
	pT = targetNode;

	if (p1 == NULL)
		return list_B;

	if (p2 == NULL)
		return list_A;


	if (p1->data > p2->data){
		pT->data = p2->data;
		p2 = p2->next;
	}else{
		pT->data = p1->data;
		p1 = p1->next;
	}

	while ((p1!=NULL) && (p2!=NULL)){
		if (p1->data > p2->data){
			pT->next = p2;
			p2 = p2->next;
		}else{
			pT->next = p1;
			p1 = p1->next;
		}

		pT = pT->next;
	}


	if (p1==NULL){
		pT->next = p2;
	}

	if (p2==NULL){
		pT->next = p1;
	}

	return targetNode;
}



int checkRing(LinkNode_t *rootNode){
	LinkNode_t *slow, *fast;
	int Ring_OK = 0;


	slow = rootNode;
	fast = rootNode;

	while(fast->next != NULL){
		if (fast->next->next == NULL){
			Ring_OK = 0;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow){
			Ring_OK = 1;
			break;
		}
	}

	printf("Whether exist ring or not: %d. \n", Ring_OK);
	fflush(stdout);


	return 0;
}



int checkRing_with_RingLen(LinkNode_t *rootNode){
	LinkNode_t *slow, *fast;
	int Ring_OK = 0;
	int meet_cnt = 0;
	int step_cnt = 0; // step count after first meet

	slow = rootNode;
	fast = rootNode;

	while(fast->next != NULL){
		if (fast->next->next == NULL){
			Ring_OK = 0;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;

		if (meet_cnt == 1){
			step_cnt++;
		}

		if (fast == slow){
			if (meet_cnt == 1){
				meet_cnt = 2;
				break;
			}

			if (meet_cnt == 0){
				Ring_OK = 1;
				meet_cnt = 1;
			}
		}
	}

	printf("Whether exist ring or not: %d, ring length: %d. \n", Ring_OK, step_cnt);
	fflush(stdout);


	return 0;
}

int checkRing_with_RingLen_RingPos(LinkNode_t *rootNode){
	LinkNode_t *slow, *fast;
	int Ring_OK = 0;
	int meet_cnt = 0;
	int step_cnt = 0; // step count

	slow = rootNode;
	fast = rootNode;

	while(fast->next != NULL){
		if (fast->next->next == NULL){
			Ring_OK = 0;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow){
				Ring_OK = 1;
				break;
		}
	}


	slow = rootNode;
	while (fast!=slow){
		slow = slow->next;
		fast = fast->next;
	}


	printf("Whether exist ring or not: %d, Ring connection position: %d. \n", Ring_OK, slow->data);
	fflush(stdout);


	return 0;
}




void test_checkRing(){
	LinkNode_t a0, a1, a2, a3, a4, a5, a6, a7, a8;

	a0.data = 0;
	a0.next = &a1;

	a1.data = 1;
	a1.next = &a2;

	a2.data = 2;
	a2.next = &a3;

	a3.data = 3;
	a3.next = &a4;

	a4.data = 4;
	a4.next = &a5;

	a5.data = 5;
	a5.next = &a6;

	a6.data = 6;
	a6.next = &a7;

	a7.data = 7;
	a7.next = &a8;

	a8.data = 8;
	a8.next = &a3;

    //checkRing(&a0);
	//checkRing_with_RingLen(&a0);
	checkRing_with_RingLen_RingPos(&a0);
}


void test_combineLinkedList(){
	LinkNode_t a0, a1, a2, a3, a4;
	LinkNode_t b0, b1, b2, b3;
	LinkNode_t *rNode;

	a0.data = 0;
	a0.next = &a1;

	a1.data = 2;
	a1.next = &a2;

	a2.data = 4;
	a2.next = &a3;

	a3.data = 19;
	a3.next = &a4;

	a4.data = 20;
	a4.next = NULL;

	b0.data = 1;
	b0.next = &b1;

	b1.data = 3;
	b1.next = &b2;

	b2.data = 5;
	b2.next = &b3;

	b3.data = 27;
	b3.next = NULL;

	rNode = combineLinkedList(&a0, &b0);

	if (rNode == NULL){
		printf("A and B are NULL pointer. \n");
		fflush(stdout);
	}

	while(rNode != NULL){
		printf("%d. \n", rNode->data);
		fflush(stdout);

		rNode = rNode->next;
	}
}





void test_findinvKNode(){
	LinkNode_t a0, a1, a2, a3, a4;
	LinkNode_t *rNode;
	int K = 3;

	a0.data = 0;
	a0.next = &a1;

	a1.data = 1;
	a1.next = &a2;

	a2.data = 2;
	a2.next = &a3;

	a3.data = 3;
	a3.next = &a4;

	a4.data = 4;
	a4.next = NULL;

	rNode = findinvKNode(&a0, K);

	if (rNode == NULL){
		printf("No inverse K point. \n");
		fflush(stdout);
		return;
	}


	printf("Inverse %d'th point: %d. \n", K, rNode->data);
	fflush(stdout);

	return;
}


void test_findMidNode(){
	LinkNode_t a0, a1, a2, a3, a4;
	LinkNode_t *rNode;

	a0.data = 0;
	a0.next = &a1;

	a1.data = 1;
	a1.next = &a2;

	a2.data = 2;
	a2.next = &a3;

	a3.data = 3;
	a3.next = NULL;

	//a4.data = 4;
	//a4.next = NULL;

	rNode = findMidNode(&a0);

	printf("mid point: %d. \n", rNode->data);
	fflush(stdout);

}


void test_reversedLinkedList(){
	LinkNode_t a0, a1, a2, a3, a4;
	LinkNode_t *rNode;

	a0.data = 0;
	a0.next = &a1;

	a1.data = 1;
	a1.next = &a2;

	a2.data = 2;
	a2.next = &a3;

	a3.data = 3;
	a3.next = &a4;

	a4.data = 4;
	a4.next = NULL;

	rNode = reversedLinkedList(&a0);


	while(rNode != NULL){
		printf("%d. \n", rNode->data);
		fflush(stdout);

		rNode = rNode->next;
	}
}




int main(){
	//test_reversedLinkedList();
	//test_delLinkedList();
	//test_findMidNode();
	//test_findinvKNode();
	//test_combineLinkedList();
	test_checkRing();
	return 0;
}
