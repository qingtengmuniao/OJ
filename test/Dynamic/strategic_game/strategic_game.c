#include <stdio.h>
#include <stdlib.h>

#define N 1600
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[N][2];//make decision by placing a soldier or not
int edges[N][N];

void dfs(int pos) 
{
	dp[pos][0] = 0; 
	dp[pos][1] = 1; 

	int i;
	for (i = 1; i <= edges[pos][0]; ++i) {
		int now_pos = edges[pos][i];
		dfs(now_pos);
		dp[pos][0] += dp[now_pos][1]; // 0 means dont place a soldier in pos
		dp[pos][1] += min(dp[now_pos][1], dp[now_pos][0]);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int i, j, root;
		for (i = 0; i < n; ++i) {
			int pos, total;
			scanf("%d:(%d)", &pos, &total);
			if (i == 0) root = pos;
			edges[pos][0] = total;
			for (j = 1; j <= total; ++j) {
				scanf("%d", &edges[pos][j]);
			}
		}

		if (n < 1) {
			printf("0\n");
			continue;
		}
		dfs(root);
		printf("%d\n", min(dp[root][0], dp[root][1]));
	}

	return 0;
}

