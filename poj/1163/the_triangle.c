#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define max(a, b) ((a) > (b) ? (a) : (b))
int triangle[N][N];
int dp[N][N];

int sum(int pos, int level, int n)
{
	if (dp[level][pos]) return dp[level][pos];

	if (level == n-1) return dp[level][n-1] = triangle[level][pos];

	return dp[level][pos] = triangle[level][pos] + max(sum(pos, level+1, n), sum(pos+1, level+1, n));
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j <= i; ++j) {
				scanf("%d", &triangle[i][j]);
			}
		}

		memset(dp, 0, sizeof(dp));
		printf("%d\n", sum(0, 0, n));
	}

	return 0;
}
