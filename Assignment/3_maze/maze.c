#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "maze.h"
/*
 * Queue is part of Breadth First Search
 *
 * Algorithm ;
 *	. Given a starting point,
 *	a.) Travel to all adjacent places, mark these locations as being 1 step away
 *	from starting point
 *	b.) For each location that is 1 step away, visit all adjacent points that are not
 *	visited, mark these locations as being two steps away.
 *	c.) Repeat until one of the spots you mark is the exit
 */

struct stack * alloc(int x, int y ){
	struct stack * new = (struct stack *) malloc(sizeof(struct stack));
	new->next = NULL ;
	new->coord[0] = x ;
	new->coord[1] = y ;
	return new ;
}

struct stack * push(struct stack * root, struct stack * newTop){
	if ( root==NULL){
		root = newTop ;
		return root ;
	}
	else{
		newTop->next = root ;
		return newTop ;
	}
}

struct stack * pop(struct stack ** root){
	struct stack * popped = (*root);
	(*root)=(*root)->next;
	popped->next = NULL ;
	return popped ;
}

struct stack * popBottom(struct stack ** root){
    if ((*root)==NULL) return NULL ;
    else{
        if ( (*root)->next->next == NULL ){
            struct stack * bottom = (*root)->next;
            (*root)->next = (*root)->next->next ;
            return bottom ;
        }
        return popBottom(&((*root)->next));
    }
}

struct stack * getBottomPtr(struct stack ** root){
	if ( (*root)->next->next == NULL ){
		struct stack * bottom = (*root)->next;
		return bottom ;
	}
    return getBottomPtr(&((*root)->next));
}

void printnext(struct stack ** root){
	if ( *root!=NULL ){
		if ( (*root)->next == NULL ) printf("\e[38;5;26m(%d %d)\e[0m\n",(*root)->coord[0],(*root)->coord[1]);
		else{
			printf("(%d %d)",(*root)->coord[0],(*root)->coord[1]);
			printnext(&((*root)->next));
		}
	}
	else{
		printf("");
	}
}

void print(struct stack ** root){
	printf("\e[38;5;26m(%d %d)\e[0m",(*root)->coord[0],(*root)->coord[1]);
	printnext(&((*root)->next));
}

