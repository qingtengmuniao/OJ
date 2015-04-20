#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p, q;
int flag = 0;
int chessboard[26][26];
char result[64];
int step[8][2] = {
	-2, -1,
	-2, 1,
	-1, -2,
	-1, 2,
	1, -2,
	1, 2,
	2, -1,
	2, 1
};
int can_move(int x, int y) 
{
	return (x >= 0 && x < q) && (y >= 0 && y < p) && (!chessboard[x][y]);
} 
/**
 * now we in the pos (x, y) and this is our nth step
 */
void dfs(int x, int y, int n)
{
	if (flag) return;
	int pos = 2 * (n - 1);
	result[pos] = 'A' + x;
	result[pos+1] = '1' + y;
	chessboard[x][y] = 1;

	if (n == p*q) {
		result[pos+2] = '\0';
		printf("%s\n\n", result);
		flag = 1;
		return;
	} 

	int i;
	for (i = 0; i < 8; ++i) {
		int new_x = x+step[i][0];
		int new_y = y+step[i][1];

		if (can_move(new_x, new_y)) {
			dfs(new_x, new_y, n+1);
		}
	}
	
	chessboard[x][y] = 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int i = 0, j, k;
	for (i = 0; i < n; ++i) {
		flag = 0;
		memset(chessboard, 0, sizeof(chessboard));
		memset(result, 0, sizeof(result));

		scanf("%d %d", &p, &q);
		printf("Scenario #%d:\n", i+1);
		for (j = 0; j < q; ++j) {
			for (k = 0; k < p; ++k) {
				if (flag) break;
				dfs(k, j, 1);
			}
			if (flag) break;
		}

		if (!flag) printf("impossible\n\n");
	}

	return 0;
}
