#include "stdio.h"

int mat[11][11] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 0, 0, 5, 6, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 0, 7, 0, 9, 10, 0, 0 },
	{ 0, 0, 4, 5, 7, 0, 8, 0, 11, 12, 0 },
	{ 0, 0, 0, 6, 0, 8, 0, 0, 0, 13, 14 },
	{ 0, 0, 0, 0, 9, 0, 0, 0, 15, 0, 0 },
	{ 0, 0, 0, 0, 10, 11, 0, 15, 0, 16, 0 },
	{ 0, 0, 0, 0, 0, 12, 13, 0, 16, 0, 17 },
	{ 0, 0, 0, 0, 0, 0, 14, 0, 0, 17, 0 }
};

int tri[9] = { 7, 152, 52, 352, 34304, 3200, 71680, 12544, 155648 };
int STATUS = (1 << 18) - 1;
int Get_Status(int old, int seg, int &cnt)
{
	int now = old | seg;
	for (int i = 0; i<9; i++)
	{
		if ((old&tri[i]) != tri[i] && (now&tri[i]) == tri[i])
		{
			cnt++;
		}
	}
	return now;
}
int MaxSearch(int state, int alpha, int ca, int cb);
int MinSearch(int state, int beta, int ca, int cb){
	if (ca >= 5 || cb>=5) 
	{
		return ca-cb;
	}
	else
	{
		int ans = 1;
		int remain = (~state)&STATUS;
		while (remain)
		{
			int seg = remain&(-remain);
			int ta = ca, tb = cb;
			int now = Get_Status(state, seg, tb);
			int tmp;
			if (tb > cb)
			{
				tmp = MinSearch(now, beta, ca, tb);
			}
			else
			{
				tmp = MaxSearch(now, ans, ca, tb);
			}
			if (tmp < ans)
			{
				ans = tmp;
			}
			if (tmp <= beta)
			{
				return ans;
			}
			remain -= seg;
		}
		return ans;
	}
}
int MaxSearch(int state, int alpha, int ca, int cb){
	if (ca >= 5 || cb >= 5)
	{
		return ca - cb;
	}
	else
	{
		int ans = -1;
		int remain = (~state)&STATUS;
		while (remain)
		{
			int seg = remain&(-remain);
			int ta = ca, tb = cb;
			int now = Get_Status(state, seg, ta), tmp;
			if (ta > ca)
			{
				tmp = MaxSearch(now, alpha, ta, cb);
			}
			else
			{
				tmp = MinSearch(now, ans, ta, cb);
			}
			if (tmp > ans)
			{
				ans = tmp;
			}
			if (tmp >= alpha)
			{
				return ans;
			}
			remain -= seg;
		}
		return ans;
	}
}
int main(){
	int t;
	int cas = 0;
	scanf("%d", &t);
	while (t--){
		int n, u, v;
		scanf("%d", &n);
		int state = 0;
		bool turn = true;
		int ca = 0, cb = 0;
		while (n--)
		{
			scanf("%d %d", &u, &v);
			int ta = ca, tb = cb;
			state = Get_Status(state, 1 << mat[u][v], turn? ca : cb);
			if (ta == ca&&tb == cb)
			{
				turn = !turn;
			}
		}
		int ans;
		if (!turn) 
		{
			ans = MinSearch(state, -1, ca, cb);
		}
		else
		{
			ans = MaxSearch(state, 1, ca, cb);
		}
		printf("Game %d: %c wins.\n", ++cas, ans >0 ? 'A' : 'B');
	}
	return 0;
}