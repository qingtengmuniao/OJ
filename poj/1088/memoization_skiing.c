#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define M 10010
#define max(a, b) ((a) > (b) ? (a) : (b))


int height[N][N];
int dp[N][N];
int m, n;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


int get_dis(int x, int y)
{
	if (dp[x][y]) return dp[x][y];

	int i, nx, ny, around_h = 0;
	for (i = 0; i < 4; ++i) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= m | nx < 0 | ny >= n | ny < 0 | height[nx][ny] >= height[x][y]) continue;
		
		around_h = max(around_h, get_dis(nx, ny));
	}

	return dp[x][y] = around_h + 1;
}

int main()
{
	while (scanf("%d %d", &m, &n) != EOF) {
		int i, j, k = 0;

		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &height[i][j]);
				dp[i][j] = 0;
			}
		}

		int max_d = 1;
		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				max_d = max(max_d, get_dis(i, j)); 	
			}
		}

		printf("%d\n", max_d);
	}


	return 0;
}
