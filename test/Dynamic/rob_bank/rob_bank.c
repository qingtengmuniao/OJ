#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10001
#define N 101

int m[N];
double p[N];
double dp[M];


int solve(int n, int total_m, double total_p)
{
	int i, j;

	dp[0] = 1.0;
	// think about every bank one by one: rob or not
	for (i = 0; i < n; ++i) {
		for (j = total_m; j >= m[i]; --j) {
			if (dp[j] < dp[j-m[i]]*(1-p[i]))
				dp[j] = dp[j-m[i]]*(1-p[i]);
		}
	}
	for (i = total_m; i >= 0; i--) {
		if (1-dp[i] < total_p) 
			return i;
	}
	return 0;
}

int main()
{
	int t, n;
	double total_p;
	scanf("%d", &t);

	int i, j;
	while (t--) {
		int total_m = 0;
		scanf("%lf %d", &total_p, &n);
		for (i = 0; i < n; ++i) {
			scanf("%d %lf", &m[i], &p[i]);
			total_m += m[i];
		}

		memset(dp, 0, 8*(total_m+1));
		printf("%d\n", solve(n, total_m, total_p));
	}

	return 0;
}
