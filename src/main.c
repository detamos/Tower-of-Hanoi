#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long long int lli;

enum task{recur,iter,both};
enum bool{true,false};

void recursive(int numOfDisks);
void iterative(int numOfDisks);

int main(int argc,char *argv[])
{
	system("clear\n");

	int numbOfDisks;
	enum bool input;
	enum task do_task;

	switch(argc)
	{
	case 1:	input = false;
			do_task = both;
			break;
	case 2:	if(strcmp(argv[1],"recursive") == 0) 
			{
				do_task = recur;
				input = false;
			}
			else if(strcmp(argv[1],"iterative") == 0)
			{
				do_task = iter;
				input = false;
			}
			else
			{
				numbOfDisks = atoi(argv[1]);
				input = true;
				do_task = both;
			}
			break;
	case 3:	if(strcmp(argv[1],"recursive") == 0)
			{
				do_task = recur;
				numbOfDisks = atoi(argv[2]);
			}
			else if(strcmp(argv[2],"recursive") == 0)
			{
				do_task = recur;
				numbOfDisks = atoi(argv[1]);
			}
			else if(strcmp(argv[1],"iterative") == 0)
			{
				do_task = iter;
				numbOfDisks = atoi(argv[2]);
			}
			else if(strcmp(argv[2],"iterative") == 0)
			{
				do_task = iter;
				numbOfDisks = atoi(argv[1]);
			}
			else
			{
				printf("Wrong arguments!!\n");
				do_task = both;
				input = false;
			}
			break;
	default:printf("Wrong number of arguments!!\n");
			do_task = both;
			input = false;
	}

	if(input == false)
	{
		printf("Enter the number of disks :\t");
		scanf("%d",&numbOfDisks);
	}

	//clock_t start,end;

	switch(do_task)
	{
	case iter:	//start = clock();
				iterative(numbOfDisks);
				//end = clock();
				break;
	case recur:	//start = clock();
				recursive(numbOfDisks);
				//end = clock();
				break;
	case both:	//start = clock();
				recursive(numbOfDisks);
				//end = clock();

				//start = clock();
				iterative(numbOfDisks);
				//end = clock();
				break;
	}
	return 0;
}