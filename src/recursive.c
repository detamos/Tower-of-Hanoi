#include <stdio.h>

void diskMoveR(int numOfDisks,char source,char dest,char aux)
{
	static long long int count = 0;
	if(numOfDisks == 1)
		printf("[%3lld] Move disk %d from Peg %c -> %c\n",++count,numOfDisks,source,dest);
	else
	{
		diskMoveR(numOfDisks-1,source,aux,dest);
		printf("[%3lld] Move disk %d from Peg %c -> %c\n",++count,numOfDisks,source,dest);
		diskMoveR(numOfDisks-1,aux,dest,source);
	}
}

void recursive(int numOfDisks)
{
	char source = 'A',aux = 'B',dest = 'C';

	printf("Transferring disks using recursive method :\n");
	diskMoveR(numOfDisks,source,dest,aux);
	printf("\n\n");
}
 