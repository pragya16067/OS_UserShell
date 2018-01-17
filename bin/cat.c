#include <stdio.h>

int main(int argc, char* argv[]) {
	int c;
	FILE *file;
	
	char *path = argv[1];
	
	file = fopen(path, "r");
	if (file) {
	    while ((c = getc(file)) != EOF)
		putchar(c);
	    fclose(file);
	}
	else
	{
		printf("Sorry, file not found\n");
		return 1;
	}

	if(argc == 3)
	{
		path=argv[2];
		file=fopen(path, "r");
		if(!file)
		{
			printf("Sorry, file not found\n");
			return 1;
		}
		while((c= getc(file)) != EOF) {
			putchar(c);
			}
		fclose(file);
	}

return 0;
}
