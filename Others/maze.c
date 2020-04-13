/*
 * maze.c
 *
 *  Created on: Mar 9, 2020
 *      Author: ZHU_JUN
 */



/*
 Maze Matrix
 0 1 0 0 0
 0 1 0 0 0
 0 0 0 0 0
 0 1 1 1 0
 0 0 0 1 0

 The robot start from (0, 0) and will find the path to the end (4, 4)
 The rule is that the robot can move through the axi with value 0.
 And it just can move right and down.
 Suppose it must exist one path to reach the end.
 */





#include <stdio.h>

#define M 5
#define N 5


typedef struct{
	int x;
	int y;
	int status;
}Node;


int maze(){
	int i, j;
	int maze[M+1][N+1];
	Node Nd[M*N];
	Node *pNd;
	int x_next, y_next;
	int x, y;

	for (i=0;i<M*N;i++){
		Nd[i].x = 0;
		Nd[i].y = 0;
		Nd[i].status = 2;
	}

	memset(maze, 0x0, (M+1)*(N+1)*sizeof(int));

	maze[1][0] = 1;
	maze[1][2] = 1;
	maze[1][4] = 1;
	maze[3][1] = 1;
	maze[3][3] = 1;
	maze[3][4] = 1;

	/* fill the boundary with 1 */
	for (i=0;i<=M;i++){
		maze[i][N] = 1;
	}

	for (i=0;i<=N;i++){
		maze[M][i] = 1;
	}

	i = 0;
	while(!((Nd[i].x == (M-1)) && (Nd[i].y == (N-1)))){ // there must exist a path to reach the end
		x = Nd[i].x;
		y = Nd[i].y;
		x_next = Nd[i].x + 1;
		y_next = Nd[i].y + 1;

		if ((maze[x_next][y] == 1) && (maze[x][y_next] == 1)){
			Nd[i].status = 2;
			i--;
			continue;
		}

		if ((maze[x_next][y] == 0) && (maze[x][y_next] == 0)){
			if (Nd[i].status == 2){
				Nd[i+1].x = x_next;
				Nd[i+1].y = y;
				Nd[i].status--;
				i++;
			}else if (Nd[i].status == 1){
				Nd[i+1].x = x;
				Nd[i+1].y = y_next;
				Nd[i].status--;
				i++;
			}else{
				Nd[i].status = 2;
				i--;
			}

			continue;
		}

		if ((maze[x][y_next] == 0) && (maze[x_next][y] != 0)){
			if (Nd[i].status==2){
				Nd[i+1].x = x;
				Nd[i+1].y = y_next;
				Nd[i].status--;
				i++;
			}else {
				Nd[i].status = 2;
				i--;
			}
			continue;
		}

		if ((maze[x][y_next] != 0) && (maze[x_next][y] == 0)){
			if (Nd[i].status==2){
				Nd[i+1].x = x_next;
				Nd[i+1].y = y;
				Nd[i].status--;
				i++;
			}else {
				Nd[i].status = 2;
				i--;
			}
			continue;
		}
	}

	for (j=0;j<i;j++){
		printf("x=%d y= %d.\n", Nd[j].x, Nd[j].y);
		fflush(stdout);
	}
	printf("quit the maze! \n");
	fflush(stdout);

	return 0;
}
