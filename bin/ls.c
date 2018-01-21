#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Implemented options -a,-x and -U

int main(int argc, char * argv[]) {

	struct dirent **listnames; //holds the files and directory names inside the pwd
	int i;
	int n = scandir(".", &listnames, 0, alphasort); //get the number of files and directories in pwd
	//also sorts the names alphabetically into array of strings listnames using function alphasort
	if(n<0) //some error occured in scandir
	{
		printf("Some error in executing ls: Could not open directory");
		/* could not open directory */
		return 1;
	}
	
	
	if(argc == 1)
	{	
		
		//ls with no options
		
		if (n>=0) {
			for(i=0; i<n; i++)
			{
			//print names of all files and directories in pwd in ascending order, but not hidden files
				char *dirname = listnames[i]->d_name;
		  		if(*dirname=='.')
		  			continue;
				printf("%s \n", listnames[i]->d_name);
			}
			free(listnames);
		}
		else
		{
			printf("Some error in executing ls: Could not open directory");
		  	/* could not open directory */
		  	return 1;
		}
	}
	else if(argc==2)
	{ 
		if(strcmp(argv[1],"-a")==0) //option is -a
		{
			//show files starting with . also, i.e. hidden files
			if (n>=0) {
				for(i=0; i<n; i++)
				{
				//print names of all files and directories in pwd in ascending order, including hidden files
					printf("%s \n", listnames[i]->d_name);
				}
				free(listnames);
			}
			else {
				printf("Some error in executing ls");
		  		/* could not open directory */
		  		return 1;
			}
		}
		else if(strcmp(argv[1],"-x")==0) //option is -x
		{
			//show all files in a single line
			if (n>=0) {
				for(i=0; i<n; i++)
				{
				//print names of all files and directories in pwd in ascending order, but not hidden files
					char *dirname = listnames[i]->d_name;
			  		if(*dirname=='.')
			  			continue;
					printf("%s  ", listnames[i]->d_name);
				}
				printf("\n");
				free(listnames);
			}
			else {
				printf("Some error in executing ls");
		  		/* could not open directory */
		  		return 1;
			}
		}
		else if(strcmp(argv[1],"-U")==0) //option is -U
		{
			//Do not sort, print files in order as listed in directory
			DIR *dir;
			struct dirent *fname;
			char *path = get_current_dir_name();
			
			if ((dir = opendir(path)) != NULL) {
		  		/* print names of all the files and directories within pwd, but not hidden files */
		  		while ((fname = readdir(dir)) != NULL) {
		  			char *dirname = fname->d_name;
		  			if(*dirname=='.')
		  				continue;
		    			printf ("%s  \n", fname->d_name);
		  		}
		  	
		  	closedir (dir);
			}
			else {
				printf("Some error in executing ls");
		  		/* could not open directory */
		  		return 1;
			}
		}
		else
		{
			printf("Please enter a valid option.\n");
			return 1;
		}
	}
	else
	{
		printf("Please eneter a valid option");
		return 1;
	}
	return 0;
}

