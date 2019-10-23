//main program for shell
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	char inp[256];
	char pwd3[1000];
	//char *add = getcwd(pwd3,1000);
	char *add = "/home/ashwat/Desktop/2016023/src/";
	char *arrey[50];	
	while(1)
	{
		char pwd2[1000];
		char *cur = getcwd(pwd2,1000);
		char *args[100];
		int i=0;
		args[i] = strtok(cur,"/");
		while( args[i]!=NULL )
		{
   			args[++i] = strtok(NULL,"/");
		}
		
		int i1=0;
		int count = 0;
		while( args[i1]!=NULL )
		{	
			count++;
			i1++;
		}
		
		char *current = args[count-1];
		printf("ashell:~/%s$ ",current);
		fgets (inp, 256, stdin);
		//printf("%s \n",inp);
		
		
		char seco[256];
		int x1 = 0;
		int quote = 0;
		int nodash = 0;
		while ( inp[x1] != NULL )
		{
			seco[x1] = inp[x1];
			//printf("%c",seco[x1]);
			if ( seco[x1] == '"' )
			{
				quote++;
			}
			if ( seco[x1] == '-' )
			{
				nodash = 1;
			}
			x1++;
		}

		strcpy(arrey,add);
		strcat(arrey,"history.txt");
		strtok(arrey,"\n");
		//char *addd = "/history.txt";
		//strcat(add,addd);
		FILE *everyfile = fopen(arrey, "a");
		/*
		int iin = 0;
		while( inp[iin] != '\0' ) 
		{
			fputc(inp[iin],everyfile);
			iin++;
		}
		*/
		//printf("%s \n",inp);
		fputs(inp,everyfile);
		fclose(everyfile);

		//All Commands And Arguments In ARGS2 REMEMBER REMEMBER !!!!!!!!
		char *args2[100];
		int i2=0;
		args2[i2] = strtok(inp," ");
		int ct = 1;
		while( args2[i2]!=NULL )
		{
			ct++;
   			args2[++i2] = strtok(NULL," ");
		}

		//Argument Array To Be Passed TO EXECVP
		char *argvs[ct+1];
		int ind = 0;
		while ( args2[ind] != NULL )
		{
			argvs[ind] = args2[ind];
			//printf("%s \n",argvs[ind]);
			ind++;
		}		
		argvs[ind] = NULL;
		
		strtok(args2[1],"\n");
		int ret3 = strncmp(args2[0],"exit",4);
		int ret1 = strncmp(args2[0],"cd",2);
		int ret2 = strncmp(args2[0],"pwd",3);
		int ret4 = strncmp(args2[0],"history",7);
		int ret5 = strncmp(args2[0],"date",4); //ext
		int ret6 = strncmp(args2[0],"ls",2); //ext
		int ret7 = strncmp(args2[0],"rm",2); //ext
		int ret8 = strncmp(args2[0],"cat",3);  //ext
		int ret9 = strncmp(args2[0],"mkdir",5); //ext
		int ret10 = strncmp(args2[0],"echo",4); 
		if ( ret1 == 0 )
		{
			int ans = cd(args2[1]);
			if( ans != 0 )
			{
				printf("Invalid Directory \n");
				return;
			}
		}
		if ( ret2 == 0 )
		{
			char add[1000];
			char* ans = getcwd(add,1000);
			printf("%s \n",ans);
		}
		if ( ret3 == 0 )
		{
			kill(getppid(), SIGKILL);
			return;
		}
		if ( ret4 == 0 )
		{
			FILE *fp2;
			//strtok(add,"\n");
			//char *add2 = "/history.txt";
			//strcat(add,add2);
			strcpy(arrey,add);
			strcat(arrey,"history.txt");
			strtok(arrey,"\n");
			fp2 = fopen(arrey, "r");
			char buff[256];
			char *ch;
			int cun = 1;
    			while( (ch=fgets(buff,256,fp2)) != EOF )
			{
					if ( ch != NULL )	
					{
						printf(" %d   %s",cun,ch);
						cun++;
					}
					else
					{
						break;
					}
    			}
    			fclose(fp2);
		}
		if ( ret5 == 0 )
		{
			pid_t pid;
			pid = fork();
			if ( pid < 0 )
			{
				printf("Error! Fork Failed \n");
				return ;	
			}
			else if ( pid == 0 )
			{
				//char *add2 = "/date";
				//strcat(add,add2);
				strcpy(arrey,add);
				strcat(arrey,"date");		
				execvp(arrey,argvs);
			}
			else
			{
				wait(NULL);
			}
		}	
		if ( ret6 == 0 )
		{
			pid_t pid;
			pid = fork();
			if ( pid < 0 )
			{
				printf("Error! Fork Failed \n");
				return ;	
			}
			else if ( pid == 0 )
			{
				//char *add2 = "/ls";
				//strcat(add,add2);
				strcpy(arrey,add);
				strcat(arrey,"ls");		
				execvp(arrey,argvs);
			}
			else
			{
				wait(NULL);
			}
		}
		if ( ret7 == 0 )
		{
			pid_t pid;
			pid = fork();
			if ( pid < 0 )
			{
				printf("Error! Fork Failed \n");
				return ;	
			}
			else if ( pid == 0 )
			{
				strcpy(arrey,add);
				strcat(arrey,"rm");		
				execvp(arrey,argvs);
				//char *add2 = "/rm";
				//strcat(add,add2);
				//execvp(add,argvs);
			}
			else
			{
				wait(NULL);
			}
		}
		if ( ret8 == 0 )
		{
			pid_t pid;
			pid = fork();
			if ( pid < 0 )
			{
				printf("Error! Fork Failed \n");
				return ;	
			}
			else if ( pid == 0 )
			{
				strcpy(arrey,add);
				strcat(arrey,"cat");		
				execvp(arrey,argvs);
				//char *add2 = "/cat";
				//strcat(add,add2);
				//execvp(add,argvs);
			}
			else
			{
				wait(NULL);
			}
		}
		if ( ret9 == 0 )
		{
			pid_t pid;
			pid = fork();
			if ( pid < 0 )
			{
				printf("Error! Fork Failed \n");
				return ;	
			}
			else if ( pid == 0 )
			{
				//char *add2 = "/mkdir";
				//strcat(add,add2);
				//execvp(add,argvs);
				strcpy(arrey,add);
				strcat(arrey,"mkdir");		
				execvp(arrey,argvs);
			}
			else
			{
				wait(NULL);
			}
		}
		if ( ret10 == 0 )
		{
			char outp[256];
			int op = 0;
			if( quote == 2 ) 
			{
    				int dou = 0;
				int y = 0;
				while ( seco[y] != NULL )
				{
					if ( dou == 1 && seco[y] != '"' )	
					{
						printf("%c",seco[y]);
					}
					if ( seco[y] == '"' && dou == 0 )
					{
						dou++;
					}
					else if ( seco[y] == '"' && dou != 2 )
					{
						break;
					}
					y++;
				}
				printf("\n");
			}
			if ( nodash == 0 && quote == 0 )
			{
				char *ar[100];
				int ii2=0;
				ar[ii2] = strtok(seco," ");
				while( ar[ii2] != NULL )
				{
   					ar[++ii2] = strtok(NULL," ");
				}	
				int iii = 0;
				while ( ar[iii] != NULL )
				{
					if ( strncmp(ar[iii],"echo",4) != 0 )
					{
						printf("%s ",ar[iii]);
					}
					iii++;
				}
				printf("\n");
			}
		}
	}
}

int cd( char *inp )
{
	return chdir(inp);
}
