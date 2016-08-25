#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}stack;

stack *push(stack *top,int data)
{
	stack *temp = NULL;
	temp = (stack*) malloc(sizeof(stack));
	temp->data = data;
	if(top != NULL)
		temp->next = top;
	top = temp;
	return top;
}

stack *pop(stack *top)
{
	if(top == NULL)
		return top;
	stack *temp = NULL;
	temp = top->next;
	free(top);
	top = temp;
	return top;
}

int size(stack *top)
{
	if(top == NULL)
		return 0;
	int count = 0;
	stack *temp = NULL;
	temp = top;
	do
		count++;
	while((temp = (temp->next)));
	return count;
}

void print(stack *top)
{
	if(top == NULL)
		return;
	stack *temp = NULL;
	temp = top;
	do
		printf("%d ",temp->data);
	while((temp = (temp->next)));
}

int empty(stack *top)
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

int top(stack *top)
{
	return (top->data);
}

stack *flush(stack *top)
{
	stack *temp = NULL;
	temp = top;
	while(temp != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
	free(temp);
	top = NULL;
	return top;
}
#endif