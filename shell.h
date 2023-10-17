#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM "\t\r\n\a"

/* points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @agrs; tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data 
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;


/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next mode
 * description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - singlr linked lis 
 * @line: command line
 * @next: next node
 * description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: lenght of the varialbe
 * @val: value of the variable
 * len_vel: lenght of the value
 * @next: next mode
 * desvroption: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - builtin struct for commmand args.
 * @name: thename of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef srruct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t

/* aux_lists.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
lin_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
