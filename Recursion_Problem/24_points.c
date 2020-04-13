/*
 * 24_points.c
 *
 *  Created on: Apr 12, 2020
 *      Author: ZHU_JUN
 */


/*  We want 4 decimal numbers which ranges from 0~9 to form 24 point with operations + - * /
	For example, 4 numbers: 7, 3, 2, 4. Then (7+3)*2+4=24.
*/

#include <stdio.h>
#include <string.h>

int nums[4];// = {7, 3, 2, 4};
int SET_COMB[24][4];
int Set_cnt=0;


int func(int result, int* nums, int len){
	int i;
	int success;
	int temp_result;

	if ((len == 1) && (result == nums[0]))
	{
		return 1;
	}

	if(len == 1){
		return 0;
	}

	success = 0;
	for (i=0;i<4;i++){
		switch (i){
			case 0: temp_result = result - nums[len-1]; break;
			case 1: temp_result = result + nums[len-1]; break;
			case 2: temp_result = result * nums[len-1]; break;
			case 3:
				if ((result%nums[len-1])==0){
					temp_result = result / nums[len-1];
				}else{
					return success;
				}
				break;
		}

		success += func(temp_result, nums, len-1);
	}

	return success;
}

void Swap(int *set, int i, int j){
	int temp = set[j];

	set[j] = set[i];
	set[i] = temp;
}

void Permute(int *set, int start, int end){
	if (start==end){
		memcpy(SET_COMB[Set_cnt], set, 4 * sizeof(int)); // save the final result
		Set_cnt++;
	}

	for (int i=start;i<end;i++){
		Swap(set, start, i); // exchange set[start] and set[i]
		Permute(set, start+1, end);
		Swap(set, start, i); // recover the set
	}
}


int main(int argc, char **argv){
	int jump_next = 0;

	while(scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]) != EOF){
		jump_next = 0;
		Set_cnt = 0;

		Permute(nums, 0, 4);

		for (int i=0;i<Set_cnt;i++){
			if (func(24, SET_COMB[i], 4)>0){
				printf("true");
				fflush(stdout);
				jump_next = 1;
				break;
			}
		}
		if (jump_next == 1){
			continue;
		}

		printf("false");
		fflush(stdout);
	 }

	return 0;
}
