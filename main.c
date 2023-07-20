#include "shell.h"

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];
    int arg_count = 0;

    while (1) {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Check if the user wants to exit
        if (strcmp(command, "exit") == 0) {
            break;
        }


        // Tokenize the command to get arguments
        char* token = strtok(command, " ");
        arg_count = 0;

        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }

        // Set the last element of the args array to NULL as required by execvp
        args[arg_count] = NULL;

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp error"); // If execvp fails, it returns -1 and prints an error
            exit(1);
        } else if (pid > 0) {
            // Parent process
            int status;
            wait(&status);
        } else {
            // Fork failed
            perror("fork failed");
            exit(1);
        }
    }

    return 0;
}
