/*
 * LPS_manacher.c
 *
 *  Created on: Apr 3, 2020
 *      Author: ZHU_JUN
 */


/* This program implements the manacher algorithm for solving longest palindromic subsequence (LPS).
 * “baaab” is called LPS of string "abaaab"
 */

#include <stdio.h>
#include <string.h>
#define STR_LEN 100
int INIT(char *st, char *tmp, int len){
	int i;

	for(i=0;i<2*len;i+=2)
	{
		tmp[i]='#';
		tmp[i+1]=st[i/2];
	}
	tmp[2*len]='#';
	return 2*len+1;
}

int Manacher(char *string, int len){
	int P0, P, i, left, right, Temp_Len;
	int Len[STR_LEN<<1 + 1];
    int max;

	P0 = 0;
	P = 0;
	Len[0] = 1;
	//memset((void *)Len, 1, 100 * sizeof(int));

	for (i=0;i<(STR_LEN<<1+1);i++){
		Len[i] = 1;
	}

	for (i=1;i<len;i++){
		if (P<=i){
			left = i;
			right = i;
			while(string[--left] == string[++right]){
				Len[i]++;
			}

			P0 = i;
			P = P0 + Len[i];
		}else{
			Temp_Len = Len[2*P0 - i];
			if (Temp_Len >= (P-i)){
				Len[i] = P-i;
				left = 2*i-P;
				right = P;

				while(string[left--] == string[right++]){
					Len[i]++;
				}
			}else{
				Len[i] = Temp_Len;
			}
		}
	}

    max = Len[0];
	for (i=0;i<len;i++){
		//printf("%d ", Len[i]);
		//fflush(stdout);
        if (max < Len[i]){
            max = Len[i];
        }
	}

    return max;
}



int Manacher_main(int argc, char **argv){
	char string[STR_LEN];
	char tmp[STR_LEN<<1 + 1];
	int len_ext;
	int len;
    int max;

    gets(string);
    len = strlen(string);


	len_ext = INIT(string, tmp, len);
/*
	printf("%s.\n", string);
	fflush(stdout);
	printf("%s.\n", tmp);
	fflush(stdout);
*/

	max = Manacher(tmp, len_ext);

    printf("%d", max-1);

	return 0;
}
