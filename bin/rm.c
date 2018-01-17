#include <stdio.h>

int main(int argc, char *argv[]) {
	if(argc < 2){
		printf("Insufficient arguments \n");
		return 1;
	} 
	
	if(argc == 2) {
		char *path = argv[1];
		FILE *f;
		f= fopen(path, "r");
		if(f != NULL) //the file exists
			remove(path);
		else
		{
			printf("Cannot remove: file does not exist\n");
			return 1;
		}
	}
	
	else
	{
		
	}
	return 0;
}
