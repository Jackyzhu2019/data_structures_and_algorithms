/*
 * LCS.c
 *
 *  Created on: Feb 26, 2020
 *      Author: ZHU_JUN
 */


/* This program demos the longest common subsequence */
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 200
#define MAX(x, y) (x)>(y)?(x):(y)

void calLCS(char *A, char *B, int lenA, int lenB){
	int C[MAX_STRING_LEN+1][MAX_STRING_LEN+1] = {0};
	int i, j, m;
	char _LCS[MAX_STRING_LEN];

	for (i=1;i<=lenB;i++){
		for (j=1;j<=lenA;j++){
			if (B[i] == A[j]){
				C[i][j] = C[i-1][j-1] + 1;
			} else {
				C[i][j] = MAX(C[i-1][j], C[i][j-1]);
			}
		}
	}

	printf("LCS len: C[%d][%d] = %d. \n", lenB, lenA, C[lenB][lenA]);
	fflush(stdout);

	// print LCS sequence
	i = lenB;
	j = lenA;
    m = 0;

	while(C[i][j]){
		if (C[i][j] == C[i][j-1]){
			j--;
		}else if (C[i][j] == C[i-1][j]){
			i--;
		}else if(C[i][j] == (C[i-1][j-1]+1)){
			_LCS[m++] = B[i-1];
			i--;
			j--;
		}
	}

	for (m=(C[lenB][lenA]-1);m>=0;m--){
		printf("%c %d\n", _LCS[m], m);
		fflush(stdout);
	}


}

int LCS(){
	char strA[MAX_STRING_LEN]; //= "BDCABA";
	char strB[MAX_STRING_LEN]; // = "ABCBDAB";
	int lenA;
	int lenB;

	gets(strA);
	gets(strB);

	lenA = strlen(strA);
	lenB = strlen(strB);

	printf("A: %s, len: %d. \n", strA, lenA);
	fflush(stdout);
	printf("B: %s, len: %d. \n", strB, lenB);
	fflush(stdout);

	calLCS(strA, strB, lenA, lenB);





	return 0;
}
