#include "../include/stack.h"
#include <stdio.h>

long long int power(int a,int b);
void diskMove(stack *source,stack *aux,stack *dest,long long int moves);
int movement(stack **a,stack **b);

void iterative(int numOfDisks)
{
	stack *source = NULL,*aux = NULL,*dest = NULL;

	long long int moves = power(2,numOfDisks)-1;
	int i;

	printf("Transferring disks using iterative method :\n");

	for(i=numOfDisks;i>=1;i--)
		source = push(source,i);

	if(numOfDisks%2 == 0)
		diskMove(source,dest,aux,moves);
	else
		diskMove(source,aux,dest,moves);

	printf("\n\n");
}

long long int power(int a,int b)
{
	int i;
	long long int powe = 1;
	for(i=0;i<b;i++)
		powe *= a;
	return powe;
}

void diskMove(stack *source,stack *aux,stack *dest,long long int moves)
{
	long long int i;
	char s,d;
	int move_check,temp;

	for(i=1;i<=moves;i++)
		switch(i%3)
		{
		case 1:	if(empty(source))
					temp = dest->data;
				else if(empty(dest))
					temp = source->data;
				else
					temp = (dest->data) > (source->data) ? (source->data) : (dest->data);

				move_check = movement(&source,&dest);
				if(move_check)
				{
					s = 'A';
					d = 'C';
				}
				else
				{
					s = 'C';
					d = 'A';
				}
				printf("[%3lld] Move disk %d from Peg %c -> %c\n",i,temp,s,d);
			break;
		case 2:	if(empty(source))
					temp = aux->data;
				else if(empty(aux))
					temp = source->data;
				else
					temp = (aux->data) > (source->data) ? (source->data) : (aux->data);

				move_check = movement(&source,&aux);
				if(move_check)
				{
					s = 'A';
					d = 'B';
				}
				else
				{
					s = 'B';
					d = 'A';
				}
				printf("[%3lld] Move disk %d from Peg %c -> %c\n",i,temp,s,d);
			break;
		case 0:	if(empty(dest))
					temp = aux->data;
				else if(empty(aux))
					temp = dest->data;
				else
					temp = (aux->data) > (dest->data) ? (dest->data) : (aux->data);

				move_check = movement(&aux,&dest);
				if(move_check)
				{
					s = 'B';
					d = 'C';
				}
				else
				{
					s = 'C';
					d = 'B';
				}
				printf("[%3lld] Move disk %d from Peg %c -> %c\n",i,temp,s,d);
			break;
		}
}

int movement(stack **a,stack **b)
{
	int temp1,temp2;
	temp1 = ((*a)!=NULL) ? ((*a)->data) : 0;
	temp2 = ((*b)!=NULL) ? ((*b)->data) : 0;

	if(temp1 == 0)
	{
		(*a) = push((*a),temp2);
		(*b) = pop(*b);
		return 0;
	}
	else if(temp2 == 0)
	{
		(*b) = push((*b),temp1);
		(*a) = pop(*a);
		return 1;
	}
	else if(temp1 > temp2)
	{
		(*a) = push((*a),temp2);
		(*b) = pop(*b);
		return 0;
	}
	else if(temp2 > temp1)
	{
		(*b) = push((*b),temp1);
		(*a) = pop(*a);
		return 1;
	}
	else
		return -1;
}
