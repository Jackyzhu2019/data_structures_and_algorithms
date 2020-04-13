/*
 * Inverse_Polish_Notation.c
 *
 *  Created on: Apr 7, 2020
 *      Author: ZHU_JUN
 */


/* This program implements Inversion Polish Notation */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 100

char stack[STR_LEN];
int queue[STR_LEN];
int queue_op[STR_LEN];

int stack_cal[STR_LEN];


int Inverse_Polish_Notation(int argc, char **argv){
	char string[STR_LEN] = "4+4+{3+5*4/[44-(32+2)]}";
	int len;
	int i=0;
	int stack_cnt=0;
	int queue_cnt=0;
	int temp_num;
	char *p;
	char op;
    //gets(string);
    len = strlen(string);

    printf("%s, len: %d. \n", string, len);
    fflush(stdout);

    memset(queue_op, 0x0, STR_LEN * sizeof(int));
    /* Step 1: convert the math equation to IPN*/
    for (i=0;i<len;i++){
    	if (isdigit(string[i])){
    		temp_num = strtoul(&string[i], &p, 10); // over 10 in decimal
    		i = p-1-string;
    		queue[queue_cnt++] = temp_num;

    	//	printf("temp_num: %d, i: %d. \n", temp_num, i);
    	//	fflush(stdout);
    	}

    	if ((string[i]=='(') || (string[i]=='[') || (string[i]=='{') || (string[i]=='*') || (string[i]=='/')){
    		stack[stack_cnt++] = string[i];
    	}


    	if (string[i]==')'){
    		while(stack[stack_cnt-1] != '('){
    			queue_op[queue_cnt] = 1;
    			queue[queue_cnt++] = stack[stack_cnt-1];
    			stack_cnt--;
    		}
    		stack_cnt--;
    	}


    	if (string[i]==']'){
    		while(stack[stack_cnt-1] != '['){
    			queue_op[queue_cnt] = 1;
    			queue[queue_cnt++] = stack[stack_cnt-1];
    			stack_cnt--;
    		}
    		stack_cnt--;
    	}


    	if (string[i]=='}'){
    		while(stack[stack_cnt-1] != '{'){
    			queue_op[queue_cnt] = 1;
    			queue[queue_cnt++] = stack[stack_cnt-1];
    			stack_cnt--;
    		}
    		stack_cnt--;
    	}


    	if ((string[i]=='+') || (string[i]=='-')){
    		while ((stack[stack_cnt-1] == '*') || (stack[stack_cnt-1] == '/')){
    			queue_op[queue_cnt] = 1;
    			queue[queue_cnt++] = stack[stack_cnt-1];
    			stack_cnt--;
    		}
			stack[stack_cnt++] = string[i];
    	}
    }

    while(stack_cnt>0){
    	if ((stack[stack_cnt-1] != '(') || (stack[stack_cnt-1] != '[') || (stack[stack_cnt-1] != '{')){
			queue_op[queue_cnt] = 1;
    		queue[queue_cnt++] = stack[stack_cnt-1];
    	}
    	stack_cnt--;
    }


    for (i=0;i<queue_cnt;i++){
    	if (queue_op[i] == 0){
    		printf("%d ",queue[i]);
    		fflush(stdout);
    	}else {
    		printf("%c ",queue[i]);
    		fflush(stdout);
    	}
    }


    /* Calculate value from IPN */
    stack_cnt = 0;
    for (i=0;i<queue_cnt;i++){
    	if (queue_op[i] == 0){
    		stack_cal[stack_cnt++] = queue[i];
    	}else{
    		op = queue[i];
    		switch (op){
				case '+': temp_num = stack_cal[stack_cnt-2]+stack_cal[stack_cnt-1]; break;
				case '-': temp_num = stack_cal[stack_cnt-2]-stack_cal[stack_cnt-1]; break;
				case '*': temp_num = stack_cal[stack_cnt-2]*stack_cal[stack_cnt-1]; break;
				case '/': temp_num = stack_cal[stack_cnt-2]/stack_cal[stack_cnt-1]; break;
    		}

    		stack_cnt -= 2;
    		stack_cal[stack_cnt++] = temp_num;
    	}
    }

    printf("\n %d \n", stack[0]);
    fflush(stdout);

    return 0;
}
