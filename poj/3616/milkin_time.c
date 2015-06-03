#include <stdio.h>
#include <stdlib.h>

#define N 1005
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct segment{
	int start, end, weight;
} Seg;

Seg interval[N];
int dp[N];


void swap(Seg v[], int a, int b)
{
	Seg temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void mysort(Seg v[], int left, int right)
{
	if (left >= right) return;

	int i, last = left;
	swap(v, left, (left+right)/2);
	for (i = left+1; i <= right; ++i) {
		if (v[i].end < v[left].end) {
			swap(v, i, ++last);
		} else if (v[i].end == v[left].end) {
			if (v[i].start < v[left].start) 
				swap(v, i, ++last);
		}
	}
	swap(v, left, last);

	mysort(v, left, last-1);
	mysort(v, last+1, right);
}

int main()
{
	int n, m, r;
	while (~scanf("%d %d %d", &n, &m, &r)) {
		int i, j;

		for (i = 0; i < m; ++i) {
			scanf("%d %d %d", &interval[i].start, &interval[i].end, &interval[i].weight);
		}

		mysort(interval, 0, m-1);

		int result = 0;
		for (i = 0; i < m; ++i) dp[i] = interval[i].weight;
		for (i = 0; i < m; ++i) {
			for (j = 0; j < i; ++j) {
				if (interval[i].start - interval[j].end >= r) {
					dp[i] = max(dp[i], dp[j]+interval[i].weight);
				}
			}
			result = max(result, dp[i]);
		}

		printf("%d\n", result);
	}	
}
