//program for cat command in shell

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main( int arg, char *argvs[] )
{
		int n = 0;
		int e = 0;
		int b = 0;	
		int i = 0;
		while( argvs[i] != NULL )
		{
			int r1 = strncmp(argvs[i],"-n",2);
			int r2 = strncmp(argvs[i],"-e",2);
			if ( r1 == 0 )
			{
				n = 1;
				break;
			}
			if ( r2 == 0 )
			{
				e = 1;
				break;
			}
			i++;
		}

		int i2 = 0;
		int c2 = 0;
		while( argvs[i2] != NULL )	
		{	c2++;
			i2++;
		}

		char *term[2000];
		int t = 0;
		for ( int j = 0 ; j < c2 ; j++ )
		{

			int r11 = strncmp(argvs[j],"cat",3);
			int r22 = strncmp(argvs[j],"-",1);
			if ( r11 != 0 && r22 != 0 )
			{
				FILE *fp;
				strtok(argvs[j],"\n");
				fp = fopen(argvs[j], "r");
				//printf("%s \n",argvs[j]);
		
	    			if( fp == NULL ) 
				{
					//printf("Error %d \n", errno);
		       			printf("No File or Directory Found By The Name \n");
	       				return 0;
	    			}
				else 
				{
					if ( n == 0 && e == 1 )
					{
						char buff[256];
						char *ch;
		    				while( (ch=fgets(buff,256,fp)) != EOF )
						{
							strtok(ch,"\n");
							if ( ch != NULL )	
							{
								printf("%s$",ch);
							}
							else
							{
								break;
							}
							printf("\n");
		    				}
					}
					if ( n == 1 && e == 0 )
					{
						char buff[256];
						char *ch;
						int count = 1;
		    				while( (ch=fgets(buff,256,fp)) != EOF )
						{
							if ( ch != NULL )	
							{
								printf("   %d  %s ",count,ch);
								count++;
							}
							else
							{
								break;
							}
		    				}
					}
					if ( n == 0 && e == 0 )
					{
						char buff[256];
						char *ch;
		    				while( (ch=fgets(buff,256,fp)) != EOF )
						{
							if ( ch != NULL )	
							{
								printf("%s",ch);
							}
							else
							{
								break;
							}
		    				}
					}
				}
	    			fclose(fp);
			}
		}

		
	//}

}


			/*
			//Absolute Path Calculations
			char add[1000];
			char *adp = getcwd(add,1000);
			int len1 = strlen(adp);
			int len2 = strlen(first[j]);
			int len = len1+len2;
			char abs[len+1];
			char *tt = first[j];
			int i1 = 0;
			for ( i1 = 0 ; i1 < len1 ; i1++ )
			{
				abs[i1] = *adp++;
			}
			abs[i1] = '/';
			i1++;
			for( int i2 = 0 ; i2 < len2 ; i2++ )
			{
				abs[i1++] = *tt++;
			}
			*/


	/*
	while(1)
	{
		
		char inp[200];
		printf("ashell:~$ ");
		fgets (inp, 200, stdin);

		char *args[100];
		int i=0;
		args[i] = strtok(inp," ");
		while( args[i]!=NULL )
		{
   			args[++i] = strtok(NULL," ");
		}
		int len = strlen(args);
		//printf("Length %d \n",len);
		//printf("Element %s \n",args[3]);
	*/

		/*
		int k = 1;
		char *flag;
		char *out;
		int c2 = 0;
		char *first[256];
		while ( args[k] != NULL )
		{
			//printf("Element %s \n",args[k]);
			int n = strlen(args[k]);
			char *tmp = args[k];
			char *hyp = tmp;
			char *hy2 = tmp;
			char *res = tmp;
			char *dash = tmp;
			char *out2 = tmp;
			if ( *tmp++ != '-' && *hyp++ != ' ' && *hy2++ != '>' )
			{		
				first[c2] = out2;
				//printf("%s \n",first[c2]);
				c2++;	
			}
			else if( *res++ == '-' )
			{
				if ( *res++ != NULL )
				{
					flag = out2;
				}
			}
			else if ( *dash++ == '>' )
			{
				out = out2;
			}
			//printf("%s \n",out2);
			k++;
		}
		*/


