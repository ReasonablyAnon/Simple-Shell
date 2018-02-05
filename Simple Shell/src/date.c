
#include <stdio.h>
#include <time.h>
#include <string.h>

int main( int arg, char *argvs[] )
{
	//char argvs[50];
	//while(1)
	//{
		//printf("ashell:~$ ");
		//fgets (argvs, 50, stdin);
		
		/*
		int ind = 0;
		while ( argvs[ind] != NULL )
		{
			printf("%s \n",argvs[ind]);
			ind++;
		}
		*/
		
		int hour = 0;
		int day = 0;	
		int i = 0;
		while( argvs[i] != NULL )
		{
			int r1 = strncmp(argvs[i],"+%d",3);
			int r2 = strncmp(argvs[i],"+%H",3);
			if ( r1 == 0 )
			{
				day = 1;
				break;
			}
			if ( r2 == 0 )
			{
				hour = 1;
				break;
			}
			i++;
		}
		time_t ti = time(NULL);
		struct tm *stan = localtime(&ti);
		char *asli = asctime(stan);
		if ( day == 1 && hour == 0 )
		{
			printf("%d \n",stan->tm_mday);
		}
		else if ( hour == 1 && day == 0 )
		{
			printf("%d \n",stan->tm_hour);
		}
		else
		{
			printf("%s \n",asli);
		}
	
	//}
}


/*
			if ( argvs[i] == '%' )
			{
				if ( argvs[i+1] == 'd' )
				{
					day = 1;
					break;
				}
				if( argvs[i+1] == 'H' )
				{
					hour = 1;
					break;
				}
			}
*/

