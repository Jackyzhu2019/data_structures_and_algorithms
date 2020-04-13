/*
 * chorus.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ZHU_JUN
 */


#include <stdio.h>
#define N 200
#define MAX(x,y) (x)>(y)?(x):(y)


int chorus(){
	int n;
	int i;
	int j;
	int height[N];
	int dp_inc[N]; // increasing subseq
	int dp_dec[N]; // decreasing subseq
	int chrusSeq[N]; // chorus subseq

	while(scanf("%d",&n) != EOF)
	{
		for(i = 0;i < n;i++)
		{
			scanf("%d",&height[i]);

			dp_inc[i] = 1;
			dp_dec[i] = 1;

			printf("%d. \n", height[i]);
			fflush(stdout);
		}

		for (i=0;i<n;i++){
			for(j=0;j<i;j++){
				if (height[j]<height[i]){
					dp_inc[i] = MAX(dp_inc[i], dp_inc[j]+1);
				}
			}
		}


		for (i=(n-1);i>=0;i--){
			for(j=n;j>i;j--){
				if (height[j]<height[i]){
					dp_dec[i] = MAX(dp_dec[i], dp_dec[j]+1);
				}
			}
		}

		for(i=0;i<n;i++){
			chrusSeq[i] = dp_inc[i] + dp_dec[i] - 1;
		}

		for (i=0;i<n;i++){
			printf("%d ", chrusSeq[i]);
			fflush(stdout);
		}
	}

	return 0;
}
