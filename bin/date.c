#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
	time_t t = time(NULL);
	printf("%s \n", ctime(&t));


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


