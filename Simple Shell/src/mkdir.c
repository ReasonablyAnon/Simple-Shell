//program for date command in shell

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main( int arg, char *argvs[] )
{
	/*
	char inp[256];
	while(1)
	{
		printf("ashell:~$ ");
		fgets (inp, 256, stdin);
		
		int v = 0;
		int m = 0;
		char *args[100];
		int i=0;
		args[i] = strtok(inp," ");
		while( args[i]!=NULL )
		{
   			args[++i] = strtok(NULL," ");
		}
	*/

		int v = 0;
		int m = 0;
		int z2 = 0;
		while ( argvs[z2] != NULL )
		{
			int r1 = strncmp(argvs[z2],"-m",2);
			int r2 = strncmp(argvs[z2],"-v",2);
			if ( r1 == 0  )
			{
				m = 1;
				break;
			}
			if ( r2 == 0  )
			{
				v = 1;
				break;
			}
			z2++;
		}
		
		if ( v == 1 && m == 0 )
		{
			char *name = argvs[2];
			int r = mkdir(name,400);
			if ( r != 0 )
			{
				printf("Error Making Directory \n");
				return ;
			}
			printf("mkdir: created directory %s \n",name);
		}
		else if ( m == 1 && v == 0 )
		{
			char *name = argvs[3];
			char *mode = argvs[2];
			//printf("%s \n",name);
			int r = mkdir(name,atoi(mode));
			if ( r != 0 )
			{
				printf("Error Making Directory \n");
				return ;
			}
		}
		else
		{
			char *name = argvs[1];
			int r = mkdir(name,400);
			if ( r != 0 )
			{
				printf("Error Making Directory \n");
				return ;
			}
		}
	//}
}
