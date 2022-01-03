/* FTREE.C : Fractal tree           */
/*                                  */
/*                PGMD by TH        */
#include <stdio.h>
#include <bios.h>
#include <graphics.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void fixed_tree(int n, int length, float angle) {
	int dx, dy;
	dx = (float)length * sin(angle);
	dy = (float)length * cos(angle);
	if ( n > 0) setcolor(LIGHTRED);
	else setcolor(LIGHTGREEN);
	linerel(-dx, -dy);
	if(n > 0) {
		fixed_tree(n-1, (float)length * 0.8, angle + 0.5);
		fixed_tree(n-1, (float)length * 0.8, angle - 0.5);
	}
	moverel(dx, dy);
}

void random_tree(int n, int length, float angle) {
	int dx, dy;
	float turn1, turn2, scale;
	dx = (float)length * sin(angle);
	dy = (float)length * cos(angle);
	turn1 = (float)rand() / (float)RAND_MAX;
	turn2 = (float)rand() / (float)RAND_MAX;
	scale = (float)rand() / (float)RAND_MAX / 5.0 + 0.7;

	if(n > 0) setcolor(LIGHTRED);
	else setcolor(LIGHTGREEN);

	linerel(-dx, -dy);
	if(n > 0) {
		random_tree(n-1, (float)length * scale, angle +turn1);
		random_tree(n-1, (float)length * scale, angle -turn2);
	}
	moverel(dx, dy);
}

void main(void) {
	int order;
	int gd = DETECT, gm;
	printf("\nEnter tree order --> ");
	scanf("%d", &order);

	initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
	if(graphresult() != grOk) {
		printf("\nGraphic system error!");
		exit(1);
	}
	setcolor(WHITE);
	outtextxy(0, 10, "Fixed Tree");
	moveto(getmaxx()/2, getmaxy() );
	fixed_tree(order, 100, 0.0);
	getch();
	cleardevice();

	randomize();
	outtextxy(0, 10, "Random  tree");
	moveto(getmaxx()/2, getmaxy());
	random_tree(order, 100, 0.0);
	getch();
	closegraph();
}