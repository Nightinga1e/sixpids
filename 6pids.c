#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pids[6];
	pid_t curpid;
//	printf("1 This process ID is %d, parent ID %d\n", getpid(), getppid());
	pids[0] = getpid();
	fork();
	if (getpid()!= pids[0])
	{
		pids[1] = getpid();
	}else if (getpid() == pids[0])
	{
		fork();
	}

	if((getpid()!=pids[0]) && (getpid()!=pids[1]))
	{
		pids[2] = getpid();
	}
	if(getpid() == pids[1])
	{
		fork();
	}
	if(getpid() == pids[2])
	{
		fork();
	}
	if(getpid() == pids[2])
	{
		fork();
	}
	printf("2 This process ID is %d, parent ID is %d \n", getpid(), getppid());
	return 0;
}
