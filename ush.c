/**
	AUTHOR : PRAGYA PRAKASH
	ROLL NO. : 2016067
	OS Assignment 0
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

/*

function to split an input string of unknown length, with whitespace as a delimiter, to form an array of Strings (terminated by Null)
	For example : Input str = "ls -l"
	Output would be a char[][] like { {ls}, {-l}, {NULL} }
	
*/

char **split(char *str)
{

	char *tokens = strtok(str, " ");	//now token has the value of the first word eneterd by the user

	char **tokenizedStr = malloc(1024);	//allocates 1KB memory for the array of words of input
	int size_ptr = 0;

	//do while there exists words/tokens in the input string
	do {

		size_ptr = size_ptr + 1;
		if ((size_ptr) * sizeof(char *) >= 1024)	//if size exceeds the already allocated memory, reallocate more memory
		{
			tokenizedStr =realloc(tokenizedStr,(size_ptr + 1) * sizeof(char *));
		}

		if (tokenizedStr == '\0') {	/* Some failure in realloc() */
			printf("Some error occurred in allocating memory. Try again.\n");
			break;
		}

		tokenizedStr[size_ptr - 1] = tokens;
		tokens = strtok(NULL, " ");	//puts in array tokens, the last value of where it was supposed to be, i.e. the next word in input string

	} while (tokens != NULL);

	/* Appending the terminating NULL */
	if ((size_ptr) * sizeof(char *) >= 1024)	//if size exceeds the already allocated memory, reallocate more memory
	{
		tokenizedStr =
		    realloc(tokenizedStr, (size_ptr + 1) * sizeof(char *));
	}
	tokenizedStr[size_ptr] = '\0';

	return tokenizedStr;
}

/*

The main function is the infinite loop of the shell which terminates with the exit command and executes user inputted commands

*/

int main()
{

	while (1) {
		char *cwd = (char *)get_current_dir_name();
		if (cwd == NULL) {
			//error occured in get_current_dir_name
			printf
			    ("error occured in getting the current working directory\n");
			continue;
		}
		printf("PragyaShell: %s >> ", cwd);

		//read the inputs
		char input[1024];
		gets(input);

		//find the command and arguments
		//and store it in an array of Strings
		char **arg = split(input);
		char *command = arg[0];

		//printf("the command is %s\n", command);

		//Internal commands, namely exit, cd, pwd, echo, history and help

		char exit[] = "exit";
		char cd[] = "cd";
		char pwd[] = "pwd";
		char echo[] = "echo";
		char history[] = "history";
		char help[] = "help";
		
		//a string to store the latest cd command, and use it for "cd -"
		char *prevCD;

		//quit if command is exit
		if (strcmp(command, exit) == 0) {
			break;
		}
		//print present working directory if command is cwd
		else if(strcmp(command,pwd) == 0)
		{
			if(arg[1]=='\0') //no options of pwd
			{
				char *cwd = (char *)get_current_dir_name();
				if (cwd == NULL) {
					//error occured in get_current_dir_name
					printf("Error occured in getting the current working directory\n");
					continue;
				}
				printf("%s\n",cwd);
			}
		}
		//change directory if the command is cd
		else if (strcmp(command, cd) == 0) {
			if (arg[1] != NULL) {
				if(strcmp(arg[1],"~")==0 || strcmp(arg[1],"~pragya")==0)
				{
					prevCD = (char *)get_current_dir_name();
					chdir("/home/pragya");
					continue;
				}
				else if(strcmp(arg[1],"-") == 0)
				{
					printf("%s \n",prevCD);
					char new[200];
					strcpy(new,prevCD);
					
					prevCD=(char *)get_current_dir_name();
					
					if (chdir(new) != 0)	//some error in executing chdir(Change directory) command
					{
						printf("Some error in executing command cd\n");
						continue;
					}
				}
				else
				{
					prevCD = (char *)get_current_dir_name();
					if (chdir(arg[1]) != 0)	//some error in executing chdir(Change directory) command
					{
						printf("Some error in executing command cd\n");
						continue;
					}
							
				}
			} else {	//Directory name to change to has not been specified
				prevCD = (char *)get_current_dir_name();
				chdir("/home/pragya");
				continue;
			}
		}
		//print the trailing text if the command is echo
		else if(strcmp(command,echo) ==0)
		{
		
		}
		//give some help advice if the command is help
		else if (strcmp(command, help) == 0) {
			printf
			    ("This is Pragya's designed shell. Wait for the prompt to appear and type in the command you wish to execute.\n");
			printf
			    ("Few of the various commands you could use are \n cd : change directory \n exit : to exit the shell \n ls : to list all files in the current directory \n pwd : to get the present working directory \n and many more...\n");
		}

		else {
			//execute other commands
			int forkResult = fork();
			if (forkResult == 0) {
				//this is the child process
				//printf("the command is %s\n", command);
				
				if(strcmp(command,"ls")==0) {
				
					char path[] = "/home/pragya/Desktop/shell/bin/ls";
					if (execv(path, arg) == -1) {
						//Some error in execl
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"mkdir")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/mkdir";
					if (execv(path, arg) == -1) {
						//Some error in execl
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"cat")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/cat";
					if (execv(path, arg) == -1) {
						//Some error in execl
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"date")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/date";
					if (execv(path, arg) == -1) {
						//Some error in execl
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"rm")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/rm";
					if (execv(path, arg) == -1) {
						//Some error in execl
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else
				{
					printf("This command does not exist.\n");
					continue;
				}
			

			} 
			
			else if (forkResult < 0) {
				//fork has failed
				printf("Fork has failed\n");
				continue;
			} else {
				//this is the parent
				//wait till the child has completed
				forkResult = wait(NULL);
			}
		}
	}
}
