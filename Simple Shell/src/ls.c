
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main( int arg, char *argvs[] )
{
	//char argvs[200];
	//while(1)
	//{
		int containsR = 0;
		int containsA = 0;
		int containsBoth = 0;
		char pwd[1000];
		//printf("ashell:~$ ");
		//fgets (argvs, 200, stdin);
		int z2 = 0;
		while ( argvs[z2] != NULL )
		{
			int r1 = strncmp(argvs[z2],"-a",2);
			int r2 = strncmp(argvs[z2],"-r",2);
			int r3 = strncmp(argvs[z2],"-ar",3);
			int r4 = strncmp(argvs[z2],"-ra",3);
			if ( r1 == 0  )
			{
				containsA = 1;
				break;
			}
			if ( r2 == 0  )
			{
				containsR = 1;
				break;
			}
			if ( r3 == 0  )
			{
				containsBoth = 1;
				break;
			}
			if ( r4 == 0  )
			{
				containsBoth = 1;
				break;
			}
			z2++;
		}

		char *cur = getcwd(pwd,1000);
		//printf("%s\n",getcwd(pwd,1000));			
		int count = 0;
		int acount = 0;
		struct dirent *entry;
		DIR *dir;
		dir = opendir(cur);
		char *first[2000];
		char *a[2000];
		int c2 = 0;
		int c22 = 0;
		while ((entry = readdir (dir)) != NULL) 
		{
			if ( entry->d_type == DT_REG || entry->d_type == DT_DIR )
			{
				char *res = entry->d_name;
				a[c22] = res;
				char *tmp = res;
				ino_t in = entry->d_ino;
				if ( *res++ != '.' )
				{
					count++;		
					//printf("%d \n",in);
					//printf("%s \n",tmp);
					first[c2] = tmp;	
					c2++;
				}
				acount++;
				c22++;
			}
		}
		closedir(dir);
		sort(first, count);
		sort(a,acount);
		if ( containsBoth == 0 && containsR == 0 && containsA == 0 )
		{
			int z = 0;
			while ( first[z] != NULL )
			{
				printf("%s \n",first[z]);
				z++;
			}
		}
		else if ( containsA == 1 && containsBoth == 0 )
		{
			int z = 0;
			while ( a[z] != NULL )
			{
				printf("%s \n",a[z]);
				z++;
			}
		}
		else if ( containsR == 1 && containsBoth == 0 )
		{
			for ( int z = count-1 ; z >= 0 ; z-- )
			{
				printf("%s \n",first[z]);
			}
		}
		else if ( containsBoth == 1 )
		{
			for ( int z = acount-1 ; z >= 0 ; z-- )
			{
				printf("%s \n",a[z]);
			}
		}

	//}
}

static int myCompare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}
 
void sort(const char *arr[], int n)
{
    qsort (arr, n, sizeof (const char *), myCompare);
}


/*

		struct dirent *namelist;
		int n = scandir(cur, &namelist, NULL, alphasort);
           	for ( int i = 0 ; i< n ; i++ ) 
		{
	               //printf("%s\n", namelist[i]->d_name);
	               free(namelist[n]);
           	}
          	free(namelist);	

		int c =0;
		char *arr[count];
		struct dirent *ent;
		DIR *dirr;
		dirr = opendir(cur);
		while ((ent = readdir (dirr)) != NULL) 
		{
			if ( ent->d_type == DT_REG || ent->d_type == DT_DIR )
			{
				char *res = ent->d_name;
				char *tmp = res;
				if ( *res++ != '.' )
				{
					//printf("%s \n",tmp);
					//arr[c] = malloc(sizeof(char)*strlen(tmp));
					arr[c] = tmp;
					//printf("%s \n",arr[c]);
					c++;		
				}
			}
		}
		closedir(dir);
*/


