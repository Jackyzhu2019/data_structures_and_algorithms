/*
 * shopping_list.c
 *
 *  Created on: Feb 8, 2020
 *      Author: ZHU_JUN
 */

/*
	This program give an example about pack problem with dependency.
	For example:
		1500 7
		500 1 0
		400 4 0
		300 5 2
		400 5 2
		200 5 0
		500 4 0
		400 4 0

	The first line is the cost when purchasing, and the number of items.
	The following lines are the details about items.
	price, value, dependency.
	for instance, "300 5 2", 300 is the item price, 5 is its value,
	2 is its dependency, if we want to buy this item, we should buy a master
	item first, the master item is the second item in the list.

	The problem is to choose the item combinations to maximize the price * value.

	In this example, we choose item list:
	400 4 0
	300 5 2
	400 5 2
	400 4 0

	where 400 + 300 + 400 + 400 <= 1500
	and 400 * 4 + 300 * 5 + 400 * 5 + 400 *4 = 6700 is the maximum value.
*/



#include <stdio.h>
#include <string.h>
#define max(x,y) (x)>(y)?(x):(y)

int shopping_list(){
	int N;
	int m;
	int i, j, n, t;
	int k=0;
	int v, p, q;
	int price[60][3] = {0}; // price
	int degree[60][3] = {0}; // importance degree
	int dp[60][3200] = {0};
	int op1, op2, op3, op4;

	scanf("%d %d", &N, &m);

	for(i=0;i<m;i++){
		scanf("%d %d %d", &v, &p, &q);

		p = p * v;
		v = v / 10;

		if(q == 0){
			price[i][0] = v;
			degree[i][0] = p;
			//k++;
		}else if(price[q-1][1] == 0){
			price[q-1][1] = v;
			degree[q-1][1] = p;
		}else{
			price[q-1][2] = v;
			degree[q-1][2] = p;
		}
	}

	N = N/10;
	j = 0;

	for(i=0;i<m;i++){
		if (price[i][0] == 0)
			continue;

		j++;
		for (n=0;n<=N;n++){
			op1 = price[i][0];
			op2 = price[i][0] + price[i][1];
			op3 = price[i][0] + price[i][2];
			op4 = price[i][0] + price[i][1] + price[i][2];

/*			if (n <= op1){
				dp[j][n] = dp[j-1][n];
			}else if (n <= op2){
				dp[j][n] = Max(dp[j-1][n], dp[j-1][n-op1] + degree[i][0]);
			}else if (n <= op3){
				dp[j][n] = Max(dp[j-1][n], dp[j-1][n-op1]);

			}else if (n <= op4){

			}else{
				dp[j][n] = Max(dp[j-1][n], dp[j-1][n-op1] + degree[i][0]);
				dp[j][n] = Max(dp[j][n], dp[j-1][n-op2] + degree[i][0] + degree[i][1]);
				dp[j][n] = Max(dp[j][n], dp[j-1][n-op3] + degree[i][0] + degree[i][2]);
				dp[j][n] = Max(dp[j][n], dp[j-1][n-op4] + degree[i][0] + degree[i][1] + degree[i][2]);
			}
*/
			if (n>=op1){
				t = max(dp[j-1][n], dp[j-1][n-op1] + degree[i][0]);
				if (t>dp[j][n])
					dp[j][n] = t;
			}

			if (n>=op2){
				t = dp[j-1][n-op2] + degree[i][0] + degree[i][1];
				if (t>dp[j][n])
					dp[j][n] = t;
			}

			if (n>=op3){
				t = dp[j-1][n-op3] + degree[i][0] + degree[i][2];
				if (t>dp[j][n])
					dp[j][n] = t;
			}

			if (n>=op4){
				t = dp[j-1][n-op4] + degree[i][0] + degree[i][1] + degree[i][2];
				if (t>dp[j][n])
					dp[j][n] = t;
			}


		}
	}
#if 0
	printf("N=%d m=%d.j=%d. \n", N, m, j);
	fflush(stdout);

	for (k=0;k<=N;k++){
		printf("%d \t", k);
		fflush(stdout);

	}
	printf("\n");
	fflush(stdout);

	for (k=0;k<=j;k++){
		for (i=0;i<=N;i++){
			printf("%d \t", dp[k][i]);
			fflush(stdout);
		}
	    printf("\n");
	    fflush(stdout);
	}
#endif
	printf("%d", dp[j][N]);
	fflush(stdout);

	return 0;
}
