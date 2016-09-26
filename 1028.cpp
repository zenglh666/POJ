#include "stdio.h"
#include "string.h"

#define max_url_len 71
#define max_command 100
#define max_stack_len 101
char stack[max_stack_len][max_url_len];
const char *visit = "VISIT";
const char *back = "BACK";
const char *forward = "FORWARD";
const char *quit = "QUIT";
const char *ignored = "Ignored";
const char *init_url = "http://www.acm.org/";

int main()
{
	char command[max_command];
	int id = 0;
	int size = 0;
	strcpy(stack[id], init_url);
	while (scanf("%s", command) && strcmp(command, quit))
	{
		if (!strcmp(command, visit))
		{
			++id;
			scanf("%s", stack[id]);
			printf("%s\n", stack[id]);
			size = id;
		}
		else if (!strcmp(command, back))
		{
			if (id > 0)
			{
				--id;
				printf("%s\n", stack[id]);
			}
			else
			{
				printf("%s\n", ignored);
			}
		}
		else if (!strcmp(command, forward))
		{
			if (id < size)
			{
				++id;
				printf("%s\n", stack[id]);
			}
			else
			{
				printf("%s\n", ignored);
			}
		}
	}
	return 0;
}

