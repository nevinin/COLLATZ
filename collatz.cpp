#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	int k=0;
	int i=0;
	
	pid_t pid;

		do
		{
			printf("Please enter a number greater than 0 to run the Collatz Conjecture.\n"); 
  			scanf("%d", &i);	
		}while (i <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Child is worjing...\n");
			printf("%d\n",i);
			while (i!=1)
			{
				if (i%2 == 0)
				{
					i = i/2;
				}
				else if (i%2 == 1)
				{
					i = 3 * (i) + 1;
				}	
			
				printf("%d\n",i);
			}
		
			printf("Child process is done.\n");
		}
		else
		{
			printf("Parents is waiting on child process...\n");
			printf("Parent process is done.\n");
		}
	return 0; 
}