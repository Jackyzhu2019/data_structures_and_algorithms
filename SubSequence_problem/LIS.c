/*
 * LIS.c
 *
 *  Created on: Feb 14, 2020
 *      Author: ZHU_JUN
 */


/* This program demos the longest increase subsequence */

#include <stdio.h>

#define ARRLEN 10
#define MAX(x,y) (x)>(y)?(x):(y)

void LIS_N2(int *nums){
	int dp[ARRLEN]= {0};
	int i, j;
	int max;

	dp[0] = 1;
	for (i=1;i<ARRLEN;i++){
		for (j=0;j<i;j++){
			if (nums[j]<nums[i]){
				dp[i] = MAX(dp[i], dp[j]+1);
			}
		}
	}

	max = dp[0];
	for (i=1;i<ARRLEN;i++){
		if (dp[i]>max){
			max = dp[i];
		}
	}

	printf("LIS length with N^2: %d. \n", max);
	fflush(stdout);
}

void binarySearch(int *dp, int len, int value){
	int start, end;
	int middle;

	start = 0;
	end = len-1;

	while(start<end){
		middle = (start + end) >> 1;
		if (dp[middle]<value){
			start = middle + 1;
		}else{
			end = middle;
		}
	}

	dp[start] = value;

}


void LIS_NLogN(int *nums){
	int dp[ARRLEN]= {0};
	int i, j;
	int dp_len;

	dp[0] = nums[0];
	dp_len = 1;
	for (i=1;i<ARRLEN;i++){
		if (nums[i]>dp[dp_len-1]){
			dp[dp_len++] = nums[i];
		}else{
			binarySearch(dp, dp_len, nums[i]);
		}
	}

	printf("LIS length with nlog(n): %d. \n", dp_len);
	fflush(stdout);
}



int LIS(){
	int nums[ARRLEN] = {1, 12, 211, 23, 66, 9, 49, 7, 4, 9};

	LIS_N2(nums);


	LIS_NLogN(nums);

	return 0;
}
