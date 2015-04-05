#include <stdio.h>

#define N 4
#define SIZE 7 
#define _DEBUG 1
#define MAXINT 0x7FFFFFFF

typedef int T;
typedef struct edge{
	int x;
	int y;
	int dis;
} Edge;

Edge edge[(N*N-N)/2];
char point[N][10];
int dis[N];
long total_dis = 0;

// qsort 
void swap(Edge *v, int a, int b)
{
	Edge temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void qsort(Edge *v, int left, int right)
{
	if (left >= right) return;

	swap(v, left, (left+right)/2);
	int i, last = 0;
	for (i = left+1; i <= right; ++i) 
		if (v[i].dis < v[left].dis)
			swap(v, i, ++last);
	swap(v, last, left);

	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

// basic opreation
T get_dis(char a[], char b[], int n)
{
	T total = 0;
	while(--n >= 0) {
		total += (a[n] == b[n] ? 0 : 1);
	}
	return total;
}

// read data and init the variable
void read_data(int n)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		scanf("%s", point[i]);
	}

	int k = 0;
	for (i = 0; i < n; ++i) {
		for (j = i+1; j < n; ++j) {
			++k;
			edge[k].x = i;
			edge[k].y = j;
			edge[k].dis = get_dis(point[i], point[j], SIZE);
#if _DEBUG
			printf("(%s, %s) = %d\n", point[i], point[j], edge[k].dis);
#endif
		}
	}

	qsort(edge, 0, n-1);

	for (i = 0; i < n; ++i) {
		dis[i] = MAXINT;
	}
}

void prim_tree()
{
		
}

int main()
{
	int i, j, n;
	while (scanf("%d\n", &n) == 1  && n) {
		read_data(n);
	}

	return 0;
}
