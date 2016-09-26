#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_grid 100
#define grid_num max_grid+1
#define die_num 1000
#define max_player 6


int die[die_num];
int connect[grid_num];
int step[grid_num];
bool trapped[max_player];
int player[max_player];


int main()
{
	int die_count=0;
	while (scanf("%d", &die[die_count]) && die[die_count] != 0)
	{
		++die_count;
	}
	int player_count;
	while (scanf("%d", &player_count) && player_count != 0)
	{
		int begin, end;
		memset(connect, 0, sizeof(connect));
		while (scanf("%d %d", &begin, &end) && (begin != 0 && end != 0))
		{
			connect[begin] = end;
		}
		int turn;
		memset(step, 0, sizeof(step));
		while (scanf("%d", &turn) && turn != 0)
		{
			if (turn > 0)
			{
				step[turn] = 1;
			}
			else
			{
				step[-turn] = -1;
			}
		}
		int player_ind = 0;
		memset(player, 0, sizeof(player));
		memset(trapped, false, sizeof(trapped));
		for (int i = 0; i < die_count; ++i)
		{
			if (trapped[player_ind])
			{
				trapped[player_ind] = false;
				player_ind = (player_ind + 1) % player_count;
				--i;
			}
			else
			{
				player[player_ind] += die[i];
				if (player[player_ind] == max_grid)
				{
					printf("%d\n", player_ind + 1);
					break;
				}
				else if (player[player_ind] > max_grid)
				{
					player[player_ind] -= die[i];
					player_ind = (player_ind + 1) % player_count;
				}
				else
				{
					while (connect[player[player_ind]] != 0)
					{
						player[player_ind] = connect[player[player_ind]];
					}
					if (step[player[player_ind]] == -1)
					{
						trapped[player_ind] = true;
						player_ind=(player_ind+1)%player_count;
					}
					else if (step[player[player_ind]] == 0)
					{
						player_ind = (player_ind + 1) % player_count;
					}
				}
			}
			
		}
	}
	return 0;
}

