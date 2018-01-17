#include <dirent.h>
#include <stdio.h>

int main() {
	DIR *dir;
	//struct dirent *ent;
	char *path = get_current_dir_name();
	char *contents[]= 
	if ((dir = opendir(path)) != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir(dir)) != NULL) {
    			printf ("%s\n", ent->d_name);
  		}
  	closedir (dir);
	} 
	
	else {
		printf("Some error in executing ls");
  		/* could not open directory */
  		return 1;
	}
	return 0;
}

