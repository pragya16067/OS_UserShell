#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

//options implemented are -v and -p


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
		char *path;
		if(strcmp(argv[1],"-v")==0) //option is -v
		{
			path = argv[2];
	
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
		else if(strcmp(argv[1],"-p")==0) //option is -p
		{
			path=argv[2];
			int i = 0;
			char *ptr=strtok(path, "/");
			char *dirNames[10];

			while(ptr!='\0')
			{
				dirNames[i++]=ptr;
				ptr=strtok(NULL, "/");
			}
			dirNames[i] = '\0';
			//array dirNames holds the names of all directories that need to be created
			i=0;
			while(dirNames[i] != '\0') {
				if(chdir(dirNames[i]) != 0) //Directory doesnt exist
				{
					//so create it 
					if ((mkdir(dirNames[i], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH )) == 0) 
					{
				  		chdir(dirNames[i]);
				  	}
					else {
				  		// could not create directory 
						printf("mkdir: Could not create directory\n");
				  		return 1;
					}
				}
				i++;
			}
		}
		else
		{
			printf("Please enter a valid option\n");
			return 1;
		}
	
	}
	else
	{
		printf("Please enter a valid option\n");
		return 1;
	}
	return 0;
}


