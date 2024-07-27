# simple-shell
This is a simple shell program written in C. The shell allows users to execute basic commands like `pwd`, `echo`, `cp`, `mv`, and `exit`

Here's how it works:

1. The shell first prints a welcome message and explains the available commands.
2. Then, it enters an infinite loop where it repeatedly prompts the user for input.
3. When the user types a command, the shell checks if the command is one of the available ones.
4. For `pwd`, it simply prints the current working directory.
5. For `echo`, it takes additional input (a string) and prints it to the console.
6. For `cp` and `mv`, it takes two arguments (source path and target path), and calls the corresponding functions from `files_management.c`.
7. If the command is not recognized, it prompts the user if they want to exit or continue.

Note that this shell program does not handle errors properly. It simply prints an error message and continues without checking for errors. It just prints a flag and get back to the entry point. In a real-world implementation, you would need to add proper error handling and checks.

The `files_management.c` and `files_management.h` files provide functions for copying and moving files. The `cp` function opens the source file, reads it line by line, and writes each line to the target file. The `mv` function does a similar thing, but also renames the source file to the target path.

For you to generate the .exe u need to write this command "gcc -static uShell.c files_management.c -o uShell.exe"

The `uShell.c` file is 3m el kawkab's shell program.
