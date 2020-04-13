/*
 * string_01.c
 *
 *  Created on: Jan 12, 2020
 *      Author: ZHU_JUN
 */

/*
	This program sorts sequences by dictionary order. For example,
	this
	abort
	my


	Output:
	abort
	my
	this

	The main idea is to use strcmp() to do comparison.
*/

#include <stdio.h>
#include <string.h>

int main(){
	int N, i, j;
	char str[1000][100];
	char temp[100];

	scanf("%d\n", &N);

	for (i=0;i<N;i++){
		//str[i] = malloc(100 * sizeof(char));
		gets(str[i]);
		//printf("i: %d %s \n", i, str[i]);
		//fflush(stdout);
	}

	for (i=0;i<N;i++)
	{
		for (j=0;j<(N-1-i);j++){
			if (strcmp(str[j], str[j+1])>0){
				strcpy(temp, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j], temp);
			}
		}
	}


	for (i=0;i<N;i++)
	{
		printf("%s\n", str[i]);
		fflush(stdout);
	}


	return 0;
}
