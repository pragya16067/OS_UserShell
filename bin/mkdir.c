#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

//options implemented are -v and 


int main(int argc, char *argv[]) {
	if(argc==2) //no options for mkdir 
	{
		char *path = argv[1];
	
		if ((mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH )) == 0) 
		{ }
		else {
	  		// could not create directory 
			printf("Could not create directory\n");
	  		return 1;
		}
	}
	else if(argc==3) {
		if(strcmp(argv[1],"-v")==0) //option is -v
		{
			char *path = argv[2];
	
			if ((mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH )) == 0) 
			{
		  		printf("mkdir: created directory '%s'\n",path);
		  	}
			else {
		  		// could not create directory 
				printf("Could not create directory\n");
		  		return 1;
			}
		}
		else
		{
			printf("Please enter a valid option");
			return 1;
		}
	
	}
	else
	{
		printf("Please enter a valid option");
		return 1;
	}
	return 0;
}


