#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "files_management.h"

extern int main(int argc, char *argv[]);

char *get_file_name(char *path)
{
	char *last_slash = strrchr(path, '/');
	if (last_slash == NULL)
		{return path;}		
	last_slash++;
	char *file_name = malloc(strlen(last_slash) + 1);
	strcpy(file_name, last_slash);
	return file_name;
}

int cp(char *source_path, char *target_path)
{
	if (strcmp(source_path, target_path) == 0)
 	{
 		printf("Source and target paths are the same.\n");
		return -1;
        }
        FILE *source_file = fopen(source_path, "r");
	if (source_file == NULL)
	{
		printf("Error: cannot open source file %s\n", source_path);
		return -1;
	}
	FILE *target_file;
	if (access(target_path, F_OK) != -1)
	{
		printf("Target file %s already exists\n", target_path);
		return 1;
	}
	target_file = fopen(target_path, "w");
	char buffer[MAX_LINE];
	while (fgets(buffer, MAX_LINE, source_file) != NULL)
	{
		fwrite(buffer, strlen(buffer), 1, target_file); 
		break;
	}
	fclose(source_file);
	fclose(target_file);
	return 0;
}

int mv(char *source_path, char *target_path)
{
	if (strcmp(source_path, target_path) == 0)
	{
		printf("Source and target paths are the same.\n");
		return -1;
	}
        FILE *source_file = fopen(source_path, "r");
	if (source_file == NULL)
	{
		printf("Error: cannot open source file %s\n", source_path);
		return -1;
	}
	if (access(target_path, F_OK) != -1)
	{
		printf("Target file already exists.\n");
		return -1;
	}
	FILE *target_file;
	target_file = fopen(target_path, "w");
	char buffer[MAX_LINE];
	while (fgets(buffer, MAX_LINE, source_file) != NULL)
	{
		fwrite(buffer, strlen(buffer), 1, target_file); 
		break;
	}
	if (rename(source_path, target_path) != 0)
	{
		printf("Error: cannot rename file %s to %s\n", source_path, target_path);
        	fclose(source_file);
        	return -1;
	}
	printf("File moved successfully.\n");
	fclose(source_file);	
	return 0;
}
