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
	//An array of strings to maintain history of the shell
	char ShellHistory[1024][512];
	int histptr=0;
	
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
		
		//Store the instruction in the shell's history
		strcpy( ShellHistory[histptr] , input );
		//printf("%s \n",ShellHistory[histptr]);
		histptr++;
		
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
					printf("cd: Error occured in getting the current working directory\n");
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
					
					char *newValForPrev=(char *)get_current_dir_name();
					
					if (chdir(new) != 0)	//some error in executing chdir(Change directory) command
					{
						printf("Some error in executing command cd\n");
						continue;
					}
					else
					{//no error in cd
						prevCD = (char *) newValForPrev;
					}
				}
				else
				{
					char *newValForPrev = (char *)get_current_dir_name();
					if (chdir(arg[1]) != 0)	//some error in executing chdir(Change directory) command
					{
						printf("Some error in executing command cd\n");
						continue;
					}
					else
					{//no error in cd
						prevCD = (char *) newValForPrev;
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
			if(strcmp(arg[1],"-n") == 0) //option is -n
			{	//Do not print the trailing newline character
				int i=2;
				while(arg[i] !='\0') {
					printf("%s ",arg[i]);
					i++;
				}
			}
			else if(strcmp(arg[1],"-e") ==0) //option is -e
			{
				//enable interpretation of backslash escapes
				int i = 2;
				int j=0;
				char *echowords[20];
				while(arg[i] != '\0')
				{
					char *ptr=strtok(arg[i], "\\");
					
					while(ptr!='\0')
					{
						echowords[j++]=ptr;
						ptr=strtok(NULL, "\\");
					}
					i++;
				}
				echowords[j] = '\0';
				j=0;
				while(echowords[j] != '\0')
				{
					char *word = echowords[j];
					if(*word == 'n') { //provide newline
						word++;
						printf("\n%s",word);
					}
					else if(*word == 't') { //provide tab
						word++;
						printf("\t%s",word);
					}
					else if(*word == 'c') { //produce no further output
						word++;
						break;
					}
					else
					{
						printf("%s",word);
					}
					j++;
				}printf("\n");
			}
			else
			{
				int i=1;
				while(arg[i] !='\0') {
					printf("%s ",arg[i]);
					i++;
				}printf("\n");
			}
		}
		//print the history of commands in shell
		else if(strcmp(command,history) ==0)
		{
			int i=0;
			for(i=0; i<histptr; i++)
			{
				printf(" %d  %s\n",i+1,ShellHistory[i]);
			}
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
						//Some error in execv
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"mkdir")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/mkdir";
					if (execv(path, arg) == -1) {
						//Some error in execv
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"cat")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/cat";
					if (execv(path, arg) == -1) {
						//Some error in execv
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"date")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/date";
					if (execv(path, arg) == -1) {
						//Some error in execv
						printf
						    ("Could not find command or some error in executing command %s\n",
						     command);
					}
				}
				else if(strcmp(command,"rm")==0) {
					char path[] = "/home/pragya/Desktop/shell/bin/rm";
					if (execv(path, arg) == -1) {
						//Some error in execv
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
				wait(NULL);
			}
		}
	}
}
