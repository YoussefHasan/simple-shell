#ifndef FILES_MANAGEMENT_H
#define FILES_MANAGEMENT_H

#define STDIN          0
#define STDOUT         1
#define STDERR         2
#define MAX_LINE       1024

extern int main( int argc, char *argv[] );
char *get_file_name(char *path);
int cp(char *source_path, char *target_path);
int mv(char *source_path, char *target_path);


#endif
