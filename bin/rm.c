#include <stdio.h>
#include <string.h>

//Options : -i, -d and -v

int main(int argc, char *argv[]) {
	char *path;
	FILE *f;
	if(argc < 2){
		printf("Insufficient arguments \n");
		return 1;
	} 
	
	if(argc == 2) {
		path = argv[1];
		f= fopen(path, "r");
		if(f != NULL) //the file exists
			remove(path);
		else
		{
			printf("Cannot remove: file does not exist\n");
			return 1;
		}
	}
	
	else if(argc == 3)
	{
		if(strcmp(argv[1],"-i")==0) //option is -i
		{
			path = argv[2];
			printf("Do you want to remove file '%s'? (y/n):",path);
			char c=getchar();
			if(c=='y')
			{
				//remove the file
				
				f= fopen(path, "r");
				if(f != NULL) //the file exists
					remove(path);
				else
				{
					printf("Cannot remove '%s': No such file\n",path);
					return 1;
				}
			}
				
		}
		else if(strcmp(argv[1],"-v")==0) //option is -v (verbose)
		{
			path = argv[2];
			//remove the file
			
			f= fopen(path, "r");
			if(f != NULL) //the file exists 
			{
				remove(path);
				printf("removed '%s'\n",path);
			}
			else
			{
				printf("Cannot remove '%s': No such file\n",path);
				return 1;
			}
			
				
		}
		else if(strcmp(argv[1],"-d")==0) //option is -d
		{
			path = argv[2];
			//remove the file
			
			f= fopen(path, "r");
			if(f != NULL) //the file exists 
			{
				remove(path);
			}
			else
			{
				printf("Cannot remove '%s': No such file\n",path);
				return 1;
			}
			
				
		}
		else
		{
			printf("Please enter a valid option.\n");
		}


	}
	return 0;
}
