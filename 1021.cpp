#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct position{
	int x, y;
}pos[10010];

int w, h, n, map[105][105], sum[2][10010];

int compare(const void*a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %d", &w, &h, &n);
		memset(map, 0, sizeof map);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &pos[i].x, &pos[i].y);
			map[pos[i].x][pos[i].y] = 1;
		}
		for (int i = 1; i <= n; i++){
			int xx = pos[i].x, yy = pos[i].y, x, y, cnt = 0;
			for (x = xx, y = yy; map[x][y] && y < h; ++y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x < w; ++x, ++cnt);
			for (x = xx, y = yy; map[x][y] && y >= 0; --y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x >= 0; --x, ++cnt);
			sum[0][i] = cnt;
		}

		memset(map, 0, sizeof map);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &pos[i].x, &pos[i].y);
			map[pos[i].x][pos[i].y] = 1;
		}

		for (int i = 1; i <= n; i++){
			int xx = pos[i].x, yy = pos[i].y, x, y, cnt = 0;
			for (x = xx, y = yy; map[x][y] && y < h; ++y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x < w; ++x, ++cnt);
			for (x = xx, y = yy; map[x][y] && y >= 0; --y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x >= 0; --x, ++cnt);
			sum[1][i] = cnt;
		}

		qsort(sum[0] + 1, n, sizeof(int), compare);
		qsort(sum[1] + 1, n, sizeof(int), compare);

		int pd = 1;
		for (int i = 1; i <= n; i++) if (sum[0][i] != sum[1][i]) {
			pd = 0; break;
		}

		if (!pd) puts("NO");
		else puts("YES");
	}

	return 0;
}