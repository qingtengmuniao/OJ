#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define M 10010
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct point{
	int h, x, y;
} Point;

int height[N][N];
Point sh[M];
int dp[N][N];

void swap(Point v[], int i, int j)
{
	Point temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void mysort(Point v[], int left, int right)
{
	if (left >= right) return;

	swap(v, left, (left+right)/2);

	int i, last = left;
	for (i = left+1; i <= right; ++i) {
		if (v[i].h > v[left].h) {
			swap(v, i, ++last);
		}	
	}

	swap(v, left, last);
	mysort(v, left, last-1);
	mysort(v, last+1, right);
}

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		int i, j, k = 0;

		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				dp[i][j] = 1;
				scanf("%d", &height[i][j]);
				sh[k].h = height[i][j];
				sh[k].x = i;
				sh[k].y = j;
				++k;
			}
		}

		int count = k;
		mysort(sh, 0, k-1);
		int max_h = 1;

		for (i = 0; i < count; ++i) {
			int temp = 1, x = sh[i].x, y = sh[i].y, h = sh[i].h;

			if (y - 1 >= 0 && height[x][y-1] > h) {
				temp = max(temp, dp[x][y-1]+1);
			}	
			if (y + 1 < n && height[x][y+1] > h) {
				temp = max(temp, dp[x][y+1]+1);
			}	
			if (x - 1 >= 0 && height[x-1][y] > h) {
				temp = max(temp, dp[x-1][y]+1);
			}	
			if (x + 1 < m && height[x+1][y] > h) {
				temp = max(temp, dp[x+1][y]+1);
			}	
			dp[x][y] = temp;
			max_h = max(temp, max_h);
		}

		printf("%d\n", max_h);
	}


	return 0;
}
