#include <stdio.h>

#define N 2000 
#define SIZE 7 
#define _DEBUG 1
#define MAXINT 0x7FFFFFFF
#define min(x,y) (((x) > (y)) ? (y) : (x))

typedef int T;
char point[N][10];
int dis[N];
long total_dis = 0;

// basic opreation
T get_dis(char a[], char b[], int n)
{
	T total = 0;
	while(--n >= 0) {
		total += (a[n] != b[n]);
	}
	return total;
}

/*
 * read data and init the variable
 */
void read_data(int n)
{
	int i;
	for (i = 0; i < n; ++i) {
		scanf("%s", point[i]);
		dis[i] = MAXINT;
	}
	total_dis = 0;
}

/*
 * prim algrithm
 */
void prim_tree(int n)
{
	int i, j;

	// select the 1st point
	int now_point = 0;
	dis[now_point] = 0;

	// select the next n-1 points
	for (i = 1; i < n; ++i){
		// update the vector distance
		for (j = 0; j < n; ++j) {
			if (dis[j]) { 
				int j_now_dis = get_dis(point[j], point[now_point], SIZE);
#if _DEBUG
				printf("The distance of (%s, %s) is %d\n", point[i], point[now_point], j_now_dis);
#endif
				dis[j] = min(dis[j], j_now_dis);
			}
		}

		// select the min distance
		int min_dis = MAXINT;
		for (j = 0; j < n; ++j) {
			if (dis[j] && dis[j] < min_dis) {
				min_dis = dis[j];
				now_point = j;
			}
		}
#if _DEBUG
		printf("The min_dis is %d\n", min_dis);
#endif

		// add it BTW
		total_dis += min_dis;
		dis[now_point] = 0;
	}

	printf("The highest possible quality is 1/%d.\n", total_dis);
}

int main()
{
	int i, j, n;
	while (scanf("%d\n", &n) == 1  && n != 0) {
		read_data(n);
		prim_tree(n);
	}

	return 0;
}
