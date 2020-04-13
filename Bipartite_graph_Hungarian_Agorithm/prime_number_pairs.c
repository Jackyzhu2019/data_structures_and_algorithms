/*
 * prime_number_pairs.c
 *
 *  Created on: Mar 4, 2020
 *      Author: ZHU_JUN
 */

/* This program use hungarian algorithm to find max number of prime number pairs. What is the prime number pairs?
 * 2, 5, its sum is 7 which is a prime number, so we call 2, 5 a prime number pairs.
 */


#include <stdio.h>
#include <math.h>
#define FOUND 1
#define NOT_FOUND 0
#define LEN 101
int EvenArray[LEN];
int OddArray[LEN];
int connection[LEN][LEN];
int Bused[LEN+1];
int Bassigned[LEN+1];



static int Is_A_Found_Matched_B(int i, int OddNum){
	int j;

	for (j=1;j<(OddNum+1);j++){
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
					if (Is_A_Found_Matched_B(Bassigned[j],OddNum)){
						Bassigned[j] = i;
						return FOUND;
					}
				}
			}
		}
	}

	return NOT_FOUND;
}


int isPrimePairs(int tmpX, int tmpY)
{
    int data = tmpX + tmpY;
    if (data <= 1)
        return 0;
    int loopNum = sqrt(data);
    for (int i = 2; i <= loopNum; i++)
    {
        if (data % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int prime_number_pairs(){
	int a;
	int N, i, j;
	int EvenNum;
	int OddNum;
	int even_idx, odd_idx;
	int num_of_match;

	while (scanf("%d", &N) != EOF)
	{
	//	printf("N:%d.\n", N);
	//	fflush(stdout);

		EvenNum=0;
		OddNum=0;
		if (N % 2 != 0)
			break;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &a);
		//	printf("%dth input data: %d\n", i, a);
		//	fflush(stdout);

			if (a % 2 == 0)
			{
				EvenArray[EvenNum++] = a;
			}
			else
			{
				OddArray[OddNum++] = a;
			}
		}

		memset(connection, 0, sizeof(connection));
		memset(Bassigned, 0, sizeof(Bassigned));

		for (even_idx=0;even_idx<EvenNum;even_idx++){
			for (odd_idx=0;odd_idx<OddNum;odd_idx++){
				connection[even_idx+1][odd_idx+1] = isPrimePairs(EvenArray[even_idx], OddArray[odd_idx]);
			}
		}

		num_of_match = 0;

		for (i=1;i<(EvenNum+1);i++){
			memset(Bused, 0, sizeof(Bused));
			if (Is_A_Found_Matched_B(i, OddNum)) num_of_match++;
		}

/*
		for (j=1;j<(OddNum+1);j++){
			printf("B%d, assigned to A%d. \n", j, Bassigned[j]);
			fflush(stdout);
		}
*/
		printf(" %d\n", num_of_match);
		fflush(stdout);
	}



	return 0;
}
