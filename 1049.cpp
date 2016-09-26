#include "stdio.h"
#include "ctype.h"

#define max_memory_len 256

char memory[max_memory_len];
inline char read(char a)
{
	if (isupper(a))
	{
		return a - 'A'+10;
	}
	else
	{
		return a - '0';
	}
}

inline void write(char a, char *add)
{
	if (a < 10)
	{
		*add = a + '0';
	}
	else
	{
		*add = a-10 + 'A';
	}
}

void process()
{
	char instruction, argument1, argument2;
	char pa, pb;
	pa = pb = 0;
	bool stop = false;
	int i = 0;
	while (i < max_memory_len)
	{
		instruction = read(memory[i++]);
		switch (instruction)
		{
		case 0:
		{
			argument1 = read(memory[i++]);
			argument2 = read(memory[i++]);
			pa = read(memory[argument1 * 16 + argument2]);
			break;
		}
		case 1:
		{
			argument1 = read(memory[i++]);
			argument2 = read(memory[i++]);
			write(pa,&memory[argument1 * 16 + argument2] );
			break;
		}
		case 2:
		{
			char buff = pa;
			pa = pb;
			pb = buff;
			break;
		}
		case 3:
		{
			char sum = pa + pb;
			pa = sum % 16;
			pb = sum / 16;
			break;
		}
		case 4:
		{
			pa = (pa + 1) % 16;
			break;
		}
		case 5:
		{
			pa = (pa + 15) % 16;
			break;
		}
		case 6:
		{
			argument1 = read(memory[i++]);
			argument2 = read(memory[i++]);
			if (pa == 0)
			{
				i = argument1 * 16 + argument2;
			}
			break;
		}
		case 7:
		{
			argument1 = read(memory[i++]);
			argument2 = read(memory[i++]);
			i = argument1 * 16 + argument2;
			break;
		}
		default:
		{
			stop = true;
			break;
		}
		}
		if (stop)
		{
			break;
		}
	}
}

int main()
{
	while (gets(memory))
	{
		if (memory[0] == '8')
		{
			break;
		}
		else
		{
			process();
			puts(memory);
		}
	}
	return 0;
}

