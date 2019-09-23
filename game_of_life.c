/*****************************************/
/** game of life                        **/
/** :                                   **/
/**                                     **/
/** purpose: test for streami           **/
/**                                     **/
/** dev start date: 2019-09-21          **/
/** update date   :                     **/
/** version       : 0.1                 **/
/**                                     **/
/**                                     **/
/*****************************************/

#include <stdio.h>
#include <unistd.h>

#define BOARD_HEIGHT	40
#define BOARD_WIDTH	80

/* initialize BOARD matrix values */
void init_val(int board[][BOARD_WIDTH]) {
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
				printf("_");
			else if(board[i][j] ==1)
				printf("+");
		printf("\n");
	}
}

/* check Neibour cell */
int check_neibour(int board[][BOARD_WIDTH], int i, int j) {
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

/* operate next step           			*/
/*   around "1" count : 			*/
/*   		1 or over 4	: alive-> die	*/
/*   		2 or 3     	: alive->alive	*/
/*   		3 		: die->alive 	*/
void next_operation(int board[][BOARD_WIDTH]) {
	int board_new[BOARD_HEIGHT][BOARD_WIDTH];
	int i, j, count = 0;
	for(i=0; i<BOARD_HEIGHT; i++) {
		for(j=0; j<BOARD_WIDTH; j++) {
			count =	check_neibour(board, i, j);
			if(count == 2) 
				board_new[i][j] = board[i][j];
			else if(count == 3)
				board_new[i][j] = 1;
			else if(count < 2 || count > 3)
				board_new[i][j] = 0;
#if	0
			if(board_new[i][j] == 1)
				printf("[%d][%d] check result = %d\n", i, j, count);
#endif
		}
	}

	for(i=0; i<BOARD_HEIGHT; i++)
		for(j=0; j<BOARD_WIDTH; j++)
			board[i][j] = board_new[i][j];
}

void main() {
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	int i, j=0;


	/* board initialize */
	init_val(board);

	board[19][40] = 1;
	board[20][40] = 1;
	board[21][40] = 1;
	board[20][39] = 1;
	board[20][41] = 1;

#if 0
	for(i=0; i<BOARD_HEIGHT; i++) {
		for(j=0; j<BOARD_WIDTH; j++) {
			if(board[i][j] == 0) {
				printf("0");
			}else if(board[i][j] == 1) {
				printf("1");
			}
				printf("%1d", board[i][j]);

		}
		printf("\n");
	}
#else
	for(i=0; i<20; i++) {
		puts("\033[H\033[J");
		print_board(board);
		next_operation(board);

		sleep(1);

//		printf("\n\n\n\n\n");
	}
#endif
}
