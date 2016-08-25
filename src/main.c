#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum task{recur,iter,both};
enum bool{true,false};

//function declarations of recursive and iterative functions from their respective c files
void recursive(int numOfDisks);
void iterative(int numOfDisks);

int main(int argc,char *argv[])
{
	system("clear\n"); // clearing the terminal screen for clear output

	FILE *log = NULL;
	log = fopen("log","w"); // opening log file for easy debugging

	int numbOfDisks;
	enum bool input;
	enum task do_task;

	//checking the number and types of arguments 
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
	// if input is still false then value of numbOfDisks has to be taken from user
	if(input == false)
	{
		printf("Enter the number of disks :\t");
		scanf("%d",&numbOfDisks);
	}

	// sending logs to file log
	fprintf(log,"All the variables are declared\nNumber of arguments %d\n",argc);
	fprintf(log,"The values of enums are :\ninput :\t%d\ndo_task :\t%d\n",input,do_task);
	fprintf(log,"The number of disks are as follows : \t%d\n\n",numbOfDisks);

	clock_t start,end;

	//checking how the user wants to do the program ,using recursive or iterative or both 
	switch(do_task)
	{
				//in case of do_task = iter ,iterative method is used
	case iter:	fprintf(log,"Sending handle to iterative function...\n");
				start = clock();
				iterative(numbOfDisks);
				end = clock();
				fprintf(log,"Tower of hanoi solved by iterative approach in %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);
				break;
				//in case of do_task = recur ,recursive method is used
	case recur:	fprintf(log,"Sending handle to recursive function...\n");
				start = clock();
				recursive(numbOfDisks);
				end = clock();
				fprintf(log,"Tower of hanoi solved by recursive approach in %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);
				break;
				//in case of do_task = both, both the methods are used
	case both:	fprintf(log,"Sending handle to recursive function...\n");
				start = clock();
				recursive(numbOfDisks);
				end = clock();
				fprintf(log,"Tower of hanoi solved by recursive approach in %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);

				fprintf(log,"Sending handle to iterative function...\n");
				start = clock();
				iterative(numbOfDisks);
				end = clock();
				fprintf(log,"Tower of hanoi solved by iterative approach in %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);
				break;
	}
	fclose(log);
	return 0;
}