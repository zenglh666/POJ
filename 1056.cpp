#include "stdio.h"
#include "string.h"

#define max_nodes 1025
#define code_length 10

struct node
{
	bool end, pass;
}nodes[max_nodes];

bool insert(char *codes, int ind)
{
	if (nodes[ind].end)
	{
		return true;
	}
	else
	{
		if (*codes != 0)
		{
			nodes[ind].pass = true;
			ind = ind * 2 + *codes - '0';
			codes++;
			return insert(codes, ind);
		}
		else
		{
			nodes[ind].end = true;
			return nodes[ind].pass;
		}
	}
}

int main()
{
	char codes[code_length];
	bool flag = true;
	int n = 1;
	memset(nodes, false, sizeof(nodes));
	while (scanf("%s", codes) == 1)
	{
		if (codes[0] == '9')
		{
			if (flag)
			{
				printf("Set %d is immediately decodable\n", n);
			}
			else
			{
				printf("Set %d is not immediately decodable\n", n);
			}
			++n;
			flag = true;
			memset(nodes, false, sizeof(nodes));
		}
		else
		{
			if (flag && insert(codes, 1))
			{
				flag = false;
			}
		}
	}
	return 0;
}

