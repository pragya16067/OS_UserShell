#include <stdio.h>
#include <string.h>

//The 2 options implemented are cat - (or cat with no option) and cat -n and cat -E

int main(int argc, char* argv[]) {
	int c;
	FILE *file;
	char *path;
	char stdin[1024];
	char *n= "-n";
	char *E= "-E";
	
	if(argc==1)
	{
		gets(stdin);
		puts(stdin);
	}
	else if(argc==2) {
		char *dash="-";
		if(strcmp(argv[1],dash)==0) {
			gets(stdin);
			puts(stdin);
		}
		else {
			path = argv[1];
	
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
		}
	}

	else if(argc == 3)
	{
		if(strcmp(argv[1],n) == 0) //option is -n with one filename
		{
			//to print all line numbers
			int i=1;
			path = argv[2];
			file = fopen(path, "r");
			
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					printf("\t%d   %s",i,stdin);
					i++;
				}
			    fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
		}
		else if(strcmp(argv[1],E) == 0) //option is -E with one filename
		{
			//to print $ at end of each line
			path = argv[2];
			file = fopen(path, "r");
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					if(strcmp(stdin,"\n")==0) //empty line 
						{printf("$\n");}
					else {
						strtok(stdin,"\n");
						printf("%s$\n",stdin);
						}
					}
				fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
		}
		else {
			path = argv[1];
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
	}
	else if(argc ==4)
	{
		if(strcmp(argv[1],n) == 0) //option is -n with 2 filenames
		{
			//to print all line numbers of the file 1
			int i=1;
			path = argv[2];
			file = fopen(path, "r");
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					printf("\t%d   %s",i,stdin);
					i++;
				}
			    fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
			path = argv[3];
			file = fopen(path, "r");
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					printf("\t%d   %s",i,stdin);
					i++;
				}
			    fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
		}
		else if(strcmp(argv[1],E) == 0) //option is -E with 2 filenames
		{
			//to print $ at end of all lines

			path = argv[2];
			file = fopen(path, "r");
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					if(strcmp(stdin,"\n")==0) //empty line 
						{printf("$\n");}
					else {
						strtok(stdin,"\n");
						printf("%s$\n",stdin);
						}
					}
				fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
			path = argv[3];
			file = fopen(path, "r");
			if (file) {
				while ((fgets(stdin,1024,file)) != NULL) {
					if(strcmp(stdin,"\n")==0) //empty line 
						{printf("$\n");}
					else {
						strtok(stdin,"\n");
						printf("%s$\n",stdin);
						}
					}
				fclose(file);
			}
			else
			{
				printf("Sorry, file not found\n");
				return 1;
			}
		}
		else { printf("Enter a valid option\n"); return 1; }
	}

return 0;
}
