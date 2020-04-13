/*
 * DFS.c
 *
 *  Created on: Mar 29, 2020
 *      Author: ZHU_JUN
 */
#include <stdio.h>

/* This program implements deep first search (DFS) algorithm. */

int BFS_Heap(int argc, char **argv){
	char item[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	int relation[6][6] = {
			{0, 1, 1, 0, 0, 0}, // A connect to B and C
			{1, 0, 0, 1, 0, 0}, // B connect to A and D
			{1, 0, 0, 1, 1, 0}, // C connect to A, D, E
			{0, 1, 1, 0, 0, 1}, // D connect to B, C, F
			{0, 0, 1, 0, 0, 0}, // E connect to C
			{0, 0, 0, 1, 0, 0}  // F connect to D
	};

	char stack[6];
	char outQueue[6];
	int i;
	char outChar;
	int j, k, m;
	int exist;

	stack[0] = item[0];
	i = 1;
	m = 0;

	while(i!=0){
		outChar = stack[i-1];
		i--;
		outQueue[m++] = outChar;

		for (j=0;j<6;j++){
			if (relation[outChar - 'A'][j] == 1){
				exist = 0;
				for (k=0;k<i;k++){
					if (item[j] == stack[k]){
						exist = 1;
					}
				}

				for (k=0;k<m;k++){
					if (item[j] == outQueue[k]){
						exist = 1;
					}
				}

				if (exist == 0){
					stack[i] = item[j];
					i++;
				}
			}
		}


		printf("%c \n", outChar);
		fflush(stdout);

	}



	return 0;
}
