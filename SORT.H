/*  SORT.H : Sorting Lib Header  */
/*                               */
/*                  pgmd by TH   */

#ifndef _SORT_H
#define _SORT_H

extern int top;
extern int far *stack;

typedef int (*FCMP)(const void*, const void*);

#define init_stack()	(top = -1)
#define push(t)		(stack[++top] = t)
#define pop()		(stack[top--])
#define is_stack_empty()	(top < 0)

int make_stack(void);
void remove_stack(void);

void select_sort(void *base, size_t nelem, size_t width, FCMP fcmp);


#endif