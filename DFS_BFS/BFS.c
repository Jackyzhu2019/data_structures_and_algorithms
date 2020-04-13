/*
 * BFS.c
 *
 *  Created on: Apr 2, 2020
 *      Author: ZHU_JUN
 */


/* This program implements the BFS (breadth first search) algorithm. */

#include <stdio.h>

int BFS_queue(int argc, char **argv){
	char item[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	int relation[6][6] = {
			{0, 1, 1, 0, 0, 0}, // A connect to B and C
			{1, 0, 0, 1, 0, 0}, // B connect to A and D
			{1, 0, 0, 1, 1, 0}, // C connect to A, D, E
			{0, 1, 1, 0, 0, 1}, // D connect to B, C, F
			{0, 0, 1, 0, 0, 0}, // E connect to C
			{0, 0, 0, 1, 0, 0}  // F connect to D
	};

	char queue[6];
	char outQueue[6];
	int i;
	char outChar;
	int j, k, m;
	int exist;
	int queue_idx;

	queue[0] = item[0];
	queue_idx = 0;
	i = 1;

	while(queue_idx<i){
		outChar = queue[queue_idx++];

		for (j=0;j<6;j++){
			if (relation[outChar - 'A'][j] == 1){
				exist = 0;
				for (k=0;k<i;k++){
					if (item[j] == queue[k]){
						exist = 1;
					}
				}

				if (exist == 0){
					queue[i] = item[j];
					i++;
				}
			}
		}


		printf("%c \n", outChar);
		fflush(stdout);

	}

	return 0;
}




