/*
 * hungarian_algorithm.c
 *
 *  Created on: Mar 4, 2020
 *      Author: ZHU_JUN
 */

/* This program implements the hungarian algorithm as described in
 * "bipartite_graph_Hungarian_Algorithm.docx"
 */

#include <stdio.h>
#define LEN_A 4
#define LEN_B 4
#define FOUND 1
#define NOT_FOUND 0

int Is_A_Found_Matched_B(int i);
void hungarian_algorithm();

int connection[LEN_A+1][LEN_B+1];
int Bused[LEN_B+1];
int Bassigned[LEN_B+1];


int Is_A_Found_Matched_B(int i){
	int j;

	for (j=1;j<(LEN_B+1);j++){
		if (connection[i][j]==1){
			if (Bused[j] == 1){
				continue;
			}

			if(Bused[j] == 0){
				Bused[j] = 1;

				if (Bassigned[j]==0){
					Bassigned[j] = i;
					return FOUND;
				}else {
					if (Is_A_Found_Matched_B(Bassigned[j])){
						Bassigned[j] = i;
						return FOUND;
					}
				}
			}



		}


	}


	return NOT_FOUND;
}


void hungarian_algorithm(){
	int i, j, k;
	int num_of_match = 0;

	for (i=0;i<(LEN_A+1);i++){
		for (j=0;j<(LEN_B+1);j++){
			printf("%d ",connection[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}

	for (i=1;i<(LEN_A+1);i++){
		memset(Bused, 0, sizeof(Bused));
		if (Is_A_Found_Matched_B(i)) num_of_match++;
	}
}

int test_hungarian_algorithm(){
	int j;

	memset(connection, 0, sizeof(connection));
	memset(Bassigned, 0, sizeof(Bassigned));
	connection[1][1] = 1;
	connection[1][2] = 1;
	connection[1][4] = 1;
	connection[2][2] = 1;
	connection[2][4] = 1;
	connection[3][2] = 1;
	connection[4][1] = 1;
	connection[4][2] = 1;


	hungarian_algorithm();

	for (j=1;j<(LEN_B+1);j++){
		printf("B%d, assigned to A%d. \n", j, Bassigned[j]);
		fflush(stdout);
	}



	return 0;
}
