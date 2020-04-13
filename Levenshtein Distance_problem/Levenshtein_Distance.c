/*
 * Levenshtein_Distance.c
 *
 *  Created on: Apr 11, 2020
 *      Author: ZHU_JUN
 */

/* This program implements Levenshtein Distance */
#include <stdio.h>

int Levenshtein_Dist(int argc, char **argv){
	char string1[5] = "abcde";
	char string2[6] = "ghacee";
	int i, j;
	int dp[6][7];
	int temp, temp1, temp2, temp3;

	for (i=0;i<6;i++){
		dp[i][0] = i;
	}

	for(j=0;j<7;j++){
		dp[0][j] = j;
	}

	for(i=1;i<6;i++){
		for (j=1;j<7;j++){
			temp1 = dp[i-1][j] + 1;
			temp2 = dp[i][j-1] + 1;
			if (string1[i-1] == string2[j-1]){
				temp3 = dp[i-1][j-1];
			}else{
				temp3 = dp[i-1][j-1]+1;
			}

			if (temp1>temp2){
				temp1 = temp2;
			}

			if (temp3<temp1){
				temp1 = temp3;
			}

			dp[i][j] = temp1;
		}
	}

	printf("dp[%d][%d] = %d \n", i-1, j-1, dp[i-1][j-1]);
	fflush(stdout);

	return 0;
}

