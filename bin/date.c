#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

	char *u= "-u"; char *r="-r";
	
	if(argc == 1) {
		time_t t = time(NULL);
		printf("IST %s", ctime(&t));
	}
	
	else if (argc == 2)
	{
		//printf("%s %s \n",u,argv[1]);
		if(strcmp(argv[1],u) == 0) //the option is -u
		{
			//Output the time in UTC
			struct tm *utcT;
  			time_t t= time(NULL);
  			utcT = gmtime(&t); //function to get the UTC time
  			printf("UTC %s", asctime(utcT));
		}
		else if(strcmp(argv[1],r)==0)
		{
			printf("Option -r requires a file path!!\n");
			return 1;
		}
		else
		{
			printf("Please enter valid option\n");
			return 1;
		}
	}
	else if (argc == 3)
	{
		
		//printf("%s %s \n",u,argv[1]);
		if(strcmp(argv[1],r) == 0) //the option is -r
		{
			//to get the last modified date and time of file given by path
			char *path= argv[2];
			//printf("%s \n",path);
			struct stat modDT;
			stat(path, &modDT);
			printf("%s",ctime(&modDT.st_mtime));
		}
		
		else
		{
			printf("Please enter valid option\n");
			return 1;
		}
	}
	else
	{
		printf("Some error in executing command, Check the syntax\n");
		return 1;
	}


	/*time_t t = time(NULL);
	struct tm time = *localtime(&t);
	printf("now: %d-%d-%d %d:%d:%d\n", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);

	struct tm *date;
	date = localtime(&t);
	char dayofweek[5];
	char *format= "%a";
	strftime(dayofweek, 5, format, date);
	printf(" %s \n", dayofweek);*/


return 0;

}


