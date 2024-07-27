#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "files_management.h"

char *PWD()
{
	char cwd[MAX_LINE];
	getcwd(cwd, sizeof(cwd));
	return strdup(cwd);
}

void shell_exit()
{
	printf("Exiting...\n");
	exit(0);
}

int main(int argc, char** argv)
{
	printf("Hi bud, this is a \033[1muShell\033[0m.\nHere's a simple guide for commands it can execute:\n");
	printf("\t\033[1;3;4mpwd\033[0m: prints the current working directory.\n");
	printf("\t\033[1;3;4mecho\033[0m: prints a string you type.\n");
	printf("\t\033[1;3;4mcp\033[0m: copies a file from source path to target path.\n");
	printf("\t\033[1;3;4mmv\033[0m: moves a file from source path to target path.\n");		
	printf("\t\033[1;3;4mexit\033[0m: closes the uShell session.\n");
	char command_line[MAX_LINE];
	ssize_t read_size = 0;
	char *current_pwd = PWD();
	while (1)
	{
		char *shell_msg = malloc(1024);
		strcpy(shell_msg, "3m el kawkab@");
		strcat(shell_msg, current_pwd);
		strcat(shell_msg, "  laghiny $ ");
		write(STDOUT, shell_msg, strlen(shell_msg));
		read_size = read(STDIN, command_line, MAX_LINE);
		char *token = strtok(command_line, " \n");
		while (token != NULL)
		{
			if (strcmp(token, "pwd") == 0)
			{
				printf("%s\n", current_pwd);
				break;
			}
			else if (strcmp((char*) "echo", (char*) token) == 0)
			{
        			while ((token = strtok(NULL, " \n")) != NULL)
				{
					write(STDOUT, token, strlen(token));
					write(STDOUT, "\n", 1);
				}
			}
			else if (strcmp(token, "cp") == 0)
			{
				char *source_path = strtok(NULL, " \n");
				char *target_path = strtok(NULL, " \n");
				cp(source_path, target_path);
				break;
			}
			else if (strcmp(token, "mv") == 0)
			{
				char *source_path = strtok(NULL, " \n");
				char *target_path = strtok(NULL, " \n");
				mv(source_path, target_path);
				break;
			}
			else if  (strcmp(token, "exit") == 0)
			{
				printf("Are you sure you want to exit? (y/n)\n");
				char confirm;
				scanf("%c", &confirm);
				if (confirm == 'y')
					{shell_exit();}
				else if (confirm == 'n')
					{break;}
				else
				{
					printf("unrecognized option\n");
					break;
				}
			}
		}
		free(shell_msg);
	}
	return 0;
}
