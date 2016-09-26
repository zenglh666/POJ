#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define max_name_length 64

typedef struct node
{
	char name[max_name_length];
	node* next;
}node;

node *insert(node *head, char *name)
{
	if (head == NULL)
	{
		head = (node *)malloc(sizeof(node));
		strcpy(head->name, name);
		head->next = NULL;
	}
	else
	{
		node *now = head;
		node *before = NULL;
		while (now!=NULL && strcmp(now->name, name) < 0)
		{
			before = now;
			now = now->next;
		}
		if (before == NULL)
		{
			now = head;
			head = (node *)malloc(sizeof(node));
			strcpy(head->name, name);
			head->next = now;
		}
		else
		{
			node *newnode = (node *)malloc(sizeof(node));
			before->next = newnode;
			newnode->next = now;
			strcpy(newnode->name, name);
		}
	}
	return head;
}

node *releasenode(node *head)
{
	node *now = head;
	node *before = head;
	while (now != NULL)
	{
		now = now->next;
		free(before);
		before = now;
	}
	return NULL;
}
bool mapping(int iter,int depth)
{
	char name[max_name_length];
	node *head = NULL;
	while (scanf("%s",name)==1)
	{
		if (name[0] == '#')
		{
			return true;
		}
		else
		{
			if (depth == 0 && head==NULL)
			{
				printf("DATA SET %d:\nROOT\n", iter);
			}
			if (name[0] == '*' || name[0]==']')
			{
				node *now = head;
				while (now != NULL)
				{
					for (int i = 0; i < depth; ++i)
					{
						printf("|     ");
					}
					printf("%s\n", now->name);
					now = now->next;
				}
				if (depth == 0)
				{
					putchar('\n');
				}
				head=releasenode(head);
				return false;
			}
			else
			{
				if (name[0] == 'f')
				{
					head=insert(head, name);
				}
				else if (name[0] == 'd')
				{
					for (int i = 0; i < depth+1; ++i)
					{
						printf("|     ");
					}
					printf("%s\n", name);
					mapping(iter,depth + 1);
				}
			}
		}
	}
}


int main()
{
	bool ret = false;
	int count = 1;
	while (!ret)
	{
		ret=mapping(count,0);
		++count;
	}
	return 0;
}

