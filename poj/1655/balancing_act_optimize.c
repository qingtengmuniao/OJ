#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20010
#define M 40020

int visited[N], subtree_num[N], head[N];
int edge[M], next[M];
int dp[N];
int loc;

void dfs(int pos, int n)
{
	visited[pos] = 1;
	subtree_num[pos] = 0;
	dp[pos] = 0;

	int i;
	for (i = head[pos]; i; i = next[i]) {
		int now_pos = edge[i];
		if (!visited[now_pos]) {
			dfs(now_pos, n);

			if (subtree_num[now_pos] + 1 > dp[pos]) {
				dp[pos] = subtree_num[now_pos] + 1; 
			}
			subtree_num[pos] += (subtree_num[now_pos] + 1);
		}
	}

	if (n - subtree_num[pos] - 1 > dp[pos]) {
		dp[pos] = n - subtree_num[pos] - 1;
	}
}

void add_edge(int u, int v) 
{
	edge[loc] = v; next[loc] = head[u]; head[u] = loc++;
	edge[loc] = u; next[loc] = head[v]; head[v] = loc++; 
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		// init 
		loc = 1;
		memset(head, 0, sizeof(head));

		int i, j;
		for (i = 1; i <= n-1; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			add_edge(x, y);
			visited[x] = visited[y] = 0;
		}

		dfs(1, n);

		int min_balance = n, min_pos = 0;
		for (i = 1; i <= n; ++i) {
			//printf("dp[%d]=%d ", i, dp[i]);
			//printf("subtree_num[%d]=%d\n", i, subtree_num[i]);
			if (dp[i] < min_balance) {
				min_balance = dp[i];
				min_pos = i;
			}	
		}

		printf("%d %d\n", min_pos, min_balance);
	}


	return 0;
}
