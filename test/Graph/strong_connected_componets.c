#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 100

using namespace std;

int num = 0;
int points[N+1];
bool visited[N+1];
bool found[N+1];
vector<int> edges[N+1];
vector<int> back_edges[N+1];
int labels[N+1]; 

void explore(vector<int> es[], int v, bool p)
{
	visited[v] = true;
	if (p) printf("%d ", v);
	//printf("we expolre %d\n", v);
	for (int i = 0; i < es[v].size(); ++i) {
		if (!visited[es[v][i]]) {
			explore(es, es[v][i], p);
		}
	}
	//labels.insert(labels.begin(), num++);
	labels[v] = num++;
}

void dfs(vector<int> es[], int n) 
{
	int i, j;
	for (i = 1; i <= n; ++i) {
		visited[i] = false;
	}
	
	for (i = 1; i <= n; ++i) {
		if (!visited[i])
			explore(es, i, false);
	}
}

int find_max(int l[], int n) 
{
	int max = -1;	
	int max_pos = -1;	
	for (int i = n; i >= 1; --i) {
		if (!visited[i] && l[i] > max) {
			max = l[i];	
			max_pos = i;
		}	
	}
	return max_pos;
} 

void print_edges(vector<int> e[], int n)
{
	for (int i = 1; i <= n; ++i) {
		printf("%d->", i);
		for (int j = 0; j < e[i].size(); ++j) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n, e;
	while (scanf("%d %d", &n, &e) != EOF) {
		int i, j;
		for (i = 0; i < e; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			back_edges[y].push_back(x);
		}
		printf("edges:\n");
		print_edges(edges, n);
		printf("back_edges:\n");
		print_edges(back_edges, n);

		
		dfs(back_edges, n);
		printf("label\n");
		for(i = 1; i <= n; ++i) {
			printf("%d ", labels[i]);
		}
		printf("\n");

		for (i = 1; i <= n; ++i) {
			visited[i] = false;	
		}
		int sink_point;
		while ( (sink_point = find_max(labels, n)) != -1) {
			explore(edges, sink_point, true);
			printf("\n");
		}
	}

	return 0;
}
