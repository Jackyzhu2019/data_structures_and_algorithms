/*
 * axis_move.c
 *
 *  Created on: Feb 11, 2020
 *      Author: ZHU_JUN
 */

#include <stdio.h>
#include <string.h>
#define True 1
#define False 0

static int X = 0;
static int Y = 0;

int isAxisVld(char *inputAxis, int len){
	if ((len < 2) || (len >3))
		return False;


	if ((inputAxis[1] > '9') || (inputAxis[1] < '0'))
		return False;

	if (len == 3){
		if ((inputAxis[2] > '9') || (inputAxis[2] < '0'))
				return False;
	}

	if ((inputAxis[0] == 'A') || (inputAxis[0] == 'D') || (inputAxis[0] == 'W') || (inputAxis[0] == 'S'))
			return True;


	return False;
}


void calFinalAxis(char *inputAxis, int len){
	int value;

	if (len == 2){
		value = inputAxis[1] - '0';
	}

	if (len == 3){
		value = (inputAxis[1] - '0') * 10 + (inputAxis[2] - '0');
	}

	//printf("value: %d. \n", value);
	//		fflush(stdout);

	switch (inputAxis[0]){
		case 'A':
				X -= value; break;
		case 'D':
				X += value; break;
		case 'W':
				Y += value; break;
		case 'S':
				Y -= value; break;
		default:
				break;
	}
}


int axis_move(){
	char str[200];// = "A23;";
	int strLen;
	int i, j;
	char oneAxis[200];

	gets(str);
	strLen = strlen(str);

	//printf("str: %s. Len: %d. \n", str, strLen);
	//fflush(stdout);

	j = 0;
	for (i=0;i<strLen;i++){
		if (str[i] == ';'){
			if (isAxisVld(oneAxis, j)){
				calFinalAxis(oneAxis, j);
			}

			j = 0;
		}else{
			oneAxis[j++] = str[i];
		}
	}

	//printf("X: %d. Y: %d. \n", X, Y);
	//	fflush(stdout);


	printf("%d, %d", X, Y);
	fflush(stdout);

	return 0;
}
