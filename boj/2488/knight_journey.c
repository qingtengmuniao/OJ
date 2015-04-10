#include <stdio.h>

int p, q;
int chessboard[26][26];
char result[64];
int step[8][2] = {
	-1, 2,
	-2, 1,
	-2, -1,
	-1, -2,
	1, -2,
	2, -1,
	2, 1,
	1, 2
};

int can_move(int x, int y) 
{
	return (x >= 0 && x < p) && (y >= 0 && y < q) && (!chessboard[x][y]);
} 
/**
 * now we in the pos (x, y) and this is our nth step
 */
int dfs(int x, int y, int n)
{
	int pos = 2 * (n - 1);
	result[pos] = 'A' + y;
	result[pos+1] = x + 1;
	chessboard[x][y] = 1;

	if (n == p*q) {
		result[pos+2] = '\0';
		printf("%s\n\n", result);
		return 1;
	} 

	int i;
	for (i = 0; i < 8; ++i) {
		int new_x = x+step[i][0];
		int new_y = y+step[i][1];

		if (can_place(new_x, new_y)) {
			dfs(new_x, new_y, n+1);
		}
	}
	
	chessboard[x][y] = 0;
}

int main()
{
	int n;
	init();
	while (scanf("%d", &n) != EOF) {
		int i = 0;
		for (i = 0; i < n; ++i) {
			memset(chessboard, 0, sizeof(chessboard));
			memset(result, 0, sizeof(result));
			scanf("%d %d", &p, &q);
			printf("Scenario #%d:\n", i+1);
			dfs(0, 0, 1);
		}
	}
}
