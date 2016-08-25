#include <stdio.h>

void diskMoveR(int numOfDisks,char source,char dest,char aux)
{
	static long long int count = 0;
	if(numOfDisks == 1)// base case (in case of number of disks = 1 ,just shift the disk to another pile)
		printf("[%3lld] Move disk %d from Peg %c -> %c\n",++count,numOfDisks,source,dest);
	else
	{
		diskMoveR(numOfDisks-1,source,aux,dest);//function calling itself again and again 
		printf("[%3lld] Move disk %d from Peg %c -> %c\n",++count,numOfDisks,source,dest);
		diskMoveR(numOfDisks-1,aux,dest,source);
	}
}

void recursive(int numOfDisks)
{
	char source = 'A',aux = 'B',dest = 'C';

	printf("Transferring disks using recursive method :\n");
	diskMoveR(numOfDisks,source,dest,aux); // calling the function for solving the problem
	printf("\n\n");
}
 