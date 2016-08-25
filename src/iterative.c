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
	//pushing data into source stack 
	for(i=numOfDisks;i>=1;i--)
		source = push(source,i);

	//if number of disks id even then source and des are used first, if odd then source and aux are used first
	if(numOfDisks%2 == 0)
		diskMove(source,dest,aux,moves);
	else
		diskMove(source,aux,dest,moves);

	printf("\n\n");
}

//function to calculate power of a number
long long int power(int a,int b)
{
	int i;
	long long int powe = 1;
	for(i=0;i<b;i++)
		powe *= a;
	return powe;
}

//function to move the disks from source to destination
void diskMove(stack *source,stack *aux,stack *dest,long long int moves)
{
	long long int i;
	char s,d;
	int move_check,temp;

	for(i=1;i<=moves;i++)
		switch(i%3)
		{
			//in 1st,4th ,10th ,....3(n)+1 cases disk is exchanged b/w source and destination according to the rules
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
			//in 2nd,3rd ,4th ,....3(n)+2 cases disk is exchanged b/w source and auxiliary according to the rules
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
			////in 3rd,6th ,9th ,....3(n) cases disk is exchanged b/w auxiliary and destination according to the rules
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


//function to exchange disk b/w stacks according to the rules of tower of hanoi
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
