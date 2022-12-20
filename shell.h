#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/*Prototypes*/
int _putchar(char c);
void _puts(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int parse_input(char *input, char *input_copy, char **argv);
int commandIsInternal(char **argv);
void execute_command(char **argv);
int handle_exit(char *command);
int handle_env(char *command);
void print_env(void);
char *generate_path(char *command);
#endif
