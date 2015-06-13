#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 20001
using namespace std;

int visited[N];
int subtree_num[N];
int dp[N];

void dfs(const vector<vector<int> > &edges, int pos, int n)
{
	visited[pos] = 1;
	subtree_num[pos] = 0;
	dp[pos] = 0;

	int i, size = edges[pos].size();
	for (i = 0; i < size; ++i) {
		int now_pos = edges[pos][i];
		if (!visited[now_pos]) {
			dfs(edges, now_pos, n);

			if (subtree_num[now_pos]+1 > dp[pos]) {
				dp[pos] = subtree_num[now_pos]+1; 
			}
			subtree_num[pos] += (subtree_num[now_pos]+1);
		}
	}

	if (n - subtree_num[pos] - 1 > dp[pos]) {
		dp[pos] = n - subtree_num[pos] - 1;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<vector<int> > edges(n+1);
		int i, j;
		for (i = 1; i <= n-1; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			edges[y].push_back(x);
			visited[x] = visited[y] = 0;
		}

		dfs(edges, 1, n);
		edges.clear();

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
