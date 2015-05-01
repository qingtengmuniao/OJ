#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define MAX_INT 0x7fffffff

int edges[N][N];
int dis[N];

void kruskal_solve(int n) 
{
	//printf("n=%d\n", n);
	int i, j, total_weight = 0;

	// select the first node:0 
	for (i = 0; i < n; ++i) {
		dis[i] = edges[0][i];
	}

	for (i = 1; i < n; ++i) {
		// select the min edge
		int min_edge = MAX_INT;
		int min_pos = -1;
		for (j = 0; j < n; ++j) {
			if (dis[j] && dis[j] < min_edge) {
				min_edge = dis[j];
				min_pos = j;
			}
		}
		
		//printf("select %d , weight = %d\n", min_pos, min_edge);
		total_weight += dis[min_pos];

		// update the dis
		for (j = 0; j < n; ++j) {
			if (dis[j] > edges[min_pos][j]) {
				dis[j] = edges[min_pos][j];
			}
		}
	}

	printf("%d\n", total_weight);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &edges[i][j]);
			}	
		}
		kruskal_solve(n);
	}

	return 0;
}
