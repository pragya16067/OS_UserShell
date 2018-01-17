
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	char *path = argv[1];
	
	if ((mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH )) == 0) 
	{
		
  		printf("Directory created\n");
  	}
	else {
  		// could not open directory 
		printf("could not open directory\n");
  		return 1;
	}
	return 0;
}


