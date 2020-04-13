/*
 * max_sum_subarray.c
 *
 *  Created on: Mar 1, 2020
 *      Author: ZHU_JUN
 */


/* This is used to calculate max sum subarray. For example,
 * given the array [2, 3, -2, -3, 4], the contiguous subarray [2, 3]
 * has the largest sum = 5
 */
#include <stdio.h>

#define ARRLEN 10
#define MAX(x,y) (x)>(y)?(x):(y)

int max_sum_subarray(){
	int nums[ARRLEN] = {1, -12, 211, 23, -66, 9, -49, 7, 4, 9};
	int i;
	int curSum[ARRLEN];
	int maxSum;

	curSum[0] = nums[0];
	maxSum = nums[0];

	for (i=1;i<ARRLEN;i++){
		curSum[i] = MAX(curSum[i-1]+nums[i], nums[i]);
		maxSum = MAX(maxSum, curSum[i]);
	}


	printf("maxSum:%d. \n", maxSum);
	fflush(stdout);

	return 0;
}
