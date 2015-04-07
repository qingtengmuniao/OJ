#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500 
#define _DEBUG 0 

typedef struct Edge{
	int x;
	int y;
	int dis;
} Edge;
Edge edge[(N*N)/2];
int father[N+1];
int max_dis = -1;

// mysort
void swap(Edge *v, int i, int j)
{
	Edge temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void mysort(Edge *v, int left, int right)
{
	int i, last = left;
	
	if (left >= right) return;

	swap(v, left, (left+right)/2);
	for (i = left+1; i <= right; ++i) {
		if (v[i].dis < v[left].dis) {
			swap(v, i, ++last);
		}
	}
	swap(v, last, left);

	mysort(v, left, last-1);
	mysort(v, last+1, right);
}

// read data of every test case, and init
int read_data(int n)
{
	int i, j, edge_pos = 0;
	int temp;
	for (i = 0; i < n; ++i) {
		father[i] = i;
		for (j = 0; j < n; ++j) {
			scanf("%d", &temp);
			if (j > i) {
				edge[edge_pos].x = i;	
				edge[edge_pos].y = j;	
				edge[edge_pos].dis = temp;	
				edge_pos++;
			} 
		}
	}
	father[i] = i;
	
	max_dis = -1;
	mysort(edge, 0, edge_pos-1);
#if _DEBUG
	for ( i = 0; i < edge_pos; ++i) {
		printf("(%d,%d)=%d\n", edge[i].x, edge[i].y, edge[i].dis);
	}
#endif
	return edge_pos;
}

// find the root of a, namely the set that a belongs to
int find_set(int a)     
{
	if(a != father[a]) {
		father[a] = find_set(father[a]);
	}
	return father[a];
}
// merge two sets
void Union(int x, int y, int w)   
{
	if(x == y)  return ;
	father[y] = x;
	if(w > max_dis) max_dis = w;
}
// solve use krushkal
void kruskal_solve(int n, int k)
{
	int i = 0;
	for(i = 0;i < k;i++)
	{
		int x = find_set(edge[i].x);
		int y = find_set(edge[i].y);
		Union(x, y, edge[i].dis);
	}
	printf("%d\n", max_dis);
}

int main()
{
	int T, n;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int k = read_data(n);
		kruskal_solve(n, k);
	}
}
