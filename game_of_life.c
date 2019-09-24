/*****************************************/
/** << game of life >>                  **/
/**                                     **/
/**                                     **/
/** purpose: test for streami           **/
/**                                     **/
/** dev start date: 2019-09-21          **/
/** update date   : 2019-09-24          **/
/** version       : 0.9                 **/
/** author	  : K.Taehyung          **/
/**                                     **/
/*****************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

int BOARD_HEIGHT=40, BOARD_WIDTH=80;

/* initialize values when argument is none */
void init_val(int board[][BOARD_WIDTH]) {
	/* default initial board values */
	/* glider */
	board[3][3] = 1;
	board[4][4] = 1; board[4][5] = 1; 
	board[5][3] = 1; board[5][4] = 1;
}

/* initialize BOARD matrix values(default:0) */
void init_board_val(int board[][BOARD_WIDTH]) {
	int i, j=0;
	for(i=0; i<BOARD_HEIGHT; i++)
		for(j=0; j<BOARD_WIDTH; j++)
			board[i][j] = 0;
}

/* print board */
void print_board(int board[][BOARD_WIDTH]) {
	int i, j=0;
	for(i=0; i<BOARD_HEIGHT; i++) {
		for(j=0; j<BOARD_WIDTH; j++)
			if(board[i][j] == 0)
				printf(".");
			else if(board[i][j] ==1)
				printf("*");
		printf("\n");
	}
} 

/* dump board (making result.txt) */
void dump_board(int board[][BOARD_WIDTH]) {

	FILE *pF_w=NULL;
	int i, j=0;

	pF_w = fopen("./result.txt", "w");
	if( pF_w == NULL ) {

		fprintf(stderr, "File open Error..\n");

	} else {

		for(i=0; i<BOARD_HEIGHT; i++) {
			for(j=0; j<BOARD_WIDTH; j++)
				if(board[i][j] == 0)
					fprintf(pF_w, ".");
				else if(board[i][j] ==1)
					fprintf(pF_w, "*");
			fprintf(pF_w, "\n");
		}
	}

	fclose(pF_w);

} 

/* check Neighbour cell */
int check_neighbour(int board[][BOARD_WIDTH], int i, int j) {
	int count_n = 0;
	int w, h, k, l;
	for(k=-1; k<2; k++) {
		h = i + k;	
		if(!(h < 0 || h > BOARD_HEIGHT)) {
			for(l=-1; l<2; l++) {
				w = j + l;	
				if(!(w < 0 || w > BOARD_WIDTH)) {
					if(k == 0 && l== 0)
						continue;
					else if(board[h][w] == 1)
						count_n++;								
				}
			}
		}
	}

	return count_n;
}

/************************************************/
/* operate next step           			*/
/*   around "1" count : 			*/
/*   		1 or over 4	: alive-> die	*/
/*   		2 or 3     	: alive->alive	*/
/*   		3 		: die->alive 	*/
/************************************************/
void next_operation(int board[][BOARD_WIDTH]) {
	int board_new[BOARD_HEIGHT][BOARD_WIDTH];
	int i, j, count = 0;
	for(i=0; i<BOARD_HEIGHT; i++) {
		for(j=0; j<BOARD_WIDTH; j++) {

			count =	check_neighbour(board, i, j);

			if(count == 2) 
				board_new[i][j] = board[i][j];
			else if(count == 3)
				board_new[i][j] = 1;
			else if(count < 2 || count > 3)
				board_new[i][j] = 0;

		}
	}

	for(i=0; i<BOARD_HEIGHT; i++)
		for(j=0; j<BOARD_WIDTH; j++)
			board[i][j] = board_new[i][j];
}


/********************************************************/
/* main logic            				*/
/*   argument counts : 					*/
/*   		none	: board random(min 40*80)	*/
/*   		1  	: read plus.txt			*/
/*   		2 	: read plus.txt & n gerneration	*/
/********************************************************/
void main(int argc, char* argv[]) {

	int i, j=0;
	int z, x, y;
	int gen_cnt=0;
	char buf[1024];

	FILE *pF_r=NULL;

	if(argc == 1) {

		/* randomize board status: considering */
		/* terminal size, (default) + 0~19     */
		srand(time(NULL));
		BOARD_HEIGHT += rand()%20; BOARD_WIDTH += rand()%20;

	}else if(argc == 2 || argc ==3) {

		pF_r = fopen(argv[1], "r");
		if( pF_r == NULL ) {

			printf("File open Error..\n");

		} else {

			fscanf(pF_r, "%d", &BOARD_HEIGHT);
			fscanf(pF_r, "%d", &BOARD_WIDTH);

		}

	}else {

		fprintf(stderr, "Usage: gol <config filename>(option) <generation count>(option)");

	}

	/* board decrare and initialize */
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	init_board_val(board);

	if(argc == 1) {

		init_val(board);

	}else if(argc == 2 || argc == 3) {

		fscanf(pF_r, "%d", &z);
		for(i=0; i < z ; i++) {
			fscanf(pF_r, "%d", &x);
			fscanf(pF_r, "%d", &y);
			board[x][y] = 1;
		}
		fclose(pF_r);

	}

	if(argc == 1 || argc == 2) {

		while(1) {

			puts("\033[H\033[J");
			print_board(board);
			next_operation(board);

			usleep(200000);

		}

	}else if(argc == 3) {

		gen_cnt = atoi(argv[2]);

		for(i=0; i < gen_cnt; i++)
			next_operation(board);

		dump_board(board);

	}

}
