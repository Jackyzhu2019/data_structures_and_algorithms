/*
 * max_product_subarray.c
 *
 *  Created on: Mar 1, 2020
 *      Author: ZHU_JUN
 */


/* This is used to calculate max product subarray. For example,
 * given the array [2,3,-2,4], the contiguous subarray [2,3] has
 * the largest product = 6.
 */
#include <stdio.h>
#define ARRLEN 5
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)>(y)?(y):(x)

int max_product_subarray(){
	double nums[ARRLEN] = {12, -0.5, 0.00025, 23, 2};
	int i;
	double maxCurProd[ARRLEN];
	double minCurProd[ARRLEN];
	double temp;
	double maxProd;

	maxCurProd[0] = nums[0];
	minCurProd[0] = nums[0];
	maxProd = nums[0];

	for (i=1;i<ARRLEN;i++){
		temp = MAX(maxCurProd[i-1]*nums[i], minCurProd[i-1] * nums[i]);
		maxCurProd[i] = MAX(temp, nums[i]);

		temp = MIN(minCurProd[i-1]*nums[i], minCurProd[i-1] * nums[i]);
		minCurProd[i] = MIN(temp, nums[i]);

		maxProd = MAX(maxProd, maxCurProd[i]);
	}


	printf("maxProd:%f. \n", maxProd);
	fflush(stdout);

	return 0;
}
