#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500 
#define _DEBUG 1 

typedef struct Edge{
	int x;
	int y;
	int dis;
} Edge;
Edge edge[(N*N - N)/2];
int previous[N];

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
void read_data(int n)
{
	int i, j, edge_pos = 0;
	int temp;
	memset(previous, -1, sizeof(previous));
	printf("%d\n", n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			temp = rand();
			if (j > i) {
				edge[edge_pos].x = i;	
				edge[edge_pos].y = j;	
				edge[edge_pos].dis = temp;	
				edge_pos++;
			} 
		}
	}
#if _DEBUG
	for ( i = 0; i < edge_pos; ++i) {
		printf("(%d,%d)=%d\n", edge[i].x, edge[i].y, edge[i].dis);
	}
#endif
	
	printf("edge_pos=%d\n", edge_pos);
	mysort(edge, 0, edge_pos-1);
#if _DEBUG
	for ( i = 0; i < edge_pos; ++i) {
		printf("(%4d,%4d)=%d\n", edge[i].x, edge[i].y, edge[i].dis);
	}
#endif
}

// judge if point i and j in one connected component
int in_one_component(int x, int y)
{
	int root_x, root_y;

	while (y != -1) {
		root_y = y;
		y = previous[y];	
		if (y == x) return 1; // x is the precedence of the y (x < y)
	}

	while (x != -1) {
		root_x = x;
		x = previous[x];	
	}
	return root_x == root_y;
}
// solve use krushkal
void kruskal_solve(int n)
{
	// select the first edge
	int now_edge = 0, i;
	previous[edge[now_edge].y] = edge[now_edge].x;

	// select the next n-1 edges
	for (i = 1; i < n-1; ++i) {
		++now_edge;
		int x = edge[now_edge].x;
		int y = edge[now_edge].y;

		// select one
		while (in_one_component(x, y)){
			++now_edge;	
			x = edge[now_edge].x;
			y = edge[now_edge].y;
		}
	}

	printf("%d\n", edge[now_edge].dis);
}

int main()
{
	int T, n;

	T = 1;
	while (T--) {
		n = 78;
		//printf("%d\n", n);
		read_data(n);
		//kruskal_solve(n);
	}
}
